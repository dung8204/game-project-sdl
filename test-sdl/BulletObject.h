#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include "BaseObject.h"
#include "CommonFunc.h"


class BulletObject:public BaseObject
{
public:
	BulletObject();
	~BulletObject();

	enum BulletDir
	{
		DIR_RIGHT = 20,
		DIR_LEFT = 21,
		DIR_UP_RIGHT = 22,
		DIR_UP_LEFT = 23,
		DIR_DOWN_RIGHT = 24,
		DIR_DOWN_LEFT = 25
	};

	enum BulletStatus
	{
		STRAIGHT = 30,
		UP = 31,
		DOWN = 32
	};

	enum BulletType
	{
		NORMAL = 40,
		SO_HEAD = 41
	};

	void set_x_val(const int& xVal) { x_val_ = xVal; }
	void set_y_val(const int& yVal) { y_val_ = yVal; }
	int get_x_val() const { return x_val_; }
	int get_y_val() const { return y_val_; }

	void set_is_move(const bool& isMove) { is_move_ = isMove; }
	bool get_is_move() const { return is_move_; }

	void HandleMove(const int& x_border, const int& y_border);

	void set_bullet_dir(const unsigned int& bulletDir) { bullet_dir_ = bulletDir; }
	
	void LoadImgBullet(SDL_Renderer* des, int status_);

	void set_bullet_type(const unsigned int& bulletType) { bullet_type_ = bulletType; }

	unsigned int get_bullet_type() const { return bullet_type_; };
private:
	float x_val_;
	float y_val_;
	bool is_move_;
	unsigned int bullet_dir_;
	unsigned int bullet_type_;
};

#endif