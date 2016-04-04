#pragma config(Sensor, S1,     Bumper,         sensorNone)
#pragma config(Sensor, S2,     Sonar,          sensorSONAR)
#pragma config(Sensor, S3,     LichtR,         sensorLightActive)
#pragma config(Sensor, S4,     LichtL,         sensorLightActive)
#pragma config(Motor,  motorA,          MotorLinks,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          MotorRechts,   tmotorNXT, PIDControl)

void turnRight90(void);
void turnLeft90(void);
//void turnRight45(void);
void turnLeft45(void);

void turnStreat(void);
void turnBack(void);

int forwardSpeed = 20;
int backwardSpeed = -20;

int max_light = 0;
int min_light = 0;




task zoek() {
			if(SensorValue[LichtL] > min_light && SensorValue[LichtR] > min_light ){   //beiden sensors zien wit
		 	//stopTask(rij);                                                          // de lijnvolg rij functie wordt gestopt
			turnBack();
			turnStreat();
			turnLeft90();
			turnStreat();
			turnBack();
			turnRight90();                 // check zuid west oostelijke richtingen om de lijn te vinden
			turnRight90();
			turnStreat();
			turnBack();
			turnLeft90();

			turnLeft90();
			turnLeft45();
			turnStreat();
			turnBack();
			turnRight90();
			turnStreat();
			turnBack();
			turnRight90();
			turnStreat();
			turnBack();
			turnRight90();
			turnStreat();
			turnBack();
			turnLeft90();
			turnLeft45();

		}
}

task rij(){
	while(true){
	int en = nMotorEncoder[MotorRechts] + 70;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = 80;												//rij met een speed van 80 rechtdoor
	motor[MotorLinks] = 80;
	if(SensorValue[LichtL] > min_light){     // lijn is kwijtgeraakt er wordt veel wit gezien
				playSound(soundBeepBeep);
				stopTask(rij);
				startTask(zoek);
  }
	while(nMotorEncoder[MotorRechts] != en){}
 }
}

//void turnRight45(void)                             //45 graden bocht
//{
//	int en = nMotorEncoder[MotorLinks] + 175;
//	nMotorEncoderTarget[MotorLinks] = en;
//	motor[MotorLinks] = 50;
//	motor[MotorRechts] = -20;
//		if(SensorValue[LichtL] < min_light){     // lijn is gevonden
//			stopTask(zoeklijn);
//			startTask(rij);
//  }
//	while(nMotorEncoder[MotorLinks] != en){}
//}

void turnLeft45(void)
{
	int en = nMotorEncoder[MotorRechts] + 100;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = 50;
	motor[MotorLinks] = -40;
		if(SensorValue[LichtL] < min_light){     // lijn is gevonden
			stopTask(zoek);
			startTask(rij);
  }
	while(nMotorEncoder[MotorRechts] != en){}
}

void turnRight90(void)                         // 90 graden bocht
{
	int en = nMotorEncoder[MotorLinks] + 350;
	nMotorEncoderTarget[MotorLinks] = en;
	motor[MotorLinks] = 50;
	motor[MotorRechts] = -20;
		if(SensorValue[LichtL] < min_light){     // lijn is gevonden
			stopTask(zoek);
			startTask(rij);
  }
	while(nMotorEncoder[MotorLinks] != en){}
}

void turnLeft90(void)
{
	int en = nMotorEncoder[MotorRechts] + 200;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = 50;
	motor[MotorLinks] = -40;
		if(SensorValue[LichtL] < min_light){     // lijn is gevonden
			stopTask(zoek);
			startTask(rij);
  }
	while(nMotorEncoder[MotorRechts] != en){}
}

void turnStreat(void)
{
	int en = nMotorEncoder[MotorRechts] + 70;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = forwardSpeed;												//rij met een speed van 20 rechtdoor
	motor[MotorLinks] = forwardSpeed;
	if(SensorValue[LichtL] < min_light){     // lijn is gevonden
			stopTask(zoek);
			startTask(rij);
  }
	while(nMotorEncoder[MotorRechts] != en){}
}

void turnBack(void)
{
	int en = nMotorEncoder[MotorRechts] + 70;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = backwardSpeed;    // rij met een speed van 20 achteruit
	motor[MotorLinks] = backwardSpeed;

	if(SensorValue[LichtL] < min_light){     // lijn is gevonden
			stopTask(zoek);
			startTask(rij);
  }
	while(nMotorEncoder[MotorRechts] != en){}
}


task main()
{
		min_light = SensorValue[LichtL];
		max_light = SensorValue[LichtR];
		startTask(rij);

}


//als sensors geen input hebben dus beiden wit

//rij stukje naar achter (als er geen lijn aanwezig is na het naar achter rijden

//rij dan in alle richtingen langzaam een stukje naar voren
//als lijn niet gevonden terug naar het midden en
