/*
 * TCA9546_lib.h
 *
 *  Created on: Jun 19, 2024
 *      Author: NJunker
 */

#ifndef THORLABS_TCA9546_INC_TCA9546_LIB_H_
#define THORLABS_TCA9546_INC_TCA9546_LIB_H_

#include <cstdint> //for uint8_t, etc
#include <cstddef> //for size_t


class Thorlabs_TCA9546 {
public:

	//Initialize I2C mux with I2C instance and I2C address.
	bool begin(uint8_t addr = 0x70);

	//Select I2C channel to use. Channel selection is 0-4.
	bool selectChannel(uint8_t channel);

	//Disable all I2C channels.
	bool disableChannels();

protected:

	uint8_t _addr;

	uint8_t Thorlabs_I2C_write(uint8_t *buf, size_t size) __attribute__((weak));

	void Thorlabs_I2C_read(uint8_t *buf, size_t size) __attribute__((weak));

	void Thorlabs_I2C_begin() __attribute__((weak));

	void Thorlabs_I2C_end() __attribute__((weak));

	void Thorlabs_I2C_setup() __attribute__((weak));

private:

	bool write(uint8_t data);
	uint8_t read(uint8_t data);
};


#endif /* THORLABS_TCA9546_INC_TCA9546_LIB_H_ */
