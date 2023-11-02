#include "SDLHelper.h"
#include <SDL_ttf.h>
#include "Objects/GameObject2D.h"

SDL_Window* SDLHelper::window;
SDL_Renderer* SDLHelper::renderer;

bool SDLHelper::Init()
{
	const int WINDOW_WIDTH = 1200;
	const int WINDOW_HEIGHT = 700;

	// create little window with minimize and x to close 
	window = SDL_CreateWindow("Basic SDL Project",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_OPENGL);

	if (!window)
	{
		return false;
	}

	// fill in that window with a virtual canvas to draw on called a renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		return false;
	}

	TTF_Init();

	return true;
}
// example based on the code from: https://stackoverflow.com/questions/22886500/how-to-render-text-in-sdl2
void SDLHelper::DrawText(const char* text, float x, float y, int width, int height)
{
	TTF_Font* font = TTF_OpenFont("arialbd.ttf", 24);

	SDL_Color Red = { 255, 0, 0 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, Red);

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect Message_rect;
	Message_rect.x = (int)x;
	Message_rect.y = (int)y;
	Message_rect.w = width;
	Message_rect.h = height;

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void SDLHelper::DisplaySplashScreen()
{
	// this object is defined inside the GameObject2D file.
	GameObject2D SplashScreen;
	SplashScreen.Init("Data\\Art\\SplashScreen.bmp", renderer,200,50);

	for (int i = 0; i < 14; i++)
	{
		// Draw a black background
		StartFrame();
		// draw our example game object
		SplashScreen.Draw(window, renderer);

		DrawLoadingText(i);

		EndFrame();
	}

	SDL_Delay(100);

}

void SDLHelper::DrawLoadingText(int dotMod)
{
	Colour TextColor;
	TextColor.r = 1.0f;
	TextColor.g = 0.0f;
	TextColor.b = 0.0f;

	SetColor(TextColor);

	string output = "Loading";

	for (int dotCounter = 0; dotCounter < dotMod % 4; dotCounter++)
	{
		output += '.';
	}

	// 10% loading.. message size error fixed
	int w = 100;
	for (int size = output.length(); size % 7 > 0; size--)
	{
		w += 7;
	}
	DrawText(output.c_str(), 10, 10, w, 20);
	SDL_Delay(100);
}

void SDLHelper::SetColor(Colour color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0xFF);
}

void SDLHelper::StartFrame()
{
	// pause to control framerate
	SDL_Delay(3);

	SDL_SetRenderDrawColor(renderer, 0x01, 0x01, 0x01, 0xFF);
	SDL_RenderClear(renderer);
}

void SDLHelper::EndFrame()
{
	// Update the screen!
	SDL_RenderPresent(renderer);
}