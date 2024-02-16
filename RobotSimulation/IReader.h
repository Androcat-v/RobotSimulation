#pragma once
#include <string>

class IReader {
public:
	virtual ~IReader() = default;
	virtual int ReadInt() = 0;
	virtual std::string ReadString() = 0;
};
