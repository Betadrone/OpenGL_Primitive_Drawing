#pragma once
#include "SDL.h"

enum ControlsEvents
{
	RIGHT_PRESSED,
	LEFT_PRESSED,
	UP_PRESSED,
	DOWN_PRESSED,

	NUM_CONTROLS_EVENTS

};

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	static bool Update();

	static const int NUM_EVENTS = 10;

	static bool events[ControlsEvents::NUM_CONTROLS_EVENTS];
private:

	static void SetButton(ControlsEvents eventNum, bool pressed);
};


