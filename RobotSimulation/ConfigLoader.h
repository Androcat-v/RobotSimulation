#pragma once
#include <memory>
#include <iostream>
#include "RobotConfiguration.h"
#include "IReader.h"

class ConfigLoader 
{
public:

	

	void SetReader(std::unique_ptr<IReader> readerChoice)
	{
		m_reader = std::move(readerChoice);
	}

	RobotConfiguration LoadConfig()
	{
		std::cout << "Enter robot vacuum's energy level, dustholder capacity, name and please!" << std::endl;
		return RobotConfiguration{m_reader->ReadInt(), m_reader->ReadInt(), m_reader->ReadString()};	
	}


private:
	std::unique_ptr<IReader> m_reader;
};
