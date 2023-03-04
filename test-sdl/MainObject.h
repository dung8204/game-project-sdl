#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include <vector>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8
#define PLAYER_JUNP_VAL 18
class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	//number stands for walk to the right or the left, use to choose exacly the frame image we want
	enum WalkType
	{
		WALK_NONE = 0,
		WALK_RIGHT = 1,
		WALK_LEFT = 2,

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

	void UpdateImagePlayer(SDL_Renderer* des);

	void set_bullet_list(std::vector<BulletObject*> bullet_list)
	{
		p_bullet_list_ = bullet_list;
	}

	std::vector<BulletObject*> get_bullet_list() const { return p_bullet_list_; }

	void HandleBullet(SDL_Renderer* des);
private:
	std::vector<BulletObject*> p_bullet_list_;
	
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

	int come_back_time_;
};


#endif