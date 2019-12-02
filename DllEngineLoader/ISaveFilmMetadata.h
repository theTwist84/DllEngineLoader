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

	void             CopyTo(LPVOID);

private:
	char             m_data[0x1F7B0];
};

void ISaveFilmMetadata::CopyTo(LPVOID outData)
{
	memcpy(outData, m_data, sizeof(m_data));
}