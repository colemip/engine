#ifndef SWEET_SESPRITE_H
#define SWEET_SESPRITE_H

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"
#include "glut.h"
#include "sePoint.h"
#include "Collider.h"
#include "Types.h"

namespace Sweet
{
	class seSprite
	{
	private:
		seString	fileName;
		sePoint		*position;
		Collider	*collider;
		GLuint		texture;
		GLenum		texture_format;

	public:
		seSprite();
		~seSprite();
		seString FileName();
		seFloat X();
		seFloat Y();
		int LoadFromPNG(const char *fileName);
		void DrawBoundingBox(); 
		virtual void Move();
		void SetColliderPosition(sePoint *_position);
	};
}

#endif