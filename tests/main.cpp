#include <gtest/gtest.h>
#include <thread>
#include <chrono>
#include "TestOutput.h"
#include "logic/GamepadControlProcessor.h"
#include "TestIOCoordinator.h"

class GamepadControlProcessorTest : public ::testing::Test {
protected:
    GamepadControlProcessor processor;
};


// TESTY GAMEPAD ----------------------------------------------------------------------------------

TEST_F(GamepadControlProcessorTest, ProcessesXInputCorrectly) {
    std::map<inputType, Data> input = {
        {GamepadInX, 42.0f}
    };

    auto* output = processor.process(&input);

    ASSERT_NE(output, nullptr);
    ASSERT_EQ(output->size(), 1);
    ASSERT_TRUE(std::holds_alternative<float>(output->at(GamepadOutX)));
    ASSERT_FLOAT_EQ(std::get<float>(output->at(GamepadOutX)), 42.0f);

    delete output;
}

TEST_F(GamepadControlProcessorTest, ProcessesYInputCorrectly) {
    std::map<inputType, Data> input = {
        {GamepadInY, 99.0f}
    };

    auto* output = processor.process(&input);

    ASSERT_NE(output, nullptr);
    ASSERT_EQ(output->size(), 1);
    ASSERT_TRUE(std::holds_alternative<float>(output->at(GamepadOutY)));
    ASSERT_FLOAT_EQ(std::get<float>(output->at(GamepadOutY)), 99.0f);

    delete output;
}

TEST_F(GamepadControlProcessorTest, IgnoresUnknownInput) {
    std::map<inputType, Data> input = {
        {static_cast<inputType>(999), 1} // nieznany klucz
    };

    auto* output = processor.process(&input);

    ASSERT_NE(output, nullptr);
    ASSERT_TRUE(output->empty());

    delete output;
}

TEST_F(GamepadControlProcessorTest, ProcessesMultipleInputs) {
    std::map<inputType, Data> input = {
        {GamepadInX, 1.5f},
        {GamepadInY, 2.5f},
        {static_cast<inputType>(1234), 3.5f}
    };

    auto* output = processor.process(&input);

    ASSERT_NE(output, nullptr);
    ASSERT_EQ(output->size(), 2);
    ASSERT_TRUE(std::holds_alternative<float>(output->at(GamepadOutX)));
    ASSERT_TRUE(std::holds_alternative<float>(output->at(GamepadOutY)));
    ASSERT_FLOAT_EQ(std::get<float>(output->at(GamepadOutX)), 1.5f);
    ASSERT_FLOAT_EQ(std::get<float>(output->at(GamepadOutY)), 2.5f);

    delete output;
}

// TESTY IO COORDINATOR ----------------------------------------------------------------------------------

TEST(IOCoordinatorTest, PushOutputs_ShouldProcessDataAndSendToOutput) {
    auto* input = new DummyInput();
    auto* output = new DummyOutput();
    auto* processor = new DummyProcessor();

    IOCoordinator coordinator(processor);
    coordinator.addInputObject(input);
    coordinator.addOutputObject(output);

    // Testujemy pushOutputs bez pętli nieskończonej ze start()
    coordinator.pushOutputs();

    ASSERT_EQ(std::get<float>(output->received.at(outputType::WheelTurn)), 42.0f);
}

// Sprawdzenie, czy input i output są poprawnie dodane (liczba obiektów)
TEST(IOCoordinatorTest, AddInputAndOutputObjects_ShouldStoreThem) {
    auto* input1 = new DummyInput();
    auto* input2 = new DummyInput();
    auto* output1 = new DummyOutput();
    auto* output2 = new DummyOutput();
    auto* processor = new DummyProcessor();

    IOCoordinator coordinator(processor);

    coordinator.addInputObject(input1);
    coordinator.addInputObject(input2);
    coordinator.addOutputObject(output1);
    coordinator.addOutputObject(output2);

    coordinator.pushOutputs();

    ASSERT_EQ(std::get<float>(output1->received.at(outputType::WheelTurn)), 42.0f);
    ASSERT_EQ(std::get<float>(output2->received.at(outputType::WheelTurn)), 42.0f);

}

// Brak inputów i outputów
TEST(IOCoordinatorTest, PushOutputs_WithNoInputsOrOutputs_ShouldNotCrash) {
    auto* processor = new DummyProcessor();
    IOCoordinator coordinator(processor);

    // Nie dodajemy żadnych inputów ani outputów
    // Sprawdzamy, czy metoda działa i nie powoduje błędu
    ASSERT_NO_THROW({
        coordinator.pushOutputs();
    });
}

// getInputs() powinno zwracać dane od wszystkich inputów
TEST(IOCoordinatorTest, GetInputs_ShouldReturnAllInputValues) {
	auto* input1 = new DummyInput();
	auto* input2 = new DummyInput();
	input1->isWorkingVal = true;
	input2->isWorkingVal = true;

	auto* processor = new DummyProcessor();
	IOCoordinator coordinator(processor);

	coordinator.addInputObject(input1);
	coordinator.addInputObject(input2);

	auto inputs = coordinator.getInputs();

	ASSERT_EQ(inputs->size(), 1);  // Oba inputy mają ten sam typ: GamepadInX, zostaną nadpisane
	ASSERT_EQ(std::get<int>(inputs->at(inputType::GamepadInX)), 123);
}

// start() powinno wywołać init() i isWorking() na inputach (symulacja cyklu)
TEST(IOCoordinatorTest, Start_ShouldCallInitAndIsWorking) {
	auto* input = new DummyInputStart();
	auto* output = new DummyOutput();
	auto* processor = new DummyProcessor();

	IOCoordinator coordinator(processor);
	coordinator.addInputObject(input);
	coordinator.addOutputObject(output);

	// Uruchom w osobnym wątku albo skróconej wersji
	std::thread startThread([&]() {
		coordinator.start();
	});

	// dzialaj krotko i przerwij
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	startThread.detach();  // UWAGA: w normalnych testach lepiej kontrolować zakończenie!

	// Sprawdzamy, czy init został wywołany
	ASSERT_TRUE(input->calledInit);
}
