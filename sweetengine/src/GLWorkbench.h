#ifndef SWEET_GLWORKBENCH_H
#define SWEET_GLWORKBENCH_H

#include <stdlib.h>
#include <stdio.h>
#include <glut.h>

/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64

namespace Sweet 
{
	static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
	static GLuint texName;

	class GLWorkbench
	{
	public:
		GLWorkbench();
		~GLWorkbench();
		void Init();
		int Run(int argc, char **argv);
		void MakeCheckImage();
		static void Display();
		static void Reshape(int w, int h);
		void Keyboard (unsigned char key, int x, int y);
	};
}

#endif

