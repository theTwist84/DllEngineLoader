#pragma once

class IMapVariant
{
public:
	// IVariantAccessorBase
	virtual void     Free()                                              = 0;
	virtual wchar_t *GetName()                                           = 0;
	virtual wchar_t *GetDescription()                                    = 0;
	virtual wchar_t *SetName(LPCWSTR pName)                              = 0;
	virtual wchar_t *SetDescription(LPCWSTR pDescription)                = 0;
	virtual void     Function5()                                         = 0;
	virtual void     Function6()                                         = 0;
	virtual void     Function7()                                         = 0;
	virtual bool     CreateFileFromBuffer(LPVOID pBuffer, size_t *pSize) = 0;

	virtual INT32    GetID()                                             = 0;
	virtual bool     Function10()                                        = 0;
	virtual bool     Function11()                                        = 0;

	LPVOID GetData();
	size_t GetDataSize();

private:
	char m_data[0x14CD8];
};

LPVOID IMapVariant::GetData()
{
	return &m_data;
}

size_t IMapVariant::GetDataSize()
{
	return sizeof(m_data);
}