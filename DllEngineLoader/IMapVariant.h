#pragma once

class IMapVariant : public IVariantAccessorBase
{
public:
	virtual INT32 GetID()      = 0;
	virtual bool  Function10() = 0;
	virtual bool  Function11() = 0;

	void          CopyTo(LPVOID);

private:
	char          m_data[0x14CD8];
};

void IMapVariant::CopyTo(LPVOID outData)
{
	memcpy(outData, m_data, sizeof(m_data));
}