#pragma once

#include <string>
#include <vector>

#include <exception>
#include <stdexcept>

#include "rs232lib\rs232.h"

class SerialPort
{
	public:
		SerialPort(int comport_number, int baudrate, std::string mode);
		~SerialPort();

		std::string get();

		bool	sendByte(unsigned char byte);

		bool	send(std::string bytes);
		bool	send(std::vector<unsigned char> bytes);
		int		send(unsigned char *buffer, int size);

	protected:
		int m_comportNumber;

		int m_baudrate;
		std::string m_mode;
};