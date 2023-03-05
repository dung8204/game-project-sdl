#include "BulletObject.h"
#include "MainObject.h"
BulletObject::BulletObject()
{
	x_val_ = 0;
	y_val_ = 0;
	is_move_ = 0;
}

BulletObject::~BulletObject()
{

}

void BulletObject::HandleMove(const int& x_border, const int& y_border)
{
	switch (bullet_dir_)
	{
		case DIR_RIGHT:
		{
			rect_.x += x_val_;
			if (rect_.x > x_border)
			{
				is_move_ = false;
			}
			break;
		}
		case DIR_LEFT:
			rect_.x -= x_val_;
			if (rect_.x < 0)
			{
				is_move_ = false;
			}
			break;
		case DIR_UP_RIGHT:
		{
			rect_.x += x_val_;
			rect_.y -= y_val_;
			if (rect_.x > x_border)
			{
				is_move_ = false;
			}
			if (rect_.y < 0)
			{
				is_move_ = false;
			}
			break;
		}
		case DIR_UP_LEFT:
		{
			rect_.x -= x_val_;
			rect_.y -= y_val_;
			if (rect_.x < 0)
			{
				is_move_ = false;
			}
			if (rect_.y < 0)
			{
				is_move_ = false;
			}
			break;
		}
		case DIR_DOWN_RIGHT:
		{
			rect_.x += x_val_;
			rect_.y += y_val_;
			if (rect_.x > x_border)
			{
				is_move_ = false;
			}
			if (rect_.y > y_border)
			{
				is_move_ = false;
			}
			break;
		}
		case DIR_DOWN_LEFT:
		{
			rect_.x -= x_val_;
			rect_.y += y_val_;
			if (rect_.x < 0)
			{
				is_move_ = false;
			}
			if (rect_.y > y_border)
			{
				is_move_ = false;
			}
			break;
		}
	}
}

void BulletObject::LoadImgBullet(SDL_Renderer* des,int status_)
{

	if (bullet_type_ == SO_HEAD)
	{
			if (status_ == MainObject::WALK_LEFT)
				LoadImg("img/so_bullet_left.png", des);
			else
				LoadImg("img/so_bullet_right.png", des);
	}
	else if (bullet_type_ == NORMAL)
	{
		LoadImg("img/bullet.png", des);
	}
}