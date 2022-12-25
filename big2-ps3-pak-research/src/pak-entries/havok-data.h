/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

namespace Havok
{
	static const int MAX_BACKGROUNDS = 0x1F;

	//COLLISION_DATA_HAVOK_BG
	struct CollisionDataHavokBg //at lest 0x21
	{
		int32_t		m_numBackgrounds;			///< <c>0x00</c>: number of collision
		uint32_t	m_unk;						///< <c>0x04</c>: 
		uint32_t	m_unk2;						///< <c>0x08</c>: 
		uint32_t	m_unk3;						///< <c>0x0C</c>: 
		int32_t		m_unk4;						///< <c>0x10</c>: 
	};

	void HavokLoginLevel(uint8_t* pData);
}
