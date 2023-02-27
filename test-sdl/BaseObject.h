#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunc.h"

class BaseObject
{
public:
	BaseObject();

	~BaseObject();

	//set position for image
	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }

	//get size of image
	SDL_Rect GetRect() const { return rect_; }

	//get object
	SDL_Texture* GetObject() const { return p_object_; }

	//load image
	virtual bool LoadImg(std::string path, SDL_Renderer* screen);

	//render image
	void Render(SDL_Renderer* des, const SDL_Rect* clop = NULL);

	//free surface
	void Free();
protected:
	//save image
	SDL_Texture* p_object_;

	//save size of image
	SDL_Rect rect_;
};

#endif