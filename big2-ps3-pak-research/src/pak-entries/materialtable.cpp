/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#include "materialtable.h"
#include "../utils/utils.h"
#include "../utils/stringid.h"
#include <stdio.h>

const char*	g_shaderPrimaryTagNames[] = {
	"postprocess",
	"showtexturecoords",
	"drawlightfirstpass",
	"drawlightsecondpass",
	"drawspherelightonepass",
	"waterccean",
	"cgfx",
	"HairPass3",
};



/*
struct ShaderTagDesc {
	const char* m_name;
	uint32_t m_value;
};

ShaderTagDesc g_shaderTagNames[145] =
{
  { "Standard", 1 },
  { "Bg", 3 },
  { "Fg", 4 },
  { "LodHigh", 5 },
  { "LodFadeoutHigh", 7 },
  { "LodFadeoutHighe", 7 },
  { "LodDLightsHigh", 9 },
  { "LodDLightsfadeouthigh", 12 },
  { "Shadows", 13 },
  { "TechniqueDebug", 14 },
  { "LocalShadows", 15 },
  { "DepthOnly", 16 },
  { "DepthOnlyFadeout", 17 },
  { "NormalDepthOnly", 18 },
  { "SurfaceReflection", 19 },
  { "DecalRaycast", 20 },
  { "HairPass1", 21 },
  { "HairPass2", 22 },
  { "Waterfall", 24 },
  { "WaterRiver", 26 },
  { "WaterOcean", 25 },
  { "DebugVertexNormals", 35 },
  { "DebugVertexTangents", 36 },
  { "DebugVertexBinormals", 37 },
  { "DebugWireframe", 38 },
  { "2d", 27 },
  { "3d", 28 },
  { "Text", 29 },
  { "GameText", 30 },
  { "SymbolText", 31 },
  { "JapText", 32 },
  { "KorText", 33 },
  { "ChiText", 34 },
  { "Skydome", 39 },
  { "Particle", 40 },
  { "kawaseBloomPass1_1", 41 },
  { "kawaseBloomPass2_2", 42 },
  { "kawaseBloomPass3_1", 43 },
  { "kawaseBloomPass4_2", 44 },
  { "kawaseBloomPass5_1", 45 },
  { "kawaseBloomPass6_2", 46 },
  { "kawaseBloomPass6_2_Add", 47 },
  { "gaussianFilter", 48 },
  { "bloomFilterPassX", 49 },
  { "bloomFilterPassY", 50 },
  { "srcBlurCombo", 51 },
  { "srcDofBlurCombo", 52 },
  { "srcDofBlurTonemapBloomTintCombo", 53 },
  { "srcDofBlurTonemapBloomTintDistortionCombo", 54 },
  { "srcDofBlurTonemapBloomSaturateTintCombo", 55 },
  { "srcDofBlurTonemapBloomSaturateTintDistortionCombo", 56 },
  { "srcDofBlurTonemapBloomTintMotionBlurCombo", 57 },
  { "srcDofBlurTonemapBloomTintDistortionMotionBlurCombo", 58 },
  { "srcDofBlurTonemapBloomSaturateTintMotionBlurCombo", 59 },
  { "srcDofBlurTonemapBloomSaturateTintDistortionMotionBlurCombo", 60 },
  { "srcDofBlurTonemapBloomTintBlendCombo", 61 },
  { "srcDofBlurTonemapBloomTintDistortionBlendCombo", 62 },
  { "srcDofBlurTonemapBloomSaturateTintBlendCombo", 63 },
  { "srcDofBlurTonemapBloomSaturateTintDistortionBlendCombo", 64 },
  { "srcDofBlurTonemapBloomTintMotionBlurBlendCombo", 65 },
  { "srcDofBlurTonemapBloomTintDistortionMotionBlurBlendCombo", 66 },
  { "srcDofBlurTonemapBloomSaturateTintMotionBlurBlendCombo", 67 },
  { "srcDofBlurTonemapBloomSaturateTintDistortionMotionBlurBlendCombo", 68 },
  {	"srcDofBlurTonemapBloomSaturateTintDistortionMotionBlurBlendComboCutScene",	69 },
  { "edgeSmoothDofBlurTonemapBloomTintCombo", 70 },
  { "sourceBuffer0_Add_sourceBuffer1", 71 },
  { "fourSampleBox0", 72 },
  { "sourceColorBuffer", 73 },
  { "sourceColorBufferBlend", 74 },
  { "sourceColorBufferRegion", 75 },
  { "sourceColorBufferRgb", 76 },
  { "blendDownsampledBufferAndOriginalBuffer", 77 },
  { "sourceAlphaBuffer", 78 },
  { "alphaBlendWithRenderBuffer", 79 },
  { "sourceDepthBuffer", 80 },
  { "sourceInvDepthBuffer", 81 },
  { "resolveParticleRenderTargetToPrimaryBuffer", 82 },
  { "copyDepthBufferToParticeRenderTarget", 83 },
  { "resolveDepthBufferForFogAndWaterRefractionWithoutDepth", 84 },
  { "resolveDepthBufferForUniFogAndWaterRefraction", 85 },
  { "createParticlePointRecieveShadowBuffer", 86 },
  { "boxFilterDownSample", 87 },
  { "sampleLuminanceInitial", 88 },
  { "sampleLuminanceFinal", 89 },
  { "createBaseBloomTexture", 90 },
  { "clearColorBuffer", 91 },
  { "clearColorBufferWithDepthTest", 92 },
  { "averageEnemyVisibileRate", 93 },
  { "brighterPass", 94 },
  { "calculateDepthIntoAlphaChannel", 95 },
  { "resolveShadowInfoBuffer", 96 },
  { "resolveSunlightShadowAndLightInfoBuffer", 97 },
  { "resolveSunlightShadowInfoBlurredBuffer", 98 },
  { "resolveSunlightShadowInfoBlurredBufferWithClipPlanes", 99 },
  { "drawLightStencilMaskPass", 100 },
  { "drawLightStencilMaskNoDepthTestPass", 101 },
  { "drawSphereLightPass", 113 },
  { "drawThreeSphereLightsPass", 102 },
  { "drawThreeSphereLightsInnerPass", 103 },
  { "drawCellOneSphereLightPass", 104 },
  { "drawCellTwoSphereLightsPass", 105 },
  { "drawCellThreeSphereLightsPass", 106 },
  { "drawCellFourSphereLightsPass", 107 },
  { "drawCellFiveSphereLightsPass", 108 },
  { "drawCellSixSphereLightsPass", 109 },
  { "drawCellSevenSphereLightsPass", 110 },
  { "drawCellEightSphereLightsPass", 111 },
  { "drawGroupSphereLightPass", 112 },
  { "drawSphereLightPass", 113 },
  { "drawSphereLightWithShadowPass", 114 },
  { "drawSphereLightWithShadowForCutscenePass", 115 },
  { "drawSphereLightOnBackgroundPass", 116 },
  { "drawSphereLightWithSpotShadowPass", 117 },
  { "drawConeLightPass", 118 },
  { "drawConeLightWithoutShadowPass", 119 },
  { "drawConeLightWithShadowPass", 120 },
  { "drawConeLightWithShadowPassWithoutDepthTest", 121 },
  { "drawFlashLightWithoutShadowAndMaskPass", 122 },
  { "drawFlashLightWithShadowAndMaskPass", 123 },
  { "drawFlashLightWithShadowAndMaskPassExcluseActor", 124 },
  { "drawFlashLightWithShadowAndMaskPassWithoutDepthTest", 125 },
  { "drawFlashLightShaftPassWithoutDepthTest", 126 },
  { "drawFlashLightWithShadowAndMaskPassWithoutDepthTestExcluseActor", 127 },
  { "drawProjectLightWithoutShadowPass", 128 },
  { "drawProjectLightWithShadowPass", 129 },
  { "drawProjectLightWithoutShadowAndMaskPass", 130 },
  { "drawProjectLightWithShadowAndMaskPass", 131 },
  { "copyDepthCleanStencil", 132 },
  { "drawLightDebugPass", 133 },
  { "drawDebugAmbientColor", 134 },
  { "createMotionBlurImage", 135 },
  { "createMotionBlurUvImage", 136 },
  { "createMotionBlurUvImageForChase", 137 },
  { "blendMotionBlurUvImage", 138 },
  { "copyMotionBlurUvImage", 139 },
  { "smoothLightBufferPass", 140 },
  { "figureOutEdgePass", 141 },
  { "copyRgba8ColorBuffer", 142 },
  { "testEnemyVisibleInfo", 143 },
  { "clearDepthBufferByNearestDepth", 144 },
  { "clearDepthBufferByFarestDepth", 145 },
  { "hackPixelShaderForCausticSeq0", 146 },
  { "hackPixelShaderForCausticSeq1", 147 },
  { "minMaxDepthValueInitialize", 148 },
  { "minMaxDepthValue", 149 }
};
*/

