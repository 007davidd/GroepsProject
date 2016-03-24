package muffininc.legomindstormsmarch23;

import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;


public class MainActivity extends AppCompatActivity {

    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;
    public static bth btj = new bth();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();
        Button bluetooth_button = (Button)findViewById(R.id.bluetooth_button);
        Button one_button = (Button)findViewById(R.id.one_button);
        Button front_button = (Button)findViewById(R.id.front_button);
        Button back_button = (Button)findViewById(R.id.back_button);
        Button left_button = (Button)findViewById(R.id.left_button);
        Button right_button = (Button)findViewById(R.id.right_button);
        //MainActivity bth  = new MainActivity();




        bluetooth_button.setOnClickListener(
                new Button.OnClickListener(){
                    public void onClick(View v) {
                        TextView bluetoothproof1 = (TextView) findViewById(R.id.bluetoothproof1);
                        TextView bluetoothproof2 = (TextView) findViewById(R.id.bluetoothproof2);
                        TextView bluetoothproof3 = (TextView) findViewById(R.id.bluetoothproof3);
                        TextView bluetoothproof4 = (TextView) findViewById(R.id.bluetoothproof4);
                        btj.enableBT();
                            if (btj.enableBT = 1){
                                bluetoothproof1.setText("BT enabled");
                            }

                            if (btj.connectToNXTs() == true) {
                                bluetoothproof2.setText("NXT connected");
                            }
                            else {
                                bluetoothproof2.setText("NXT not connected");
                            }

                            if (btj.writeMessage(byte msg, String nxt) == 1) {
                                bluetoothproof3.setText("Message written");
                            }

                        btj.readMessage(String nxt);
                            if (btj.readMessage = -1) {
                                bluetoothproof2.setText("Message read");
                            }

                        TextView StatusSign = (TextView) findViewById(R.id.StatusSign);
                        StatusSign.setText("It's blue tooth");
                    }
                }

        );

        one_button.setOnClickListener(
                new Button.OnClickListener(){
                   public void onClick(View v) {
                    TextView StatusSign = (TextView)findViewById(R.id.StatusSign);
                       StatusSign.setText("Hey look you pressed it! Sucker!");

                   }
                }
        );


    front_button.setOnClickListener(
            new Button.OnClickListener(){
        public void onClick(View v) {
            TextView StatusSign = (TextView)findViewById(R.id.StatusSign);
            StatusSign.setText("Forward March!");
        }
    }
    );
    back_button.setOnClickListener(
            new Button.OnClickListener(){
        public void onClick(View v) {
            TextView StatusSign = (TextView)findViewById(R.id.StatusSign);
            StatusSign.setText("Back It Up");
        }
    }
    );
    left_button.setOnClickListener(
            new Button.OnClickListener(){
        public void onClick(View v) {
            TextView StatusSign = (TextView)findViewById(R.id.StatusSign);
            StatusSign.setText("To the Left To the Left!");
        }
    }
    );
    right_button.setOnClickListener(
            new Button.OnClickListener(){
        public void onClick(View v) {
            TextView StatusSign = (TextView)findViewById(R.id.StatusSign);
            StatusSign.setText("Forward March!");
        }
    }
    );
}

    public boolean onCreateOptionMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public void onStart() {
        super.onStart();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client.connect();
        Action viewAction = Action.newAction(
                Action.TYPE_VIEW, // TODO: choose an action type.
                "Main Page", // TODO: Define a title for the content shown.
                // TODO: If you have web page content that matches this app activity's content,
                // make sure this auto-generated web page URL is correct.
                // Otherwise, set the URL to null.
                Uri.parse("http://host/path"),
                // TODO: Make sure this auto-generated app deep link URI is correct.
                Uri.parse("android-app://muffininc.legomindstormsmarch23/http/host/path")
        );
        AppIndex.AppIndexApi.start(client, viewAction);
    }

    @Override
    public void onStop() {
        super.onStop();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        Action viewAction = Action.newAction(
                Action.TYPE_VIEW, // TODO: choose an action type.
                "Main Page", // TODO: Define a title for the content shown.
                // TODO: If you have web page content that matches this app activity's content,
                // make sure this auto-generated web page URL is correct.
                // Otherwise, set the URL to null.
                Uri.parse("http://host/path"),
                // TODO: Make sure this auto-generated app deep link URI is correct.
                Uri.parse("android-app://muffininc.legomindstormsmarch23/http/host/path")
        );
        AppIndex.AppIndexApi.end(client, viewAction);
        client.disconnect();
    }
}