#pragma once

#include "io/Input.h"

class GamepadController : public Input {
   private:
	int workingState = 1;
   public:
	GamepadController();
	void init() override;
	int isWorking() override;
	Data* get() const override;
	inputType type() const override;

};
