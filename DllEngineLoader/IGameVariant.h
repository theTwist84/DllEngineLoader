#pragma once

class IGameVariant
{
public:
	// IVariantAccessorBase
	virtual void          Free()                                              = 0;
	virtual wchar_t *     GetName()                                           = 0;
	virtual wchar_t *     GetDescription()                                    = 0;
	virtual wchar_t *     SetName(LPCWSTR pName)                              = 0;
	virtual wchar_t *     SetDescription(LPCWSTR pDescription)                = 0;
	virtual void          Function5()                                         = 0;
	virtual void          Function6()                                         = 0;
	virtual void          Function7()                                         = 0;
	virtual bool          CreateFileFromBuffer(LPVOID pBuffer, size_t *pSize) = 0;

	virtual bool          Function9()                                         = 0;
	virtual INT32         GetID()                                             = 0;
	virtual bool          Function11()                                        = 0;
	virtual UINT8         Function12()                                        = 0;
	virtual UINT32        Function13()                                        = 0;
	virtual IGameVariant *Reset()                                             = 0;
	virtual INT32         Function15(LPVOID, LPVOID)                          = 0;
	virtual UINT32        Function16(LPVOID, LPVOID)                          = 0;
	virtual bool          Function17(LPVOID, LPVOID)                          = 0;
	virtual bool          Function18(LPVOID, LPVOID)                          = 0;
	virtual bool          Function19(LPVOID, LPVOID)                          = 0;
	virtual INT32         Function20()                                        = 0;
	virtual bool          Function21(INT32)                                   = 0;

	LPVOID                GetData();
	size_t                GetDataSize();

private:
	char m_data[0x15230];
};

LPVOID IGameVariant::GetData()
{
	return &m_data;
}

size_t IGameVariant::GetDataSize()
{
	return sizeof(m_data);
}