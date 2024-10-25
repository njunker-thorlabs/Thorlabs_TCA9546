/*
 * TCA9546_lib.cpp
 *
 *  Created on: Jun 19, 2024
 *      Author: NJunker
 */

#include "TCA9546_lib.h"

bool Thorlabs_TCA9546::begin(uint8_t addr)
{
	_addr = addr;

	Thorlabs_I2C_setup();
}

bool Thorlabs_TCA9546::write(uint8_t data)
{
	uint8_t ret;
	uint8_t cmd[1];
	//build command word
	cmd[0] = data;

	Thorlabs_I2C_begin();
	ret = Thorlabs_I2C_write(cmd, sizeof(cmd));
	Thorlabs_I2C_end();

	return (ret > 0) ? false : true;
}

uint8_t Thorlabs_TCA9546::read(uint8_t data)
{
	uint8_t cmd[1];
	uint8_t _read_buf[1];
	//build command word
	cmd[0] = data;

	Thorlabs_I2C_begin();
	Thorlabs_I2C_write(cmd, sizeof(cmd));
	Thorlabs_I2C_end();
	Thorlabs_I2C_read(_read_buf, sizeof(_read_buf));
	
	return _read_buf[0];
}

bool Thorlabs_TCA9546::selectChannel(uint8_t channel)
{
	if (channel <= 3 && channel >= 0) {
		uint8_t data = 0x00;
		data = data | (1 << channel);
		return write(data);
	} else {
		return false;
	}
}

bool Thorlabs_TCA9546::disableChannels()
{
	return write(0x00);
}

//-----------------------------------------------------------------------
//------------------- To be implemented by user -------------------------
//-----------------------(Platform Specific)-----------------------------
//-----------------------------------------------------------------------

uint8_t Thorlabs_TCA9546::Thorlabs_I2C_write(uint8_t *buf, size_t size) {
	//Implement this in a parent class or modify for your platform

	//Take in an array of single bytes (buf) and length
	//Return length of bytes successfully transmitted
}

void Thorlabs_TCA9546::Thorlabs_I2C_read(uint8_t *buf, size_t size) {
	//Implement this in a parent class or modify for your platform

	//Takes in a pointer to a buffer to place data in, and size of said buffer
}

void Thorlabs_TCA9546::Thorlabs_I2C_begin() {
	//Implement this in a parent class or modify for your platform

	//Used if your platform has an I2C transaction begin function (i.e. Arduino)
}

void Thorlabs_TCA9546::Thorlabs_I2C_end() {
	//Implement this in a parent class or modify for your platform
	
	//Used if your platform has an I2C transaction end function (i.e. Arduino)
}

void Thorlabs_TCA9546::Thorlabs_I2C_setup() {
	//Implement this in a parent class or modify for your platform

	//Platform specific startup code, i.e. setting pins, clock speed, etc
}
