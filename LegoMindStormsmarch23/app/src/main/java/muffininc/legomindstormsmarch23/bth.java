package muffininc.legomindstormsmarch23;


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

    final String nxt = "00:16:53:18:BC:50";

    BluetoothAdapter localAdapter;
    BluetoothSocket socket_nxt;
    boolean success = false;


    //Enables Bluetooth if not enabled
    public boolean enableBT() {
        localAdapter = BluetoothAdapter.getDefaultAdapter();
        //If Bluetooth not enable then do it
        if (!localAdapter.isEnabled()) {
            localAdapter.enable();
            while (!(localAdapter.isEnabled())) {

            }
        }
        return true;
    }

    //connect to both NXTs
    public boolean connectToNXTs() {


        //get the BluetoothDevice of the NXT
        BluetoothDevice nxt_1 = localAdapter.getRemoteDevice(nxt);
        //try to connect to the nxt
        try {

            socket_nxt = nxt_1.createRfcommSocketToServiceRecord(UUID
                    .fromString("00001101-0000-1000-8000-00805F9B34FB"));


            //  socket_nxt2.connect();


            socket_nxt.connect();


            success = true;


        } catch (IOException e) {
            Log.d("Bluetooth", "Err: Device not found or cannot connect");
            success = false;


        }
        return success;

    }


    public boolean writeMessage(byte[] msg) throws InterruptedException {
        BluetoothSocket connSock = socket_nxt;

        if (connSock != null) {
            try {

                OutputStreamWriter out = new OutputStreamWriter(connSock.getOutputStream());
                for (int i = 0; i < 14; i++) {
                    out.write(msg[i]);
                }
                out.flush();

                Thread.sleep(1000);

                return true;

            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
                return false;
            }
        } else {
            //Error
            return false;
        }
    }

    public boolean readMessage() {
        BluetoothSocket connSock;
        int n;

        connSock = socket_nxt;

        if (connSock != null) {
            try {

                InputStreamReader in = new InputStreamReader(connSock.getInputStream());
                n = in.read();

                if (n > 0) {
                    return true;
                }
                return false;

            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
                return false;
            }
        } else {
            //Error
            return false;
        }

    }

}