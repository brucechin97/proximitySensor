/*
 * CAbstandssensor.h
 *
 *  Created on: Jan 14, 2020
 *      Author: vmuser
 */

#ifndef CABSTANDSSENSOR_H_
#define CABSTANDSSENSOR_H_

//#include "Global.h"
#include "I2CDevice.h"

#define VL6180X_ERROR_NONE         0   ///< Success!
#define VL6180X_ERROR_SYSERR_1     1   ///< System error
#define VL6180X_ERROR_SYSERR_5     5   ///< Sysem error
#define VL6180X_ERROR_ECEFAIL      6   ///< Early convergence estimate fail
#define VL6180X_ERROR_NOCONVERGE   7   ///< No target detected
#define VL6180X_ERROR_RANGEIGNORE  8   ///< Ignore threshold check failed
#define VL6180X_ERROR_SNR          11  ///< Ambient conditions too high
#define VL6180X_ERROR_RAWUFLOW     12  ///< Raw range underflow
#define VL6180X_ERROR_RAWOFLOW     13  ///< Raw range overflow
#define VL6180X_ERROR_RANGEUFLOW   14  ///< Range underflow
#define VL6180X_ERROR_RANGEOFLOW   15  ///< Range overflow

class CAbstandssensor:protected I2CDevice
{
public:
	enum MODE { Range_SingleShot=0x01, Range_Continuous=0x03};
public:
	CAbstandssensor(unsigned int I2CBus, unsigned int I2CAddress);
	int init();
	void setRangeMode(CAbstandssensor::MODE pMode);
	bool readRange(int& pRange);
	int readRangeStatus(unsigned char& pStatus);
	int getError();
//	int Mittelwert(int& pWert);

private:
	unsigned int I2CBus, I2CAddress;
	CAbstandssensor::MODE mOperateMode;

public:
//	float mSollWert;
	unsigned char mRange;
	unsigned char mRangeStatus;
	unsigned char mReady;
	unsigned char mInterrupt;
/*	int Buffer[3];
	int writePtr;
	bool BuffFull;
	*/
};


#endif /* CABSTANDSSENSOR_H_ */
