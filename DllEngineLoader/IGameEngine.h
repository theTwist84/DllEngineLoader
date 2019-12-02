#pragma once

enum class EngineState
{
	ePause,
	eUnpause,
	eEndGameWriteStats,
	eRevertToLastSave,
	eRestartLevel,
	eReloadSettings,
	eGameLoadStart,
	eGameLoadEnd,
	eUnknown8,
	eUnknown9,
	eSaveGameVariant,
	eSaveMapVariant,
	eEndRound,
	eEndGame,
	eReloadRenderer,
	eUnknown15,
	eUnknown16, // this takes some extra argument

	kCount
};

class IGameEngine
{
public:
	virtual int    InitGraphics(ID3D11Device *, ID3D11DeviceContext *, IDXGISwapChain *, IDXGISwapChain *) = 0;
	virtual HANDLE InitThread(class IGameEngineHost *, class IGameContext *)                               = 0;
	virtual int    UpdateEngineState(EngineState, LPVOID unknown = nullptr)                                = 0;
	virtual int    Free()                                                                                  = 0;
	virtual void   Function4()                                                                             = 0;
	virtual void   Function5()                                                                             = 0;
	virtual void   Function6()                                                                             = 0;
	virtual void   Function7()                                                                             = 0;
	virtual void   Function8()                                                                             = 0;
	virtual int    Function9(LPVOID unknown)                                                               = 0;
	virtual void   Function10()                                                                            = 0;

	HANDLE Initialize(class IGameRasterizer &rGameRasterizer, class IGameEngineHost &rGameEngineHost, class IGameContext &rGameContext)
	{
		InitGraphics(rGameRasterizer.GetDevice(), rGameRasterizer.GetContext(), rGameRasterizer.GetSwapChain(), 0);
		return InitThread(&rGameEngineHost, &rGameContext);
	}
private:
	static  char   s_data[0x460];
};
