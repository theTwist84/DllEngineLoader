#pragma once

class IVariantAccessorBase
{
public:
	virtual void     Free()                                 = 0;
	virtual wchar_t *GetName()                              = 0;
	virtual wchar_t *GetDescription()                       = 0;
	virtual wchar_t *SetName(LPCWSTR)                       = 0;
	virtual wchar_t *SetDescription(LPCWSTR)                = 0;
	virtual void     Function5()                            = 0;
	virtual void     Function6()                            = 0;
	virtual void     Function7()                            = 0;
	virtual bool     CreateFileFromBuffer(LPVOID, size_t *) = 0;
};