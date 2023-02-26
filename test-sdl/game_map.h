#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "CommonFunc.h"
#include "BaseObject.h"

#define MAX_TILES 20

class TileMat : public BaseObject
{
public:
	TileMat() { ; }
	~TileMat() { ; }
};

class GameMap
{
public:
	GameMap() { ; }
	~GameMap() { ; }

	void LoadMap(const char* name);
	void LoadTiles(SDL_Renderer* screen);
	void DrawMap(SDL_Renderer* screen);
private:
	//imformation about a block
	Map game_map_;
	//image of block
	TileMat tile_mat[MAX_TILES];
};

#endif