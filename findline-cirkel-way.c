#pragma config(Sensor, S1,     Bumper,         sensorNone)
#pragma config(Sensor, S2,     Sonar,          sensorSONAR)
#pragma config(Sensor, S3,     LichtR,         sensorLightActive)
#pragma config(Sensor, S4,     LichtL,         sensorLightActive)
#pragma config(Motor,  motorA,          MotorLinks,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          MotorRechts,   tmotorNXT, PIDControl)


void Circle (int Lspeed, float Omtrek);

int count = 0;                                      //debug
int offset = 45;																		// offset zwarte lijn
int Lspeed = 10;																		//init speed linker wiel
float Omtrek = 2500;																//init omtrek cirkel
int lijn = 0;


task rij(){
			motor[MotorRechts] = 30;											//rij met een speed van 30 rechtdoor
			motor[MotorLinks] = 30;
			while(true);
}

task circle()
{
	while(true){

		Circle(Lspeed,Omtrek);                          //aanroep functie die motor aanstuurt controle komt terug na 1 rondje
		Omtrek = Omtrek * 1.3;													// de omtrek van de cirkel word per ronde met 1,3 vermenigvuldigd
		if(Omtrek > 5000){ 															// als deze grens overschreden word dan wordt de omtrek gelijk gemaakt aan een vaste waarde
			Omtrek = 4700;
		}

		Lspeed = Lspeed + 10;       										//de snelheid van het linker wiel word wer per ronde met 10 verhoogd tot dat de grens van 35+ overschreden is
		if(Lspeed > 35)
		{
			Lspeed = 35;
		}
		 count++;																				//debug tel aantal gereden rondjes

	}

}

task start()
{
	stopTask(circle);
	startTask(rij);
}																										//test functie stopcirkel start // auto



void Circle(int Lspeed, float Omtrek)
{

	int en = nMotorEncoder[MotorRechts] + Omtrek;
	motor[MotorRechts] = 50;
	motor[MotorLinks] = Lspeed;												//speed linker wiel moet varieren om langere of kortere bocht te krijgen
	while(nMotorEncoder[MotorRechts] < en)						//while motor nog niet de omtrek heeft afgelegd
	{
		if(SensorValue[LichtL] < offset)            	  //if tijdens het rond rijden en zoeken naar de lijn de lijn gevonden word stop dan alles en start de task rij auto
		{																							  // aangezien de sensor op de lijn zit kan de auto functie direct overnemen
			playSound(soundBeepBeep);
			motor[MotorRechts] = 0;
			motor[MotorLinks] = 0;
			lijn = 1;                                	   // variabele die doorgeeft dat de lijn gelezen aan de code buiten de while loop
		}
		break;
	}
	if(lijn == 1)
	{
		lijn = 0;
		startTask(start);
  }
}








task main()
{
	nMotorEncoder[MotorRechts] = 0;
	startTask(circle);

	while(true);
}
