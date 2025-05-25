#include "GamepadInX.h"

#include <iostream>
#include <ostream>

using namespace GamepadWrapper;

GamepadInX::GamepadInX(GamepadController* gamepad) : controller(gamepad) {
}
void GamepadInX::init() {
}
int GamepadInX::isWorking() {
	return controller->isWorking();
}
Data GamepadInX::get() const {
	return controller->getAxisX();
}

inputType GamepadInX::type() const {
	return inputType::GamepadInX;
}