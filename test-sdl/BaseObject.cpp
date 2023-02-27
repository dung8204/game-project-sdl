#include "BaseObject.h"

BaseObject::BaseObject()
{
	//all necessary information about an object that we want to load
	p_object_ = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}



BaseObject::~BaseObject()
{
	//free memory
	Free();
}



//class base_object get the image/texture and the size of image/texture
bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
	//initialize texture
	SDL_Texture* new_texture = NULL;

	//read the image and save as SDL_Surface*
	SDL_Surface* load_surface = IMG_Load(path.c_str());


	if (load_surface != NULL)
	{
		//color key = transparent pixel -> define color will be treated as transparent in a blit, so it won't be rendered, read SDL_MapRGB
		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));

		//texture created from surface
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);


		if (new_texture != NULL)
		{
			//rect get size of load_surface
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;
		}
		
		//free surface
		SDL_FreeSurface(load_surface);
	}

	//object as a texture get the image that loaded to new_texture
	p_object_ = new_texture;

	return p_object_ != NULL;
}



//render object
void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip /* = NULL */)
{
	//size and position of object
	SDL_Rect renderquad = { rect_.x, rect_.y, rect_.w, rect_.h };
	
	//read parameters
	SDL_RenderCopy(des, p_object_, clip, &renderquad);
}



void BaseObject::Free() 
{
	if (p_object_ != NULL)
	{
		SDL_DestroyTexture(p_object_);
		p_object_ = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}