/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#include "vis-info.h"
#include "../utils/utils.h"

#include <stdio.h>

void Visibility::DumpInfo(uint8_t* pMem)
{
	VisInfo* pVisInfo = reinterpret_cast<VisInfo*>(pMem);
	if (swapU32(&pVisInfo->m_versionNumber) == 7)
	{
		int32_t numCells = (int32_t)swapU32(&pVisInfo->m_numVisRegions);
		printf("m_numVisRegions: %d\n", numCells);
		int32_t iCell = 0;
		VisCell* pTable = pVisInfo->m_pVisTable;
		for (iCell; iCell < numCells; iCell++)
		{
			VisCell* pCell = &pTable[iCell];
			int32_t numSides = (int32_t)swapU32(&pCell->m_numSides);
			VisSide* pSide = pCell->m_pVisSide;
			printf("VisCell[%d]:\n", iCell);
			for (int i = 0; i < numSides; i++)
			{
				int32_t nPoints = swapU32(&pSide[i].m_numPoints);
				VisPoint* pPoint = pSide[i].m_pVisPoint;
				for (int32_t iPoint = 0; iPoint < nPoints; iPoint++)
				{
					uint32_t x = swapU32(&pPoint->m_vec.m_x);
					uint32_t y = swapU32(&pPoint->m_vec.m_y);
					uint32_t z = swapU32(&pPoint->m_vec.m_z);
					printf("    VisPoint[%d]: %f %f %f\n", iPoint, *(float*)&x, *(float*)&y, *(float*)&z);
					pPoint++;
				}
			}
			puts("----------------------------------");
		}
	}
	else
	{
		puts("Error: Vis Version wrong");
	}
}