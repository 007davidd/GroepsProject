#include "auto.h"

void turnRight(void)
{
	motor[MotorRechts] = 0;
	motor[MotorLinks] = 0;

	nMotorEncoderTarget[Head] = 100;
	motor[Head] = 50;
	wait1Msec(2000);

	nMotorEncoderTarget[Head] = 100;
	motor[Head] = -50;

	nMotorEncoder[MotorLinks] = 0;
	motor[MotorRechts] = -20;
	motor[MotorLinks] = 50;
	while(nMotorEncoder[MotorLinks] < 270){}
}

void turnLeft(void)
{
	motor[MotorRechts] = 0;
	motor[MotorLinks] = 0;

	nMotorEncoderTarget[Head] = 100;
	motor[Head] = -50;
	wait1Msec(2000);

	nMotorEncoderTarget[Head] = 100;
	motor[Head] = 50;
	motor[MotorRechts] = 40;
	motor[MotorLinks] = -10;
	while(SensorValue[LichtL] < offset){}
}

void turnBack(void)
{
	motor[MotorRechts] = Tp;
	motor[MotorLinks] = -Tp;
	int en = nMotorEncoder[MotorRechts] + 500;
	while(nMotorEncoder[MotorRechts] < en){}
	motor[MotorRechts] = 0;
	motor[MotorLinks] = 0;
}

void turnStreat(void)
{
	motor[MotorRechts] = Tp;
	motor[MotorLinks] = Tp;
	while(SensorValue[LichtL] < offset){}
}
