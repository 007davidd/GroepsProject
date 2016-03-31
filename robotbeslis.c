//#include "queue.c"

void turnRight(void);
void turnLeft(void);

#pragma config (Motor, motorA, motorLinks, tmotorNXT, openLoop, encoder)
#pragma config (Motor, motorB, motorIets, tmotorNXT, openLoop)
#pragma config (Motor, motorC, motorRechts, tmotorNXT, openLoop)
#pragma config(Sensor, S4,     Licht,          sensorLightActive)

int speedL = 0;
int speedR = 0;

int lijn = 100;



task rij(){
	while(speedR < 50 && speedL < 50){
		speedR++;
		speedL++;
		motor[MotorRechts]=speedR;
		motor[MotorLinks]=speedL;
		wait1Msec(50);
	}
}


task stoprij(){
			motor[motorLinks] = 0;
			motor[motorRechts] = 0;
			wait1Msec(100);

}

task sense(){
	// lees de sensoren
	while(true){
		if(SensorValue[Licht] >= lijn){                    		//check de safety sensor en de main sensor voor beiden zwarte lijnen
			// stop met rijden en maak de beslissing
			StopTask(rij);
			StartTask(stopRij);
			speedR=0;
			speedL=0;
			if(1){         // in deze statements komt het beslissing gedeel van tarik

			  turnLeft();

		  }
		 else if {

		    turnRight();

		 }
		 else{
		    turnStreat();
	  }

			motor[MotorRechts]=-5;
			motor[MotorLinks]=-5;
			wait1Msec(1000);
			motor[MotorRechts]=0;
			motor[MotorLinks]=0;
		}
	}
}

task main()
{
	//queue que;

	startTask(rij);
	starttask(sense);

}

void turnRight(void){
	int en = nMotorEncoder[MotorLinks] + 350;
	nMotorEncoderTarget[MotorLinks] = en;
	motor[MotorLinks] =50;
	motor[MotorRechts] = -20;
	while(nMotorEncoder[MotorLinks = != en){}
}


void turnLeft(void){
	int en = nMotorEncoder[MotorRechts] + 200;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] =50;
	motor[MotorRechts] = -40;
	while(nMotorEncoder[MotorRechts = != en){}
}

/*
void turnStreat(void){
	int en = nMotorEncoder[MotorRechts] + 70;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] =Tp;
	motor[MotorRechts] = TP;
	while(nMotorEncoder[MotorRechts = != en){}
}
*/
