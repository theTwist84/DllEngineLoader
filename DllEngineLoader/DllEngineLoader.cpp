#include <windows.h>
#include <cstdio>
#include <iostream>
#include <stdio.h>

#include "c_file.h"
#include "c_engine.h"

auto pathf = [](LPCSTR fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	static char path[MAX_PATH];
	int result = vsnprintf_s(path, MAX_PATH, _TRUNCATE, fmt, args);
	va_end(args);

	return path;
};

int main()
{
	char basePath[MAX_PATH] = "C:\\Games\\Testing\\Halo The Master Chief Collection Flighting";
	char engineName[MAX_PATH] = "HaloReach";

	auto engine_interface = c_engine_interface(pathf("%s\\%s\\%s.dll", basePath, engineName, engineName));
	auto pEngineData = engine_interface.GetEngineData();


	char *game_variant = nullptr;
	char *map_variant = nullptr;

	{
		size_t variantSize = -1;
		auto variant = c_file(pathf("%s\\%s\\game_variants\\%s.bin", basePath, engineName, "slayer_classic_054"));
		if (variant.FileOpen())
		{
			char *pBuffer = variant.GetBuffer(variantSize);
			game_variant = pEngineData->GameVariantCreateFromFile(pBuffer, variantSize) + sizeof(LPVOID); // skip virtual table

			variant.FileClose();
		}
	}
	{
		size_t variantSize = -1;
		auto variant = c_file(pathf("%s\\%s\\map_variants\\%s.mvar", basePath, engineName, "beaver_creek_cl_031"));
		if (variant.FileOpen())
		{
			char *pBuffer = variant.GetBuffer(variantSize);
			map_variant = pEngineData->MapVariantCreateFromFile(pBuffer, variantSize) + sizeof(LPVOID); // skip virtual table

			variant.FileClose();
		}
	}

	if (game_variant)
	{
		printf("%S, %S\n\n", (wchar_t *)&game_variant[0x8C], (wchar_t *)&game_variant[0x18C]); // print name and description
	}
	if (map_variant)
	{
		printf("%S, %S\n\n", (wchar_t *)&map_variant[0x80], (wchar_t *)&map_variant[0x180]); // print name and description
	}

	auto pEngine = engine_interface.GetEngine();

	Sleep(-1); // set a breakpoint here
}
