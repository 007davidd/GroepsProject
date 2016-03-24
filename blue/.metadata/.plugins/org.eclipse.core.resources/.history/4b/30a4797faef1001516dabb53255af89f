package bluetooth;
import bth;


public class bt {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		enableBT();				
		connectToNXTs();
		
		byte [] stuur = new byte[] {(byte)0x01,(byte)0x9B,(byte)0x00,(byte)0x00,(byte)0x80,(byte)0x00,(byte)0x00,(byte)0xA4,	
							(byte)0x00,(byte)0x01,(byte)0x14,(byte)0xA6,(byte)0x00,(byte)0x01};
				
				
				
		

		
		for(int i = 0; i < 14; i++){
			writeMessage(stuur[i], "nxt1");
		
		}
		
		int ontvang = readMessage("nxt1");
		System.out.println(ontvang);
		
		
	}

}
