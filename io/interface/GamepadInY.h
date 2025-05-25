#pragma once
#include "GamepadController.h"
#include "io/Input.h"
namespace GamepadWrapper {
class GamepadInY: public Input {
private:
	GamepadController* controller;
public:
	explicit GamepadInY(GamepadController* gamepad);
	void init() override;
	int isWorking() override;
	Data get() const override;
	inputType type() const override;
};
}