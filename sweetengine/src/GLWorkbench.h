#ifndef SWEET_GLWORKBENCH_H
#define SWEET_GLWORKBENCH_H

#include <stdlib.h>
#include <stdio.h>
#include <glut.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"

/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64

namespace Sweet 
{
	static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
	static GLuint texName;
	/* bmp info */
	static GLuint texture = NULL;
	static GLenum texture_format = NULL;
	static GLint nofcolors;

	class GLWorkbench
	{
	public:
		GLWorkbench();
		~GLWorkbench();
		void Init();
		int Run(int argc, char **argv);
		int RunWithSprite();
		void MakeCheckImage();
		static void Display();
		static void Reshape(int w, int h);
		void Keyboard (unsigned char key, int x, int y);
		int LoadPNG(const char *fileName);
		void DrawImage();
		void Init_GL();
		bool Init_SDL_GL();
		void OnRender();
		void CleanUp();
	};
}

#endif

