#include "SerialPortLib.hpp"

SerialPort::SerialPort(int comport_number, int baudrate, std::string mode, int timeout)
{
	if (RS232_OpenComport(comport_number, baudrate, mode.c_str(), timeout) == 1)
	{
		throw std::invalid_argument("Error when opening ComPort !");
	}
	m_comport = comport_number;
	m_baudrate = baudrate;
	m_mode = mode;
}

SerialPort::~SerialPort()
{
	RS232_CloseComport(m_comport);
}

ByteArray SerialPort::getBytes()
{
	Byte buffer[4096];
	int bufSize = 4096;

	RS232_PollComport(m_comport, buffer, bufSize);

	return ByteArray(buffer, buffer + bufSize);
}

bool SerialPort::sendByte(Byte byte)
{
	if (RS232_SendByte(m_comport, byte))
		return false;
	else
		return true;
}

int SerialPort::sendBytes(ByteArray bytes)
{
	return RS232_SendBuf(m_comport, bytes.data(), bytes.size());
}

int SerialPort::sendBytes(Byte *buffer, int size)
{
	return RS232_SendBuf(m_comport, buffer, size);
}

void SerialPort::sendStr(std::string str)
{
	return RS232_cputs(m_comport, str.c_str());
}

#if defined(__linux__) || defined(__FreeBSD__)

#else

bool SerialPort::setTimeOut(int timeout)
{
	return RS232_SetTimeOut(m_comport, timeout) !=0;
}

#endif