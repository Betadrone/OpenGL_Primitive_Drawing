#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//FALL 2023 - Graphics Programming 1 GAME300 Lab 2

// for loading sprites
#include "Utils.h"
#include "SDLHelper.h"

// processing events
#include "EventHandler.h"

// creating a basic gameobject
#include "Objects\GameObject2D.h"
#include "SDL.h"

//New OpenGl/GLEW headers
#include "../OpenGL.h"

#define WINDOW_WIDTH    1400
#define WINDOW_HEIGHT   800

extern "C"
{
	__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

// GameState
bool GameRunning = true;

bool Init(SDL_Window** mainWindow, SDL_Renderer** mainRenderer);


int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (!SDLHelper::Init())
	{
		return false;
	}


	// this will run for 1500ms before allowing input
	// 10% (minor) ["loading.." message size error]
	SDLHelper::DisplaySplashScreen();
	
	// Create instance of OpenGL project
	OpenGL project;
	SDL_GLContext GLContext = SDL_GL_CreateContext(SDLHelper::GetWindow());

	printf(" using %s card with %s:", glGetString(GL_VENDOR), glGetString(GL_RENDERER));

	// Main game loop
	while (GameRunning) 
	{
		// the order of everything within this loop is very important.
		// handle button events
		GameRunning = EventHandler::Update();

		// CLEAR THE SCREEN FIRST...
		// 15% (week 2 knowledge) [glew files]
		project.ClearScreen();

		// DRAW HERE:
		// 20% (week 3 knowledge) [Primitive drawing]
		project.CreateBorder();

		// 20% (week 3 knowledge) [triangle with different colors per vertice]
		project.CreateArrayPic();

		// 10% (minor) [Draw a Picture or character]
		project.DrawKirby();

		// 20% (week 3 knowledge) [3 triangles that share vertices]
		project.CreateElementArrayPic();

		SDL_GL_SwapWindow(SDLHelper::GetWindow());
	}

	SDL_Quit();
	return true;
}