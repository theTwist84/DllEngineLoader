#pragma once

enum class EngineState : INT32
{
	ePause,
	eUnpause,
	eEndGameWriteStats,
	eRevertToLastSave,
	eRestartLevel,
	eReloadSettings,
	eStartLoading,
	eEndLoading,
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

LPCSTR EngineStateFromID(EngineState id)
{
	switch (id)
	{
	case EngineState::ePause:
		return "Pause";
	case EngineState::eUnpause:
		return "Unpause";
	case EngineState::eEndGameWriteStats:
		return "EndGameWriteStats";
	case EngineState::eRevertToLastSave:
		return "RevertToLastSave";
	case EngineState::eRestartLevel:
		return "RestartLevel";
	case EngineState::eReloadSettings:
		return "ReloadSettings";
	case EngineState::eStartLoading:
		return "StartLoading";
	case EngineState::eEndLoading:
		return "EndLoading";
	case EngineState::eUnknown8:
		return "Unknown8";
	case EngineState::eUnknown9:
		return "Unknown9";
	case EngineState::eSaveGameVariant:
		return "SaveGameVariant";
	case EngineState::eSaveMapVariant:
		return "SaveMapVariant";
	case EngineState::eEndRound:
		return "EndRound";
	case EngineState::eEndGame:
		return "EndGame";
	case EngineState::eReloadRenderer:
		return "ReloadRenderer";
	case EngineState::eUnknown15:
		return "Unknown15";
	case EngineState::eUnknown16:
		return "Unknown16";
	}
	return nullptr;
}

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

private:
	static  char   s_data[0x460];
};
