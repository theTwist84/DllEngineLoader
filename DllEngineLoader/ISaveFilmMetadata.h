#pragma once

class ISaveFilmMetadata
{
public:
	virtual void     Free()           = 0;
	virtual INT32    Function1()      = 0;
	virtual UINT32   Function2()      = 0;
	virtual INT32    GetID()          = 0;
	virtual INT64    GetAuthorXuid()  = 0;
	virtual wchar_t *GetName()        = 0;
	virtual wchar_t *GetDescription() = 0;

	LPVOID           GetData();
	size_t           GetDataSize();

private:
	char m_data[0x1F7B0];
};

LPVOID ISaveFilmMetadata::GetData()
{
	return &m_data;
}

size_t ISaveFilmMetadata::GetDataSize()
{
	return sizeof(m_data);
}