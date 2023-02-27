#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "CommonFunc.h"
#include "BaseObject.h"


//the number of image used to load each kind of block
#define MAX_TILES 20

class TileMat : public BaseObject
{
public:
	TileMat() { ; }
	~TileMat() { ; }
};

//class GameMap
class GameMap
{
public:
	GameMap() { ; }
	~GameMap() { ; }

	//load map
	void LoadMap(std::string name);

	//load tile for map
	void LoadTiles(SDL_Renderer* screen);

	//draw map
	void DrawMap(SDL_Renderer* screen);

	Map getMap() const { return game_map_; };
private:
	//imformation about a block
	Map game_map_;

	//image of block
	TileMat tile_mat[MAX_TILES];
};

#endif