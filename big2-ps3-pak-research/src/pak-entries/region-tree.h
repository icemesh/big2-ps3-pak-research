/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

struct Region //0x30
{
	const char* m_name;				///< <c>0x00</c>: region name
	uint32_t	m_regionId;			///< <c>0x04</c>: StringId of the region name
	uint32_t	m_unk;				///< <c>0x08</c>: always 0 ?
	void*		m_unkPtr;			///< <c>0x0C</c>: 
	uint32_t	m_unk2;				///< <c>0x10</c>: always 0 ?
	uint32_t	m_unk3;				///< <c>0x14</c>: always 0 ?
	void*		m_pQuadList;		///< <c>0x18</c>: ptr to the QuadList
	uint32_t	m_unk4;				///< <c>0x1C</c>: this feels like two uint16_t fields...
	uint32_t	m_unk5;				///< <c>0x20</c>: always 0 ?
	void*		m_unkPtr2;			///< <c>0x24</c>: 
	uint32_t	m_unk6;				///< <c>0x28</c>: always 0 ?
	uint32_t	m_unk7;				///< <c>0x2C</c>: always 0 ?
};

struct RegionTree
{
	void* m_unkData;///< <c>0x00</c>:
	Region* m_aRegion[0];///< <c>0x04</c>: contiguos array of pointer to Region
	void Login();
};