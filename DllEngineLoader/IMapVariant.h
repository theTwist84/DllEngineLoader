#pragma once

class IMapVariant : public IVariantAccessorBase
{
public:
	virtual INT32 GetID()      = 0;
	virtual bool  Function10() = 0;
	virtual bool  Function11() = 0;

	LPVOID        GetData();
	size_t        GetDataSize();

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