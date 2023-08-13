/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

namespace Visibility
{
	struct Vec3
	{
		float m_x;
		float m_y;
		float m_z;
	};

	struct VisPoint
	{
		Vec3 m_vec;
	};

	struct VisSide //0x8
	{
		uint32_t	m_numPoints;		///< <c>0x00</c>: number of points always 0x4 ?
		VisPoint*	m_pVisPoint;		///< <c>0x04</c>: array of ptrs
	};

	struct VisCell //0x30
	{
		uint32_t	m_unkNum;					///< <c>0x00</c>: always 0x6
		void*		m_unkPtr;					///< <c>0x04</c>: bkp hit @ 0x136E38
		void*		m_unkPtr2;					///< <c>0x08</c>: bkp never got hit
		uint8_t		m_unkarray[0x18];			///< <c>0x04</c>: array of floats used @ 0x136AF4
		uint32_t	m_numSides;					///< <c>0x24</c>: number of sides //always 0x6
		VisSide*	m_pVisSide;					///< <c>0x28</c>: ptr to the side
		uint32_t	m_pad;						///< <c>0x2C</c>: 
	};

	struct VisInfo
	{
		uint32_t	m_versionNumber;			///< <c>0x00</c>: usually  0x7
		int32_t		m_numVisRegions;			///< <c>0x04</c>: number of visibility regions
		VisCell*	m_pVisTable;				///< <c>0x08</c>: ptr to the visibility table
		uint32_t	m_unk;						///< <c>0x0C</c>: 
	};

	void DumpInfo(uint8_t* pMem);
}

