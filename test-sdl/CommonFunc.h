#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "BaseObject.h"
#include <iostream>

//window
static SDL_Window* g_window = NULL;

//screen on the window
static SDL_Renderer* g_screen = NULL;

//event
static SDL_Event g_event;

//information of screen
const int FRAME_PER_SECOND = 30; //
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;

//pixel of game
const int SCREEN_BPP = 32; 

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

//render draw color
const int RENDER_DRAW_COLOR = 255;

#define BLANK_TILE 0

//size of a block tile*tile
#define TILE_SIZE 64

//number of block in xlabel
#define MAX_MAP_X 400

//number of block in y label
#define MAX_MAP_Y 10

//struct input stands for the keyboard arrow
typedef struct input
{
	int left_;
	int right_;
	int down_;
	int jump_;
	int up_;
};

//struct includes all the features of map
typedef struct Map
{
	//vi tri mep man hinh ben trai so voi ban do full
	int start_x_;
	//vi tri mep man hinh ben trai sp voi ban do full
	int start_y_;

	//chieu dai toi da cua map
	int max_x_;
	//chieu dai toi da cua map
	int max_y_;


	//vi tri cua block
	int tile[MAX_MAP_Y][MAX_MAP_X];

	//ten file dau vao
	std::string file_name_;
};

#endif