struct ShaderTag
{
	StringId m_nameId;
	uint32_t m_value;
};

ShaderTag stru_E16A50[237] =
{
	{0x13A1C349, 1},
	{0x73F552F7, 3},
	{0x36D1735E, 4},
	{0x4FB9A76C, 5},
	{0x9620A15F, 6},
	{0xA45A84D0, 6},
	{0xFB87606F, 7},
	{0x61436C8C, 8},
	{0xF7BB54C0, 9},
	{0x7D963218, 0xA},
	{0x727CA13, 6},
	{0x2F5ECD5E, 0xB},
	{0xD554B5CD, 0xC},
	{0xEC715CFF, 0xD},
	{0x9EEAE8DD, 0xE},
	{0xA4B72862, 0xF},
	{0x2D58544E, 0x10},
	{0x8A29A4E6, 0x11},
	{0xE2F6CA87, 0x12},
	{0x5B4F7F98, 0x13},
	{0x2A7F0331, 0x14},
	{0x1CABB1B7, 0x15},
	{0xBD484A02, 0x16},
	{0xDD620175, 0x17},
	{0xD02127AC, 0x18},
	{0xFCD2EFB6, 0x19},
	{0x950E94A9, 0x1B},
	{0x58E6953A, 0x1A},
	{0x2FE39D50, 0x26},
	{0x2CC3824F, 0x27},
	{0x1DF2D505, 0x28},
	{0xCB45FDA0, 0x29},
	{0x2FA18371, 0x1C},
	{0xFDB842AD, 0x1D},
	{0xCA773CD7, 0x1E},
	{0xF3D3F1A9, 0x1F},
	{0xFD454010, 0x20},
	{0xC2262D4, 0x21},
	{0x677ACA45, 0x22},
	{0x3987299E, 0x23},
	{0x124AD18D, 0x24},
	{0xF3C7112F, 0x25},
	{0x6F4E92F1, 0x2A},
	{0x852FF270, 0x2B},
	{0xF394EBEF, 0x2C},
	{0xFCBE38BF, 0x2D},
	{0xF025B2E1, 0x2E},
	{0xF86DD3AD, 0x2F},
	{0xF4F659F3, 0x30},
	{0xFBDC8AA3, 0x31},
	{0x3D76E8C0, 0x32},
	{0xAD1AF57A, 0x33},
	{0x1532D52D, 0x34},
	{0x11F3C89A, 0x35},
	{0x6DB399B6, 0x36},
	{0x8AB3094E, 0x37},
	{0xCFEE6C74, 0x38},
	{0x44EFEE13, 0x39},
	{0x6B079985, 0x3A},
	{0x6B62150D, 0x3B},
	{0xE847D9E7, 0x3C},
	{0x2D2FD8AC, 0x3D},
	{0x51939636, 0x3E},
	{0xAE6F98CE, 0x3F},
	{0xB5C3380D, 0x40},
	{0x7F59FE39, 0x41},
	{0x807462DF, 0x42},
	{0xF6236CA7, 0x43},
	{0x30D8B904, 0x44},
	{0x2852CA0C, 0x45},
	{0x356CF008, 0x46},
	{0x98FE11D7, 0x47},
	{0x2EA027CE, 0x48},
	{0x39F71A82, 0x49},
	{0xEB0637D2, 0x4A},
	{0x85A00119, 0x4B},
	{0xA680E1E8, 0x4C},
	{0x2AFECA2F, 0x4D},
	{0x5AB8D129, 0x4E},
	{0x80F0EB3D, 0x4F},
	{0x587BCB71, 0x50},
	{0x57CFF73B, 0x51},
	{0xD65EEF6D, 0x52},
	{0xC3BBD996, 0x53},
	{0x5724C014, 0x54},
	{0x98438948, 0x55},
	{0x7DEA8462, 0x56},
	{0x73C6D1D5, 0x57},
	{0xBA7FF6CD, 0x58},
	{0x9389F287, 0x59},
	{0xF8296A75, 0x5A},
	{0x1C8B24D1, 0x5B},
	{0x84D3131C, 0x5C},
	{0xBE66EFB6, 0x5D},
	{0x104F9A5C, 0x5E},
	{0xD09E3450, 0x5F},
	{0x67BD24BE, 0x60},
	{0x7C2E63A9, 0x61},
	{0xC5410200, 0x62},
	{0x6757D9EB, 0x63},
	{0xA052F8FF, 0x64},
	{0x235A0E5D, 0x65},
	{0x335384B0, 0x66},
	{0xB3BD71F7, 0x67},
	{0xCCA6DE79, 0x68},
	{0x6DE7DEDC, 0x69},
	{0x2FF5BE95, 0x6A},
	{0x994D3EA0, 0x6B},
	{0x94E434B1, 0x6C},
	{0x25399209, 0x6D},
	{0x5D94314D, 0x6E},
	{0xC2CFDA8B, 0x6F},
	{0x2953E1AC, 0x70},
	{0xCAF7493A, 0x71},
	{0x78388262, 0x72},
	{0xE42EA76A, 0x73},
	{0x93EEE7F3, 0x74},
	{0xEDE86CA0, 0x75},
	{0xE16BAC51, 0x76},
	{0x34FF973F, 0x78},
	{0xB48687A5, 0x79},
	{0xA4DF52D3, 0x7A},
	{0x50CA11D2, 0x7B},
	{0xBC0ADE42, 0x7C},
	{0x344123C8, 0x7D},
	{0x51E2D49E, 0x7E},
	{0xB28B3D8, 0x7F},
	{0x16959C3E, 0x80},
	{0xECD6203, 0x81},
	{0x9FCB3F14, 0x77},
	{0x6E4A52AF, 0x82},
	{0x9C69628A, 0x83},
	{0x7DAC8C18, 0x84},
	{0x1D0F5C2E, 0x85},
	{0x1AA71137, 0x86},
	{0x1E6FF2D1, 0x87},
	{0x22D305C7, 0x88},
	{0x4D71E438, 0x89},
	{0xC8A9862D, 0x8A},
	{0xDA36A538, 0x8B},
	{0x86DB1422, 0x8C},
	{0x70AA5495, 0x8D},
	{0x2A0C03B2, 0x8E},
	{0x39381AAA, 0x8F},
	{0x6FD2D7FF, 0x90},
	{0xB77CF128, 0x91},
	{0x841C703F, 0x92},
	{0xC37B540F, 0x93},
	{0x7FD5F0E4, 0x94},
	{0x30E9920B, 0x95},
	{0x5F00E1CE, 0x96},
	{0x6B888BD, 0x97},
	{0xD0A261F3, 0x98},
	{0x4C8E6ECB, 0x99},
	{0x525476ED, 0x9A},
	{0x56956B5A, 0x9B},
	{0x37BEF934, 0x9C},
	{0x78E99125, 0x9D},
	{0xA9102916, 0x9E},
	{0xE6474107, 0x9F},
	{0x23D1C6E2, 0xA0},
	{0x991624C7, 0xA1},
	{0xC02F5E46, 0xA2},
	{0x3AB73DAC, 0xA3},
	{0xBA5ED61, 0xA4},
	{0x47A3F6B6, 0xA5},
	{0xCF8FCD48, 0xB1},
	{0xDFF6F700, 0xA6},
	{0x6251A032, 0xA7},
	{0x5F8A3343, 0xA8},
	{0x1E16CE71, 0xA9},
	{0xD1FECBF0, 0xAA},
	{0x780DF2F1, 0xAB},
	{0xDDF63AFB, 0xAC},
	{0x14C37571, 0xAD},
	{0x6E0EB998, 0xAE},
	{0x3679A2E2, 0xAF},
	{0xF431C173, 0xB0},
	{0xCF8FCD48, 0xB1},
	{0x9CCE6836, 0xB2},
	{0xFAAD6D74, 0xB3},
	{0x52FFF1C3, 0xB4},
	{0xBEB50BE6, 0xB5},
	{0xCD4A79B5, 0xB6},
	{0xA77CC551, 0xB7},
	{0x9E1F9469, 0xB8},
	{0x212D121B, 0xB9},
	{0xC48E7121, 0xBA},
	{0x92C65764, 0xBB},
	{0x8F8A56F6, 0xBC},
	{0x51D000E9, 0xBD},
	{0xAAF008C2, 0xBE},
	{0x18B34FB0, 0xBF},
	{0x551CC518, 0xC0},
	{0xA413F56E, 0xC1},
	{0xD53F9245, 0xC2},
	{0x415AEFA4, 0xC3},
	{0x77CCBCB0, 0xC4},
	{0x6C0E9EB2, 0xC5},
	{0xA744C2F5, 0xC6},
	{0xD527E0C0, 0xC7},
	{0x1FA38304, 0xC8},
	{0xAAD4CE20, 0xC9},
	{0x5FD2A9D5, 0xCA},
	{0xDD070F27, 0xCB},
	{0x4C302185, 0xCC},
	{0x2518A1C1, 0xCD},
	{0x13893199, 0xCE},
	{0x623B115D, 0xCF},
	{0x39DF905D, 0xD0},
	{0x8D2DBDDD, 0xD1},
	{0xB756F227, 0xD2},
	{0xD095F648, 0xD3},
	{0x76DB57CA, 0xD4},
	{0x3AD204CF, 0xD5},
	{0x6010B6C, 0xD6},
	{0x81049F0, 0xD7},
	{0xF26FA47C, 0xD8},
	{0x8B2ADAC6, 0xD9},
	{0x75D0C28B, 0xDA},
	{0xD7CBDF56, 0xDC},
	{0x41E368B9, 0xDB},
	{0x291A913B, 0xDD},
	{0x1430346F, 0xDE},
	{0x3491C65C, 0xDF},
	{0xF1A88DC2, 0xE0},
	{0xAE736B90, 0xE1},
	{0x3C4256F2, 0xE2},
	{0x3BD94D21, 0xE3},
	{0xAE150A02, 0xE4},
	{0x3022AE5D, 0xE5},
	{0xF8CC6C4C, 0xE6},
	{0xDD0BE0A2, 0xE7},
	{0xAEFF7680, 0xE8},
	{0xAA3E6B37, 0xE9},
	{0x428269BF, 0xEA},
	{0x9FE5EBDF, 0xEB}
};

