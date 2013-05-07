#ifndef SWEET_SESPRITE_H
#define SWEET_SESPRITE_H

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_opengl.h"
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
		void X(seFloat value);
		seFloat Y();
		void Y(seFloat value);
		void Init_GL();
		void Draw();
		int LoadFromPNG(const char *fileName);
		void DrawImage(seFloat x, seFloat y);
		void DrawBoundingBox(); 
		virtual void Move();
		void SetColliderPosition(sePoint *_position);
	};
}

#endif