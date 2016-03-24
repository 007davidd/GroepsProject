package muffininc.legomindstormsmarch23;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.util.Log;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.UUID;

public class bth  {
    final String nxt1 = "00:16:53:18:BC:50";
    BluetoothAdapter localAdapter;
    BluetoothSocket socket_nxt1;
    BluetoothSocket socket_nxt2;
    boolean success = false;

    public bth() {
    }

    public int enableBT() {
        this.localAdapter = BluetoothAdapter.getDefaultAdapter();
        if(!this.localAdapter.isEnabled()) {
            this.localAdapter.enable();

            while(!this.localAdapter.isEnabled()) {
                ;
            }

        }
        return 1;
    }

    public boolean connectToNXTs() {
        BluetoothDevice nxt_1 = this.localAdapter.getRemoteDevice("00:16:53:18:BC:50");

        try {
            this.socket_nxt1 = nxt_1.createRfcommSocketToServiceRecord(UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"));
            this.socket_nxt1.connect();
            this.success = true;
        } catch (IOException var3) {
            Log.d("Bluetooth", "Err: Device not found or cannot connect");
            this.success = false;
        }

        return this.success;
    }

    public int writeMessage(byte msg, String nxt) throws InterruptedException {
        BluetoothSocket connSock;
        if(nxt.equals("nxt2")) {
            connSock = this.socket_nxt2;
        } else if(nxt.equals("nxt1")) {
            connSock = this.socket_nxt1;
        } else {
            connSock = null;
        }

        if(connSock != null) {
            try {
                OutputStreamWriter e = new OutputStreamWriter(connSock.getOutputStream());
                e.write(msg);
                e.flush();
                Thread.sleep(1000L);
            } catch (IOException var5) {
                var5.printStackTrace();
            }
        }
        return 1;
    }

    public int readMessage(String nxt) {
        BluetoothSocket connSock;
        if(nxt.equals("nxt2")) {
            connSock = this.socket_nxt2;
        } else if(nxt.equals("nxt1")) {
            connSock = this.socket_nxt1;
        } else {
            connSock = null;
        }

        if(connSock != null) {
            try {
                InputStreamReader e = new InputStreamReader(connSock.getInputStream());
                int n = e.read();
                return n;
            } catch (IOException var5) {
                var5.printStackTrace();
                return -1;
            }
        } else {
            return -1;
        }
    }
}
