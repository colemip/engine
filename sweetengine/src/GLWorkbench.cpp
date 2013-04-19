/*
Examples taken from 
http://www.glprogramming.com/red/chapter09.html
http://www.gaanza.com/blog/display-2d-sprite/
*/

#include <tchar.h>
#include <iostream>
#include "GLWorkbench.h"

using namespace Sweet;

#define SPRITE_TEST 1
#define TEXTURE_TEST 0

SDL_Surface *Surf_Display;

GLWorkbench::GLWorkbench()
{
}


GLWorkbench::~GLWorkbench()
{
}

int GLWorkbench::Run(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);		
	Init_GL();
	glutDisplayFunc(GLWorkbench::Display);
	glutReshapeFunc(GLWorkbench::Reshape);	
	glutMainLoop();
	return 0; 
}

int GLWorkbench::RunWithSprite()
{
	Init_GL();	
	LoadPNG("C:\\projects\\engine\\sweetengine\\build\\bin\\Debug\\helloworld.png");
	DrawImage();
	return 0;
}

void GLWorkbench::Display()
{
	std::cout << "Calling display" << std::endl;
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

int GLWorkbench::LoadPNG(const char *fileName)
{
	SDL_Surface *surface;
	int imgInitValue = IMG_Init(IMG_INIT_PNG);
	if((imgInitValue & IMG_INIT_PNG) != IMG_INIT_PNG)
		std::cout << "Failed to init png support" << std::endl;

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
		else if(nofcolors==3) //no alpha channel
		{
			if(surface->format->Rmask==0x000000ff)
				texture_format=GL_RGB;
			else
				texture_format=GL_BGR;
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

void GLWorkbench::DrawImage()
{
	// Clear screen buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Bind the texture to which subsequent calls refer to
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);
	// Top-left vertex
	glTexCoord2i(0, 0);
	glVertex3f(100, 100, 0);
	// Bottom-left vertex
	glTexCoord2i(1, 0);
	glVertex3f(228, 100, 0);
	// Bottom-right vertex
	glTexCoord2i(1, 1);
	glVertex3f(228, 228, 0);
	// Top-right vertex
	glTexCoord2i(0, 1);
	glVertex3f(100, 228, 0);

	glEnd();
	glLoadIdentity();
	SDL_GL_SwapBuffers();
}

bool GLWorkbench::Init_SDL_GL()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
 
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);
 
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,            32);
 
    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
 
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);
 
    if((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        return false;
    }
 
    glClearColor(0, 0, 0, 0);
 
    glViewport(0, 0, 640, 480);
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
 
    glOrtho(0, 640, 480, 0, 1, -1);
 
    glMatrixMode(GL_MODELVIEW);
 
    glEnable(GL_TEXTURE_2D);
 
    glLoadIdentity();
 
    return true;
}

void GLWorkbench::OnRender() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
 
    glBegin(GL_QUADS);
        glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
        glColor3f(1, 1, 0); glVertex3f(100, 0, 0);
        glColor3f(1, 0, 1); glVertex3f(100, 100, 0);
        glColor3f(1, 1, 1); glVertex3f(0, 100, 0);
    glEnd();
 
    SDL_GL_SwapBuffers();
}

void GLWorkbench::Init_GL()
{
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	glClearColor(0, 0, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GLWorkbench::CleanUp()
{
	glDeleteTextures(1, &texture);	
}