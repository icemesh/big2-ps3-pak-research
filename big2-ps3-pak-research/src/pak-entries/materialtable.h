/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

//forward decl
namespace Ice
{
	namespace Render
	{
		struct VertexProgram;
		struct FragmentProgram;
	}
}

namespace MaterialTable
{
	struct Material;
	struct PropertyTag;
	struct ShaderSrc;
	struct Pass;

	bool LoginMaterialTable(uint8_t* pMem);

	void CreatePropertyMaskTable(uint8_t* pMem);

	struct MaterialTable //0x30 ?
	{
		int32_t			m_versionNumber;			///< <c>0x00</c>: verion number - 179 for big
		uint32_t		m_numberStringIds;			///< <c>0x04</c>: number of StringId in the file
		uint32_t		m_numShaders;				///< <c>0x08</c>: number of shaders in material table
		uint32_t		m_numMaterials;				///< <c>0x0C</c>: number of materials in material table
		uint32_t		m_numEntries;				///< <c>0x10</c>: number of entries in the table
		uint32_t		m_hasBeenLoggedIn;			///< <c>0x14</c>: 0x12345 set to 1 at the end of LoginMaterialTable
		uint32_t		m_pStringIds;				///< <c>0x18</c>: pointer to StringIds 
		ShaderSrc*		m_paShaderSrc;				///< <c>0x1C</c>: point to an array of ShaderSrc //m_pShader
		Material**		m_paMaterial;				///< <c>0x20</c>:
		PropertyTag**	m_apPropertyTag;			///< <c>0x24</c>: pointer array of PropertyTag
		uint32_t		m_unk7;						///< <c>0x28</c>:
		uint32_t		m_unk8;						///< <c>0x2C</c>:
	};

	struct Material
	{
		const char*		m_name;						///< <c>0x00</c>: name of the material
		uint32_t		m_unk;						///< <c>0x04</c>: always 0 ?
		uint32_t		m_unk2;						///< <c>0x08</c>: always 0 ?
		int32_t			m_numPasses;				///< <c>0x0C</c>: number of passes in the material
		Pass**			m_apPass;					///< <c>0x10</c>: array of pointers of Pass
		uint32_t		m_unk3;						///< <c>0x14</c>: StringId ?
	};

	struct Pass //0x20
	{
		uint32_t m_field_0;
		uint32_t m_field_4;
		uint32_t m_unkCount;
		uint32_t m_field_C;
		uint32_t m_unkPtr;
		uint32_t m_field_14;
		uint32_t m_field_18;
		uint32_t m_field_1C;
	};

	struct PropertyTag
	{
		char* m_name;
	};

	struct ShaderSrc //0x10
	{
		uint32_t m_unk;											///< <c>0x00</c>: 
		uint32_t m_unk2;										///< <c>0x04</c>: 
		Ice::Render::VertexProgram* m_pVertexProgram;			///< <c>0x8</c>: pointer to a vertex program
		Ice::Render::FragmentProgram* m_pFragmentProgram;		///< <c>0xC</c>: pointer to a fragment program
	};

	struct UnkStruct_0xA0
	{

	};
}

