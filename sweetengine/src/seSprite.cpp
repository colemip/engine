#include "seSprite.h"

using namespace Sweet;

seSprite::seSprite()
{
	this->texture = NULL;
	this->texture_format = NULL;
}


seSprite::~seSprite()
{
}

seString seSprite::FileName()
{
	return this->fileName;
}

seFloat seSprite::X()
{
	return this->position->X();
}

seFloat seSprite::Y()
{
	return this->position->Y();
}

void seSprite::Init_GL()
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

void seSprite::Draw()
{
	Init_GL();
	LoadFromPNG("C:\\projects\\engine\\sweetengine\\build\\bin\\Debug\\helloworld.png");
	DrawImage();
}

int seSprite::LoadFromPNG(const char *fileName)
{
	SDL_Surface *surface;
	GLint nofcolors;

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
				this->texture_format = GL_RGBA;
			else
				this->texture_format = GL_BGR;
		}
		else if(nofcolors==3) //no alpha channel
		{
			if(surface->format->Rmask==0x000000ff)
				this->texture_format = GL_RGB;
			else
				this->texture_format = GL_BGR;
		}
		else
		{
			std::cout << "Image is NOT truecolor" << std::endl;
		}

		// have OpenGL generate a texture object handle
		glGenTextures(1, &this->texture);

		// bind the texture object
		glBindTexture(GL_TEXTURE_2D, this->texture);

		// set the texture's stretching properties
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, nofcolors, surface->w, surface->h, 0, this->texture_format, GL_UNSIGNED_BYTE, surface->pixels);
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

void seSprite::DrawImage()
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

void seSprite::DrawBoundingBox()
{
	//clear color and depth buffer 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); //load identity matrix
	glColor3f(0, 1, 0);

	glBegin(GL_LINE_LOOP);
		glVertex3f(-0.25f, -0.25f, 0.0f);
		glVertex3f(-0.25f, 0.25f, 0.0f);
		glVertex3f(0.25f, 0.25f, 0.0f);
		glVertex3f(0.25f, -0.25f, 0.0f);
	glEnd();
}

void seSprite::Move()
{
	// update collider here
}

void seSprite::SetColliderPosition(sePoint *_position)
{
	this->collider->SetPosition(_position);
}
