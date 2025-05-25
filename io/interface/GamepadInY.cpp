#include "GamepadInY.h"

using namespace GamepadWrapper;

GamepadInY::GamepadInY(GamepadController* gamepad) : controller(gamepad) {
}
void GamepadInY::init() {
}
int GamepadInY::isWorking() {
	return controller->isWorking();
}
Data GamepadInY::get() const {
	return controller->getAxisY();
}

inputType GamepadInY::type() const {
	return inputType::GamepadInY;
}