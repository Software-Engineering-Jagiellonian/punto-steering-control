#pragma once
#include "GamepadController.h"
#include "io/Input.h"

namespace GamepadWrapper {
class GamepadInX: public Input {
private:
	GamepadController* controller;
public:
	explicit GamepadInX(GamepadController* gamepad);
	void init() override;
	int isWorking() override;
	Data get() const override;
	inputType type() const override;
};
}