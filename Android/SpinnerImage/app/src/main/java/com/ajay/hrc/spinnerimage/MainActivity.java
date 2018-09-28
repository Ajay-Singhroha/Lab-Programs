package com.ajay.hrc.spinnerimage;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {
    Spinner s;
    TextView tv;
    ImageView i;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        s = findViewById(R.id.spinner);
        tv = findViewById(R.id.textView);
        i = findViewById(R.id.imageView);

        ArrayAdapter<CharSequence> arrayAdapter = ArrayAdapter.createFromResource(this, R.array.countries, R.layout.support_simple_spinner_dropdown_item);
        arrayAdapter.setDropDownViewResource(R.layout.support_simple_spinner_dropdown_item);
        s.setAdapter(arrayAdapter);
        s.setOnItemSelectedListener(this);
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        if (parent.getId() == R.id.spinner) {
            switch (position) {
                case 0:
                    tv.setText("Flag of United Kingdom");
                    i.setImageResource(R.drawable.uk);

                    break;
                case 1:
                    tv.setText("Flag of Canada");

                    i.setImageResource(R.drawable.canada);
                    break;
                case 2:
                    tv.setText("Flag of Australia");

                    i.setImageResource(R.drawable.australia);
                    break;
                case 3:
                    tv.setText("Flag of Bangladesh");

                    i.setImageResource(R.drawable.bangladesh);
                    break;
                case 4:
                    tv.setText("Flag of China");

                    i.setImageResource(R.drawable.china);
                    break;
            }
        }


    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
}
