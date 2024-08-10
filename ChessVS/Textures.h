#ifndef TEXTURES_H_INCLUDED
#define TEXTURES_H_INCLUDED

#include "GL/freeglut.h"
#include <iostream>
#include <string>
#include "constants.h"
#include "board.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

void ShowTexture(int figure, int x, int y)
{
	if (figure == 0)
		return;

	GLuint texture = textures[figure];

	int indent = (step - IMAGE_SIZE) / 2;
	GLfloat offX = x * step + indent;
	GLfloat offY = y * step + indent;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		
		glTexCoord2f(0, 0); 
		glVertex2f(offX, offY);

		glTexCoord2f(0, 1);
		glVertex2f(offX, offY + IMAGE_SIZE);
		
		glTexCoord2f(1, 1); 
		glVertex2f(offX + IMAGE_SIZE, offY + IMAGE_SIZE);

		glTexCoord2f(1, 0);
		glVertex2f(offX + IMAGE_SIZE, offY);

	glEnd();
}

void LoadTexture(string strfilename, int i)
{
	const char* name = strfilename.c_str();
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	int width, height, nrChannels;
	unsigned char* data = stbi_load(name, &width, &height, &nrChannels, STBI_rgb_alpha);
	
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		cout << width << " " << height << " " << nrChannels << endl;
	}
	else
	{
		cout << "Failed to load texture \"" << name << "\"" << endl;
		//exit(EXIT_FAILURE);
	}
	
	stbi_image_free(data);
}

void LoadTextures()
{
	string path = "Figures/";
	string format = ".png";

	for (int i = -6; i <= 6; i++)
	{
		if (i == 0)
			continue;
		string name = path + to_string(i) + format;
		LoadTexture(name, i);
	}
}

#endif // TEXTURES_H_INCLUDED
