package bluetooth;


import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.UUID;


import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import android.util.Log;

 public class bth {

//Target NXTs for communication

final String nxt1 = "00:16:53:18:BC:50";

BluetoothAdapter localAdapter;
BluetoothSocket socket_nxt1,socket_nxt2;
boolean success=false;



//Enables Bluetooth if not enabled
public void enableBT(){
    localAdapter=BluetoothAdapter.getDefaultAdapter();
    //If Bluetooth not enable then do it
    if(localAdapter.isEnabled()==false){
        localAdapter.enable();
        while(!(localAdapter.isEnabled())){

        }
    }

}

//connect to both NXTs
public  boolean connectToNXTs(){



    //get the BluetoothDevice of the NXT
    //BluetoothDevice nxt_2 = localAdapter.getRemoteDevice(nxt2);
    BluetoothDevice nxt_1 = localAdapter.getRemoteDevice(nxt1);
    //try to connect to the nxt
    try {
       // socket_nxt2 = nxt_2.createRfcommSocketToServiceRecord(UUID
               // .fromString("00001101-0000-1000-8000-00805F9B34FB"));


        socket_nxt1 = nxt_1.createRfcommSocketToServiceRecord(UUID
                .fromString("00001101-0000-1000-8000-00805F9B34FB"));


          //  socket_nxt2.connect();



            socket_nxt1.connect();


        success = true;



    } catch (IOException e) {
        Log.d("Bluetooth","Err: Device not found or cannot connect");
        success=false;


    }
    return success;

}


public void writeMessage(byte msg, String nxt) throws InterruptedException{
    BluetoothSocket connSock;

    //Swith nxt socket
    if(nxt.equals("nxt2")){
        connSock=socket_nxt2;
    }else if(nxt.equals("nxt1")){
        connSock=socket_nxt1;
    }else{
        connSock=null;
    }

    if(connSock!=null){
        try {

            OutputStreamWriter out=new OutputStreamWriter(connSock.getOutputStream());
            out.write(msg);
            out.flush();

            Thread.sleep(1000);


        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }else{
        //Error
    }
}

public int readMessage(String nxt){
    BluetoothSocket connSock;
    int n;
    //Swith nxt socket
    if(nxt.equals("nxt2")){
        connSock=socket_nxt2;
    }else if(nxt.equals("nxt1")){
        connSock=socket_nxt1;
    }else{
        connSock=null;
    }

    if(connSock!=null){
        try {

            InputStreamReader in=new InputStreamReader(connSock.getInputStream());
            n=in.read();

            return n;


        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            return -1;
        }
    }else{
        //Error
        return -1;
    }

}

}