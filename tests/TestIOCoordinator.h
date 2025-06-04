#pragma once

#include "data/Data.h"
#include "io/IOCoordinator.h"

class DummyInput : public Input {
public:
    bool calledInit = false;
    bool isWorkingVal = true;

    void init() override;
    int isWorking() override;

    Data get() const override;
    inputType type() const override;

    ~DummyInput() override = default;
};

class DummyOutput : public Output {
public:
    std::map<outputType, Data> received;

    void push(std::map<outputType, Data>* data) override;

    ~DummyOutput();
};

class DummyProcessor : public DataProcessor {
public:
    std::map<outputType, Data>* process(std::map<inputType, Data>* inputs) override;

    ~DummyProcessor() override = default;
};

class DummyInputStart : public DummyInput {
public:
	int workingCalls = 2;

	int isWorking() override;
};