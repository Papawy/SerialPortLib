#pragma once

#include <string>
#include <vector>

#include <exception>
#include <stdexcept>

#include "rs232lib\rs232.h"

typedef unsigned char Byte;

typedef std::vector<Byte> ByteArray;

class SerialPort
{
	public:
		SerialPort(int comport_number, int baudrate, std::string mode, int timeout = 0);
		~SerialPort();

		ByteArray getBytes();

		bool	sendByte(Byte byte);

		int		sendBytes(ByteArray bytes);
		int		sendBytes(Byte *buffer, int size);

		void	sendStr(std::string str);

#if defined(__linux__) || defined(__FreeBSD__)
		// Need RS232_SetTimeOut linux implementation
#else
		bool	setTimeOut(int timeout);
#endif

		// Accessors

		int		getComPort() { return m_comport; };
		int		getBaudRate() { return m_baudrate; };
		std::string getMode() { return m_mode; };

	protected:
		int m_comport;

		int m_baudrate;
		std::string m_mode;
};