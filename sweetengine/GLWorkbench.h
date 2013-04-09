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
	class GLWorkbench
	{
	private:
		static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
		static GLuint texName;
	public:
		GLWorkbench();
		~GLWorkbench();
		void Init();
		void makeCheckImage();
		void display();
		void reshape(int w, int h);
		void keyboard (unsigned char key, int x, int y);
	};
}

#endif

