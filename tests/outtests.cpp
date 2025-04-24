#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
#include <string>

#include "fstream"

using json = nlohmann::json;

json getJson(std::string input) {
	std::ifstream f(input);
	json data = json::parse(f);
	f.close();
	return data;
}

TEST(JSonTests, basic) {}