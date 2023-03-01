#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "CommonFunc.h"
#include "BaseObject.h"

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8
#define PLAYER_JUNP_VAL 20
class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	//number stands for walk to the right or the left, use to choose exacly the frame image we want
	enum WalkType
	{
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
	};

	//load image
	bool LoadImg(std::string path, SDL_Renderer* screen);

	//show player
	void Show(SDL_Renderer* des);

	//handle the keyboard input
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen);

	//set clips
	void set_clips();

	//truyen vao map, check xem limit cua ban do, khong cho phep nhan vat di vuot qua ban do
	void DoPlayer(Map& map_data);

	void CheckToMap(Map& map_data);

	void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x, map_y_ = map_y; }

	void CenterEntityOnMap(Map& map_data);
private:
	//val of player
	float x_val_;
	float y_val_;

	//position of player
	float x_pos_;
	float y_pos_;

	//size of frame
	int width_frame_;
	int height_frame_;

	//number of frame iamge we load
	SDL_Rect frame_clip_[8];

	//luu trang thai
	input input_type_;

	//luu chi so cua frame (dang o frame nao)
	int frame_;

	//di chuyen sang phai hay sang trai
	int status_;

	bool on_ground_;
	
	//luu vi tri ban do
	int map_x_;
	int map_y_;
};
#endif