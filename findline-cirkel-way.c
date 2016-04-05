#pragma config(Sensor, S1,     Bumper,         sensorNone)
#pragma config(Sensor, S2,     Sonar,          sensorSONAR)
#pragma config(Sensor, S3,     LichtR,         sensorLightActive)
#pragma config(Sensor, S4,     LichtL,         sensorLightActive)
#pragma config(Motor,  motorA,          MotorLinks,    tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,          MotorRechts,   tmotorNXT, PIDControl)

void start(void);
void Circle (int Lspeed, float Omtrek);

int count = 0;
int offset = 45;
int Lspeed = 10;
float Omtrek = 2500;

task rij(){

			motor[MotorRechts] = 30;												//rij met een speed van 40 rechtdoor
			motor[MotorLinks] = 30;
			while(true);
}

task circle()
{
	while(true){

		Circle(Lspeed,Omtrek);
		Omtrek = Omtrek * 1.3;
		if(Omtrek > 5000){
			Omtrek = 4700;
		}

		Lspeed = Lspeed + 10;
		if(Lspeed > 35){
			Lspeed = 35;
		}
		count++;

	}

}

void start(void){
	stopTask(circle);
	startTask(rij);
}


void Circle(int Lspeed, float Omtrek)
{

	int en = nMotorEncoder[MotorRechts] + Omtrek;
	motor[MotorRechts] = 50;													//speed moet varieren om langere of kortere bocht te krijgen
	motor[MotorLinks] = Lspeed;
	while(nMotorEncoder[MotorRechts] < en)
	{
		if(SensorValue[LichtL] < offset)
		{
			playSound(soundBeepBeep);
			motor[MotorRechts] = 0;
			motor[MotorLinks] = 0;
			   //stopTask(circle);
				//startTask(rij)
			start();
		}
	}
}








task main()
{
	nMotorEncoder[MotorRechts] = 0;
	startTask(circle);

	while(true);
}






//functie moet een halve cirkel van een bepaalde diameter kunnen draaien
// deze diameter moet kunnen varieren
