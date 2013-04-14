/*
Examples taken from http://www.glprogramming.com/red/chapter09.html
*/

#include <tchar.h>
#include <iostream>
#include "GLWorkbench.h"

using namespace Sweet;

GLWorkbench::GLWorkbench()
{
}


GLWorkbench::~GLWorkbench()
{
}

void GLWorkbench::Init()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	MakeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
					GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
					GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, 
					checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, 
					checkImage);
}

int GLWorkbench::Run(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	Init();
	glutDisplayFunc(GLWorkbench::Display);
	glutReshapeFunc(GLWorkbench::Reshape);	
	glutMainLoop();
	return 0; 
}

void GLWorkbench::MakeCheckImage()
{
	int i, j, c;
    
    for (i = 0; i < checkImageHeight; i++) {
		for (j = 0; j < checkImageWidth; j++) {
			c = ((((i&0x8)==0)^((j&0x8))==0))*255;
			checkImage[i][j][0] = (GLubyte) c;
			checkImage[i][j][1] = (GLubyte) c;
			checkImage[i][j][2] = (GLubyte) c;
			checkImage[i][j][3] = (GLubyte) 255;
		}
	}
}

void GLWorkbench::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texName);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
	glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D);
}


void GLWorkbench::Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -3.6);
}

void GLWorkbench::Keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int GLWorkbench::LoadPNG(const char *fileName)
{
	SDL_Surface *surface;

	if((surface = IMG_Load(fileName)))
	{
		/* check if image's width is power of 2 */
		if((surface->w & (surface->w - 1)) != 0)
		{
			std::cout << "WARNING: image's width NOT power of 2" << std::endl;
		}
		/* check if image's height is power of 2 */
		if((surface->h & (surface->h - 1)) != 0)
		{
			std::cout << "WARNING: image's height NOT power of 2" << std::endl;
		}

		/* get number of channels in surface */
		nofcolors = surface->format->BytesPerPixel;

		// contains an alpha channel
		if(nofcolors == 4)
		{
			if(surface->format->Rmask == 0x000000ff)
				texture_format = GL_RGBA;
			else
				texture_format = GL_BGR;
		}
		else
		{
			std::cout << "Image is NOT truecolor" << std::endl;
		}

		// have OpenGL generate a texture object handle
		glGenTextures(1, &texture);

		// bind the texture object
		glBindTexture(GL_TEXTURE_2D, texture);

		// set the texture's stretching properties
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, nofcolors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels);
	}
	else
	{
		std::cout << "Could not load image.bmp: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Free the SDL_Surface only if it was successfully created
	if(surface)
	{
		SDL_FreeSurface(surface);
	}

	return 0;
}

void GLWorkbench::DrawImage(const char *fileName)
{

}

