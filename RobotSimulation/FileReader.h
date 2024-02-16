#pragma once
#include "IReader.h"
#include <fstream>
#include <iostream>

class FileReader : public IReader {
public:
	FileReader() {
		/*чтобы у меня скомпилилось. сорри.*/
	}

	FileReader(std::ifstream&& inputStream)
		: m_inputStream(std::move(inputStream)) {}

	int ReadInt() override {

		if (!m_inputStream.is_open()) {
			std::cout << "File isn't open";
			return 0;
		}

		int number = 0;

		m_inputStream >> number;

		if (!m_inputStream.good())
		{
			std::cout << "Don't change my file!!! >:(";
			return 0;
		}
		return 0;
	}

	std::string ReadString() override {

		if (!m_inputStream.is_open()) {
			std::cout << "File isn't open";
			return "";
		}
		std::string name; //не инициализируем, потому что вызывается конструктор по умолчанию
		m_inputStream >> name;
		return name;
	}
private:
	std::ifstream m_inputStream;
};
