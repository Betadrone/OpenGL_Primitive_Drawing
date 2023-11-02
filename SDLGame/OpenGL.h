#pragma once

#define GL3_PROTOTYPES 1
#include "glew.h"

#include "Source/EventHandler.h"

class OpenGL
{
public:
	OpenGL() {}
	~OpenGL() {}

	void ClearScreen();
	void CreateBorder();
	void CreateArrayPic();
	void CreateElementArrayPic();
	void DrawKirby();

private:
	void CreateDotGL();
	void CreateLineGL();
	void CreateTriangleGL();
	int indexLen = sizeof(triVert) / sizeof(float);

	float vertices[9] = { -0.5f, 0.5f, 0.0f,
							-0.52f, 0.45f, 0.0f,
							-0.48f, 0.45f, 0.0f,
							
	};
	float colors[12] = { 1.0f, 0.0f, 0.0f, 1.0f,
						0.0f, 1.0f, 0.0f, 1.0f,
						0.0f, 0.0f, 1.0f,1.0f
	};

	float triVert[18] = {0.5f, 0.5f, 0.0f,
						0.4f, 0.5f, 0.0f,
						0.6f, 0.5f, 0.0f,
						0.55f, 0.6f, 0.0f,
						0.45f, 0.6f, 0.0f,
						0.5f, 0.7f, 0.0f
	};

	unsigned int vertIndex[9] = {1, 0, 4, // tri 1
								0, 2, 3, // tri 2
								5, 4, 3 // tri 3
	};
};

