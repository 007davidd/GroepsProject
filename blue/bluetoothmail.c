#pragma config (Motor, motorA, motorLinks, tmotorNXT, openLoop, encoder)
#pragma config (Motor, motorB, motorIets, tmotorNXT, openLoop)
#pragma config (Motor, motorC, motorRechts, tmotorNXT, openLoop)

task stoprij(){
			motor[motorLinks] = 0;
			motor[motorRechts] = 0;
			wait1Msec(100);

}

task vooruit(){
			motor[motorLinks] = 20;
			motor[motorRechts] = 20;
			wait1Msec(100);
}

task achteruit(){
			motor[motorLinks] = -20;
			motor[motorRechts] = -20;
			wait1Msec(100);
}

task links(){
			motor[motorLinks] = -20;
			motor[motorRechts] = 20;
			int TimeL = 0;
			while(TimeL < 10){       //om naar links en naar rechts te draaien moeten de motors maar een bepaalde tijd draaien
					TimeL++;							//hiervoor heb ik gekozen voor een while loop die 10x 100ms wachts voordat de task wordt stopgezet
					wait1Msec(100);			//dit is natuurlijk fine te tunen
		 }
			stopTask(links);

}

task rechts(){
			motor[motorLinks] = 20;
			motor[motorRechts] = -20;
			int TimeR = 0;
			while(TimeR < 10){
					TimeR++;
					wait1Msec(100);
		 }
			stopTask(links);
}

task main(){
	int mailbox = 5;


		//initialiseer display door alles leeg te maken

		eraseDisplay();
		wait1Msec(100);

		while(1){
				string buffer, message="";
				int result;

				eraseDisplay();

				// lees mailbox
				int a = cCmdMessageGetSize(mailbox);  //haal de hoeveel bytes in eerst volgende bericht
				if(a){
					result = cCmdMessageRead(buffer, a, mailbox); // lees aantal bytes a in en plaats ze in buffer
					nxtDisplayString(1, "result = %d", result);
				}
					nxtDisplayString(2, "msg: %s", message);

				if(message == "up"){
					stopTask(stoprij);			 //voor het aanroepen van een nieuwe task via de app
					stopTask(links);  				//sluiten we eerst alle andere task die via de app aangeroepen kunnen worden
					stopTask(rechts);
					stopTask(achteruit);
					startTask(vooruit);
					wait1Msec(100);

				}

				else if(message == "down"){
					stopTask(stoprij);
					stopTask(links);
					stopTask(rechts);
					stopTask(vooruit);
					startTask(achteruit);
					wait1Msec(100);

				}

				else if(message == "left"){
					stopTask(stoprij);
					stopTask(vooruit);
					stopTask(rechts);
					stopTask(achteruit);
					startTask(links);


				}

				else if (message == "right"){
					stopTask(stoprij);
					stopTask(links);
					stopTask(vooruit);
					stopTask(achteruit);
					startTask(rechts);


				}

				else if(message == "stop"){
					stopTask(stoprij);
					stopTask(links);
					stopTask(rechts);
					stopTask(achteruit);
					stopTask(vooruit);
					startTask(stoprij);
					wait1Msec(100);

				 }
				 else{
				   nxtDisplayString(3, "Err msg: %s", message); //mocht messge onjuist zijn dan print message op het lcd
				}

				wait1Msec(100);
		}

}
