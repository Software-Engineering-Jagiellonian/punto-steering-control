#pragma once
#include "io/IOCoordinator.h"

int main() {
	DataProcessor* data_processor = nullptr;
	const IOCoordinator ioc(data_processor);
	ioc.start();
	delete data_processor;
}
