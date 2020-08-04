/*
 * main.cpp
 *
 *  Created on: Jan 10, 2020
 *      Author: Bruce Chin
 */

#include "CAbstandssensor.h"
//#include <stdio.h>
#include <unistd.h>
//#include <fcntl.h>
//#include <sys/ioctl.h>
//#include <linux/i2c.h>
//#include <linux/i2c-dev.h>
//#include <unistd.h>
#include <iostream>
#include "sys/time.h"
//#include <fstream>
using namespace std;

int main()
{
//	ofstream file;
//	file.open("ProxSensor.txt");
	CAbstandssensor Sensor1(2, 0x29);				// I2C Bus 2, Sensor mit Adresse 0x29
	Sensor1.init();
	int Messabstand=0;
	unsigned char error=0;

	struct timeval 				mTik;					// tik for synchronization (20ms)
	struct timeval				mTok;					// tok for synchronization (20ms)
	struct timezone				mTimezone;
	static constexpr float 	sTs{0.02F};

	unsigned long long tik_abs, tok_abs, sleep = 0;

	while (true)
	{
		gettimeofday(&mTik, &mTimezone);
		tik_abs = mTik.tv_sec * 1000000 + mTik.tv_usec;

		Sensor1.readRange(Messabstand);
		cout<<"Range: "<<Messabstand<<endl;

		gettimeofday(&mTok, &mTimezone);
		tok_abs = mTok.tv_sec * 1000000 + mTok.tv_usec;
		sleep = tok_abs - tik_abs;
		cout<<"Execution time:"<<sleep<<endl;
		usleep( (sTs * 1000000 ) - sleep);

	}

	return 0;
}


