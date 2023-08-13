/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

namespace Havok
{
	static const int MAX_BACKGROUNDS = 0x20;

	struct hkpMeshMaterial
	{
		std::uint32_t m_filterInfo;
	};

	namespace hkpExtendedMeshShape
	{
		struct Subpart //0x10
		{
			std::uint8_t	m_type;							///< <c>0x00</c>:
			std::uint8_t	m_materialIndexStridingType;	///< <c>0x01</c>: A type defining whether 8 or 16 bits are used to index material.
			std::uint16_t	m_materialStriding;				///< <c>0x02</c>: The byte offset between two hkMeshMaterials
			const void*		m_materialIndexBase;			///< <c>0x04</c>: a pointer, pointing to a strided array of material index (hkUint8), one index for each triangle.
			std::uint16_t	m_materialIndexStriding;		///< <c>0x08</c>: The byte offset between two material indices
			std::uint16_t	m_numMaterials;					///< <c>0x0A</c>: The number of materials, only used for debug checking
			const void*		m_materialBase;					///< <c>0x0C</c>: The base for the material table, the byte offset between two hkMeshMaterials is defined by m_materialStriding
		};

		struct TrianglesSubpart : Subpart //0x40 
		{
			int				m_numTriangleShapes;		///< <c>0x10</c>:
			const float*	m_vertexBase;				///< <c>0x14</c>: A pointer to the first vertex, defined by three floats.
			int				m_vertexStriding;			///< <c>0x18</c>: The byte offset between two consecutive vertices (usually 12, 16 or more).
			int				m_numVertices;				///< <c>0x1C</c>: The number of vertices.
			std::uint8_t	m_extrusion[0x10];			///< <c>0x20</c>: Vec4
			const void*		m_indexBase;				///< <c>0x30</c>:
			int				m_indexStriding;			///< <c>0x34</c>: The byte offset between two indices triples.
			std::uint8_t	m_stridingType;				///< <c>0x38</c>: A type defining whether 16 or 32 bits are used to index vertices.
			std::uint8_t	m_flipAlternateTriangles;	///< <c>0x39</c>:
			std::uint16_t   m_pad;						///< <c>0x3A</c>: padding so that we get 0x40
			int				m_triangleOffset;			///< <c>0x3C</c>:
		};
	}

	struct HavokMaterialPalette
	{
		void* m_materialIndexBase;		///< <c>0x00</c>:
		void* m_materialBase;			///< <c>0x04</c>: hkpMeshMaterial
		std::uint32_t	m_numMaterials;	///< <c>0x08</c>:
	};

	//COLLISION_DATA_HAVOK_BG
	struct HavokBackgroundData //0x40
	{
		std::uint32_t								m_version;					///< <c>0x00</c>:
		HavokMaterialPalette*						m_aHavokMaterialPalette;	///< <c>0x04</c>: array of HavokMaterialInfo
		hkpExtendedMeshShape::TrianglesSubpart**	m_aHavokTrianglesSubpart;	///< <c>0x08</c>: array of pointers. DrawData is stored here
		std::uint32_t								m_numTrianglesSubparts;		///< <c>0x0C</c>: this is for both HavokMaterialPalette and HavokTrianglesSubpart
		std::uint32_t								field_10;					///< <c>0x10</c>:
		void*										m_unkPtr;					///< <c>0x14</c>: must be always valid
		void*										m_unkPtr2;					///< <c>0x18</c>: 
		std::uint32_t								field_1C;					///< <c>0x1C</c>:
		std::uint8_t								field_20;					///< <c>0x20</c>:
		std::uint8_t								field_21;					///< <c>0x21</c>:
		std::uint8_t								field_22;					///< <c>0x22</c>:
		std::uint8_t								field_23;					///< <c>0x23</c>:
		void*										m_pRigidBody;				///< <c>0x24</c>:
		void*										m_pLevel;					///< <c>0x28</c>:
		void*										field_2C;					///< <c>0x2C</c>: if set to 0 nothing happens
		void*										field_30;					///< <c>0x30</c>: if set to 0 nothing happens
		std::uint32_t								field_34;					///< <c>0x34</c>:
		std::uint32_t								field_38;					///< <c>0x38</c>:
		std::uint32_t								field_3C;					///< <c>0x3C</c>:
	};

	void HavokLoginLevel(uint8_t* pData);
}