bool MaterialTable::LoginMaterialTable(uint8_t* pMem)
{
	MaterialTable* pTable = reinterpret_cast<MaterialTable*>(pMem);
	if (pTable)
	{
		uint32_t version = swapU32(&pTable->m_versionNumber);
		if (version != 0x79)
		{
			MsgWarn("Invalid version number %d, [current version %d]", version, 0x79);
			puts("Need to reexport assets");
		}
		if (swapU32(&pTable->m_hasBeenLoggedIn) == 0x12345)
		{
#ifdef _DEBUG
			printf("num materials: %d\n", swapU32(&pTable->m_numMaterials));
			printf("num ShaderSrc: %d\n", swapU32(&pTable->m_numShaders));
#endif
			//lwz       r8, 0x10(r4)
			uint32_t numEntries = swapU32(&pTable->m_numEntries);
			if (numEntries != 0)
			{
				//00749724 3A 80 00 00 li        r20, 0
				uint32_t iEntries = 0x0;
				//lwz       r0, 0x28(r11)
				uint8_t* unkPtr = (uint8_t*)pTable->m_unk7;
				do
				{
					//0074973C 56 89 10 3A slwi      r9, r20, 2
					//00749748 7D 29 02 14 add       r9, r9, r0
					//unkPtr += (iEntries << 0x2); //+= 0x4
					//00749758 7C 17 07 B4 extsw     r23, r0
					uint32_t numTechniques = swapU32(unkPtr+ (iEntries << 0x2)); //yes yes i know should be int32_t
					if (numTechniques != 0)
					{
						//00749768 56 96 18 38 slwi      r22, r20, 3 

						//0074976C 3B 80 00 00 li        r28, 0
						uint32_t iTechnique = 0;
						do {
							//0074977C 38 00 04 00 li        r0, 0x400
							int cap = 0x400;
							//00749780 39 00 00 00 li        r8, 0
							int capItr = 0;
							//00749788 81 69 00 24 lwz       r11, 0x24(r9)
							//00749760 56 98 10 3A slwi      r24, r20, 2
							//0074978C 7D 78 5A 14 add       r11, r24, r11

							//00749778 57 9B 10 3A slwi      r27, r28, 2
							//00749794 81 2B 00 00 lwz       r9, 0(r11)
							PropertyTag* pTag = pTable->m_apPropertyTag[iEntries];
							//00749798 7D 3B 4A 14 add       r9, r27, r9
							//007497A0 81 69 00 00 lwz       r11, 0(r9)
#ifdef _DEBUG
							printf("[%d] tag: %s\n", iTechnique, pTag[iTechnique].m_name);
#endif	
							//this is simply a snprint(buf, 0x400, "%s", pTech[iTechnique].m_name);
							/*
							do {
								//007497BC 7D 28 5A 14 add       r9, r8, r11
								//007497D4 89 29 00 00 lbz       r9, 0(r9)
								//007497D8 7D 2A 07 74 extsb     r10, r9
								//007497DC 38 09 FF BF addi      r0, r9, -0x41
								//007497E0 2F 8A 00 00 cmpwi     cr7, r10, 0
								if (pTech[iTechnique].m_name[capItr] == 0x00)
								{
									break;
								}
							} while (cap--);
							*/
							StringId tagId = SID(pTag[iTechnique].m_name);
							/*
							for (int i = 0; i < 0xED; i++)
							{

							}
							*/
							iTechnique++;
						} while (iTechnique < numTechniques);
					}
					//007498C4 3A 94 00 01 addi      r20, r20, 1
					iEntries++;
				} while (iEntries < numEntries);
				/*
				uint32_t nShaderSrc = swapU32(&pTable->m_numShaderSrc);
				for (uint32_t iShader = 0; iShader < nShaderSrc; iShader++)
				{
					Ice::Render::VertexProgram* pVtxProg = pTable->m_paShaderSrc[iShader].m_pVertexProgram;
					Ice::Render::FragmentProgram* pFragProg = pTable->m_paShaderSrc[iShader].m_pFragmentProgram;
				}
				*/
				uint32_t numMaterials = swapU32(&pTable->m_numMaterials);
				for (uint32_t iMaterial = 0; iMaterial < numMaterials; iMaterial++)
				{
					Material* pMat = pTable->m_paMaterial[iMaterial];
					Pass* pPass = pMat->m_apPass[0];
					printf("Material: %s\n", pMat->m_name);
				}
			}
			return true;
		}
		return false;
	}
	return false;
}

