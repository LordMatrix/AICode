
// project A Star
// astar.h
// author: Toni Barella
// Artificial Intelligence - 3VGP
// ESAT 2016/2017

#ifndef __ASTAR__
#define __ASTAR__

#include <algorithm>

#include "../../include/config.h"
#include "path.h"
#include "cost_map.h"

class AStar
{
	std::vector<Cell*> list_open_;
	Cell*** list_open_indexes_;
	
	std::vector<Cell*> list_closed_;
	Cell*** list_closed_indexes_;

	CostMap *map_;

public:
	AStar();
	AStar(const AStar& orig);
	~AStar();

	bool PreProcess(CostMap *map);
	bool GeneratePath(MOMOS::Vec2 origin, MOMOS::Vec2 destination, Path *path);
};
#endif // __ASTAR__