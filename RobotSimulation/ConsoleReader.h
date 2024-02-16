#pragma once
#include "IReader.h"
#include <iostream>

class ConsoleReader : public IReader {
public:
	int ReadInt() override
	{
		int number;
		std::cin >> number;

		while (!std::cin.good()) {
			std::cout << "Your input is of wrong type, please enter a number" << std::endl;
			ClearStream(std::cin);
			std::cin >> number;
		}
		return number;
	}

	std::string ReadString() override
	{
		std::string name;
		std::cin >> name;
		return name;
	}
private:

	void ClearStream(std::istream& stream)
	{
		stream.clear();
		stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};

