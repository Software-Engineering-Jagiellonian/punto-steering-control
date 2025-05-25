#pragma once
#include "io/Input.h"

class GamepadController {
   private:
	int workingState = 1;

	float axisX = 0;
	float axisY = 0;
   public:
	GamepadController();
	void init();
	int isWorking();
	float getAxisX() const;
	float getAxisY() const;
	void print() const;
};
