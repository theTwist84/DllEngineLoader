#pragma once

class IGameEngine
{
public:
	virtual int    InitGraphics(struct ID3D11Device *, struct ID3D11DeviceContext *, struct IDXGISwapChain *, struct IDXGISwapChain *) = 0;
	virtual HANDLE InitThread(class IGameEngineHost *, class IGameContext *)                                                       = 0;
	virtual int    UpdateEngineState(int, LPVOID unknown = nullptr)                                                                = 0;
	virtual int    Free()                                                                                                          = 0;
	virtual void   Function4()                                                                                                     = 0;
	virtual void   Function5()                                                                                                     = 0;
	virtual void   Function6()                                                                                                     = 0;
	virtual void   Function7()                                                                                                     = 0;
	virtual void   Function8()                                                                                                     = 0;
	virtual int    Function9(LPVOID unknown)                                                                                       = 0;
	virtual void   Function10()                                                                                                    = 0;

private:
	static  char   s_data[0x460];
};
