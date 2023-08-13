#include "region-tree.h"
#include <stdio.h>

void RegionTree::Login()
{
	int i = 0;
	while (m_aRegion[i] != 0)
	{
		printf("%s\n", m_aRegion[i]->m_name);
		i++;
	}
}
