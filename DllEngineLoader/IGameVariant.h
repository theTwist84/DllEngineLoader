#pragma once

class IGameVariant : public IVariantAccessorBase
{
public:
	virtual bool          Function9()                = 0;
	virtual INT32         GetID()                    = 0;
	virtual bool          Function11()               = 0;
	virtual UINT8         Function12()               = 0;
	virtual UINT32        Function13()               = 0;
	virtual IGameVariant *Reset()                    = 0;
	virtual INT32         Function15(LPVOID, LPVOID) = 0;
	virtual UINT32        Function16(LPVOID, LPVOID) = 0;
	virtual bool          Function17(LPVOID, LPVOID) = 0;
	virtual bool          Function18(LPVOID, LPVOID) = 0;
	virtual bool          Function19(LPVOID, LPVOID) = 0;
	virtual INT32         Function20()               = 0;
	virtual bool          Function21(INT32)          = 0;

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