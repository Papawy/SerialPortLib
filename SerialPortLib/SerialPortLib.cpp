#include "SerialPortLib.hpp"

SerialPort::SerialPort(int comport_number, int baudrate, std::string mode)
{
	if (RS232_OpenComport(comport_number, baudrate, mode.c_str()) == 1)
	{
		throw std::invalid_argument("Error when opening ComPort !");
	}
	m_comportNumber = comport_number;
	m_baudrate = baudrate;
	m_mode = mode;
}

SerialPort::~SerialPort()
{
	RS232_CloseComport(m_comportNumber);
}

std::string SerialPort::get()
{
	

}