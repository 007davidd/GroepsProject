
#define pixels_per)char = 6

task main(){
		int loopnum = 0;

		//initialiseer display

		eraseDisplay();
		wait1Msec(2000);

    //displayBigStringAt(25, 25 "%s", pChar, ...);

		while(1){
				string buffer, message="";
				int result;

				eraseDisplay();
				nxtDisplayString(0, "bluetooth test %d", 0);
				nxtDisplayString(1, "weergeef mailbox 1");
				nxtDisplayString(2, "loopnumber %d", loopnum);


				// lees mailbox 1
				if(cCmdMessageGetSize(1)){
					  int a = cCmdMessageGetSize(1);          //haal de hoeveel bytes in eerst volgende bericht
					  result = cCmdMessageRead(buffer, a, 1); // lees aantal bytes a in en plaats ze in buffer
						ClearMessage();														// haal bericht uit de queue
						nxtDisplayString(3, "result = %d", result);

						if(result)
									message = buffer;
									// stuur iets terug als we dat zouden willen
									//sendMessage(3+10, message);
						}

				nxtDisplayString(4, "msg: %s", message);
				wait1Msec(1000);
				loopnum++;
			}

}
