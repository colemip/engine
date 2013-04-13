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
	/*public:
		static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
		static GLuint texName;*/
	public:
		GLWorkbench();
		~GLWorkbench();
		void init();
		int run(int argc, char **argv);
		void makeCheckImage();
		static void display();
		static void reshape(int w, int h);
		void keyboard (unsigned char key, int x, int y);
	};
}

#endif

