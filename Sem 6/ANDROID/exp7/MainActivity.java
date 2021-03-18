package com.example.exno7;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
    Button btnShowLocation;
    GPStrace gps;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        btnShowLocation = (Button) findViewById(R.id.show_Location);
        btnShowLocation.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                gps = new GPStrace(GPSlocationActivity.this);
                if (gps.canGetLocation()) {
                    double latitude = gps.getLatitude();
                    double longitude = gps.getLongtiude();
                    Toast.makeText(getApplicationContext(), "Your Location is \nLat:" + latitude + "\nLong:" + longitude, Toast.LENGTH_LONG).show();
                } else {
                    gps.showSettingAlert();
                }

            }

        });

    }
}