/*
* uint32_t version = swapU32(&pTable->m_versionNumber);
		if (version != 0x79)
		{
			MsgWarn("Invalid version number %d, [current version %d]", version, 0x79);
			puts("Need to reexport assets");
		}
		if (swapU32(&pTable->m_inited) == 0x12345)
		{
			//lwz       r21, 0x24(r28)
			uint8_t* unkPtr = (uint8_t*)pTable->m_unk6;
			//lwz       r22, 0x28(r28)
			uint8_t* unkPtr2 = (uint8_t*)pTable->m_unk7;
			//stw       r7, 0x24(r28)
			//stw       r7, 0x28(r28)
			*(uint64_t*)(pMem + 0x24) = 0; //remove me
			//lwz       r31, 0x10(r28)
			//slwi      r3, r31, 3 
			int32_t numEntries = (int32_t)swapU32(pMem + 0x10);
			//malloc() && memset
			
			//00483A54 mr        r10, r3
			//00483A88 stw       r10, 0x24(r28)

			//00483A80 lwz       r11, 0x10(r28)
			//00483A8C cmpwi     cr7, r11, 0
			//00483A94 beq       cr7, NULL_SIZE
			if (numEntries != 0)
			{
				//00483A84 li        r23, 0
				int32_t counter = 0;
				//00483A90 li        r26, 0
				uint32_t itr = 0;
				do {
					//00483A98 add       r15, r26, r22
					unkPtr2 += itr; //pointer table probably
					//00483A9C clrldi    r9, r15, 32
					//00483AA0 lwz       r0, 0(r9)
					//00483AA4 cmpwi     cr7, r0, 0
					if (swapU32(unkPtr2) != 0)
					{
						//00483AAC slwi      r27, r23, 3

						//00483AB4 li        r24, 0
						int32_t innerCounter = 0;
						//00483ABC add       r29, r26, r21
						int32_t target = swapU32(unkPtr2);
						unkPtr += itr;

						int arrayItr = 0;
				static	int arrayElements = sizeof(stru_100ADD1C) / sizeof(unkStructTag);
						do {
							//00483AC0 slwi      r12, r24, 2
							//00483AC4 li        r25, 0
							bool foundTag = false;
							//00483AC8 mr        r4, r18
							do
							{
								unkPtr += innerCounter * 4;
								arrayItr++;
							} while (arrayItr < arrayElements);
							//004832AC addi      r24, r24, 1
							innerCounter++;
						} while (innerCounter < target);
					}
					//004832C4 addi      r23, r23, 1
					counter++;
					//004832CC addi      r26, r26, 4
					itr += 4;
				} while (counter < numEntries);
			}
			CreatePropertyMaskTable(pMem);
		}
		return true;
	}
*/

void MaterialTable::CreatePropertyMaskTable(uint8_t* pMem)
{

}
