#pragma once

#include <string>

#include "rs232lib\rs232.h"

class SerialPort
{
	public:
		SerialPort(int comport_number, int baudrate, std::string mode);

		std::string get();

		bool send(unsigned char bytes)


};