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
int speed = 40;

int max_light = 80;   //80
int min_light = 255;   //50




task zoek() {
	while(true){
			//if(SensorValue[LichtL] > max_light && SensorValue[LichtR] > max_light ){   //beiden sensors zien wit
		 	//stopTask(rij);                                                          // de lijnvolg rij functie wordt gestopt


			//turnBack();
			turnStreat();
			turnLeft90();
			turnStreat();
			//turnBack();
			//turnRight90();                 // check zuid west oostelijke richtingen om de lijn te vinden
			//turnRight90();
			//turnStreat();
			//turnBack();
			//turnLeft90();

			//turnLeft90();
			//turnLeft45();
			//turnStreat();
			//turnBack();
			//turnRight90();
			//turnStreat();
			//turnBack();
			//turnRight90();
			//turnStreat();
			//turnBack();
			//turnRight90();
			//turnStreat();
			//turnBack();
			//turnLeft90();
			//turnLeft45();
		 }
		}


//task rij(){
//	while(true){
//		int en = nMotorEncoder[MotorRechts] + 70;
//		nMotorEncoderTarget[MotorRechts] = en;
//		motor[MotorRechts] = speed;												//rij met een speed van 40 rechtdoor
//		motor[MotorLinks] = speed;
//		while(nMotorEncoder[MotorRechts] != en){
//				if(SensorValue[LichtL] > max_light && SensorValue[LichtR] > max_light){     // lijn is kwijtgeraakt er wordt veel wit gezien
//					playSound(soundBeepBeep);
//					stopTask(rij);
//					startTask(zoek);
//  	}

//	}
// }
//}

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
	while(nMotorEncoder[MotorRechts] != en){
			//if(SensorValue[LichtL] < min_light){     // lijn is gevonden
			//stopTask(zoek);
			//playSound(soundBeepBeep);
			////startTask(rij);
   //}
  }
}

void turnRight90(void)                         // 90 graden bocht
{
	int en = nMotorEncoder[MotorLinks] + 370;
	nMotorEncoderTarget[MotorLinks] = en;
	motor[MotorLinks] = 50;
	motor[MotorRechts] = -20;
	while(nMotorEncoder[MotorLinks] != en){
			//if(SensorValue[LichtL] < min_light){     // lijn is gevonden
			//stopTask(zoek);
			//playSound(soundBeepBeep);
			////startTask(rij);
   //}
	}
}

void turnLeft90(void)
{
	int en = nMotorEncoder[MotorRechts] + 250;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = 50;
	motor[MotorLinks] = -40;
	while(nMotorEncoder[MotorRechts] != en){
		//if(SensorValue[LichtL] < min_light){     // lijn is gevonden
		//	stopTask(zoek);
		//	playSound(soundBeepBeep);
		//	//startTask(rij);
  // }
	}
}

void turnStreat(void)
{
	int en = nMotorEncoder[MotorRechts] + 150;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = forwardSpeed;												//rij met een speed van 20 rechtdoor
	motor[MotorLinks] = forwardSpeed;
	while(nMotorEncoder[MotorRechts] != en){
		//if(SensorValue[LichtL] < min_light){     // lijn is gevonden
		//	stopTask(zoek);
		//	playSound(soundBeepBeep);
		//	//startTask(rij);
  // }
	}
}

void turnBack(void)
{
	int en = nMotorEncoder[MotorRechts] + 70;
	nMotorEncoderTarget[MotorRechts] = en;
	motor[MotorRechts] = backwardSpeed;    // rij met een speed van 20 achteruit
	motor[MotorLinks] = backwardSpeed;
  while(nMotorEncoder[MotorRechts] != en){
	 //if(SensorValue[LichtL] < min_light){     // lijn is gevonden
		//	stopTask(zoek);
		//	playSound(soundBeepBeep);
		//	//startTask(rij);
  // }
	}
}


task main()
{
		//min_light = SensorValue[LichtL];
		//max_light = SensorValue[LichtR];
		startTask(zoek);

}


//als sensors geen input hebben dus beiden wit

//rij stukje naar achter (als er geen lijn aanwezig is na het naar achter rijden

//rij dan in alle richtingen langzaam een stukje naar voren
//als lijn niet gevonden terug naar het midden en
