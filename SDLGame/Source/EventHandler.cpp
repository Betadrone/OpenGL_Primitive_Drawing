#include "EventHandler.h"
#include <stdio.h>
#include <string.h>

bool EventHandler::events[];

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

bool EventHandler::Update()
{
	bool success = true;

	SDL_Event currEvents;
	// Check for events
	while (SDL_PollEvent(&currEvents))
	{
		switch (currEvents.key.keysym.sym)
		{
			case SDLK_RIGHT:
			{
				SetButton(ControlsEvents::RIGHT_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_LEFT:
			{
				SetButton(ControlsEvents::LEFT_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_UP:
			{
				SetButton(ControlsEvents::UP_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_DOWN:
			{
				SetButton(ControlsEvents::DOWN_PRESSED, currEvents.key.type == SDL_KEYDOWN);
				break;
			}
			case SDLK_ESCAPE:
			{
				return false;
				break;
			}
		}
	}	
	return success;
}

void EventHandler::SetButton(ControlsEvents eventNum, bool pressed)
{
	events[eventNum] = pressed;
}
