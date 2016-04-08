#include "auto.h"

task man_ramp_up(){
	if(btn == "UP"){
		Tp = 10;
		while(Tp < fTp){
			Tp += 2;
			motor[MotorLinks] = Tp;
			motor[MotorRechts] = Tp;
			wait10Msec(1);
		}
		}else if(btn == "DOWN"){
		Tp = 10;
		while(Tp < fTp){
			Tp += 2;
			motor[MotorLinks] = -Tp;
			motor[MotorRechts] = -Tp;
			wait10Msec(1);
		}
		}else if(btn == "LEFT"){
		Tp = 10;
		while(Tp < fTp){
			Tp += 2;
			motor[MotorLinks] = -Tp;
			motor[MotorRechts] = Tp;
			wait10Msec(1);
		}
		}else if(btn == "RIGHT"){
		Tp = 10;
		while(Tp < fTp){
			Tp += 2;
			motor[MotorLinks] = Tp;
			motor[MotorRechts] = -Tp;
			wait10Msec(1);
		}
	}
}

task man_ramp_down(){
	if(btn == "UP"){
		while(Tp > 0){
			Tp -= 2;
			motor[MotorLinks] = Tp;
			motor[MotorRechts] = Tp;
			wait10Msec(1);
		}
		}else if(btn == "DOWN"){
		while(Tp > 0){
			Tp -= 2;
			motor[MotorLinks] = -Tp;
			motor[MotorRechts] = -Tp;
			wait10Msec(1);
		}
		}else if(btn == "LEFT"){
		while(Tp > 0){
			Tp -= 2;
			motor[MotorLinks] = -Tp;
			motor[MotorRechts] = Tp;
			wait10Msec(1);
		}
		}else if(btn == "RIGHT"){
		while(Tp > 0){
			Tp -= 2;
			motor[MotorLinks] = Tp;
			motor[MotorRechts] = -Tp;
			wait10Msec(1);
		}
	}
	btn = "";
}
