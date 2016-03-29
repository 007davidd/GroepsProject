

task main(){
	int mailbox = 5;
		int loopnum = 0;

		//initialiseer display door alles leeg te maken

		eraseDisplay();
		wait1Msec(2000);

		while(1){
				string buffer, message="";
				int result;

				eraseDisplay();
				nxtDisplayString(0, "bluetooth test %d", 0);
				nxtDisplayString(1, "weergeef mailbox 1");
				nxtDisplayString(2, "loopnumber %d", loopnum);


				// lees mailbox
				int a = cCmdMessageGetSize(mailbox);  //haal de hoeveel bytes in eerst volgende bericht
				if(a){        
					result = cCmdMessageRead(buffer, a, mailbox); // lees aantal bytes a in en plaats ze in buffer
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
