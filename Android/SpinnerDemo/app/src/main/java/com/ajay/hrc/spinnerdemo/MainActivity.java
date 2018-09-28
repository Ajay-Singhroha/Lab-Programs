package com.ajay.hrc.spinnerdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Adapter;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView;
import android.widget.Toast;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener ,View.OnKeyListener{

    String states[]={"Delhi","Haryana","Punjab","Goa","Kerala","Bihar","Other"};
    String cities[]={"Gurugram","Lucknow","Jaipur","Shimla","Rohtak","Pune","Other"};
    ArrayAdapter<String> adapter,adapterr;
    ArrayList<String> arrayListState,arrayListCity;
    Spinner s1,s2;
    String string ,city,state;
    EditText et1,et2;
    TextView tv1,tv2,tv3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        s1=findViewById(R.id.s1);
        s2=findViewById(R.id.s2);
        et1=findViewById(R.id.et1);
        et2=findViewById(R.id.et2);
        tv1=findViewById(R.id.tv1);
        tv2=findViewById(R.id.tv2);
        tv3=findViewById(R.id.tv3);
        et1.setVisibility(View.INVISIBLE);
        et2.setVisibility(View.INVISIBLE);
        et1.setOnKeyListener(this);
        et2.setOnKeyListener(this);
        arrayListState=new ArrayList<>(Arrays.asList(states));
        adapter=new ArrayAdapter<>(this,android.R.layout.simple_spinner_item,arrayListState);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        arrayListCity=new ArrayList<>(Arrays.asList(cities));
        adapterr=new ArrayAdapter<>(this,android.R.layout.simple_spinner_item,arrayListCity);
        adapterr.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        s1.setAdapter(adapter);
        s2.setAdapter(adapterr);
        s1.setOnItemSelectedListener(this);
        s2.setOnItemSelectedListener(this);
    }

    @Override
    public void onItemSelected(AdapterView<?> adapterView, View view, int pos, long id) {
        if (adapterView.getId() == R.id.s1) {
            state = et1.getText().toString();
            et1.setVisibility(View.INVISIBLE);
            if (adapterView.getItemAtPosition(pos).toString().equals("Other")) {
                et1.setVisibility(View.VISIBLE);
                Toast.makeText(this, "Press Enter once Done ", Toast.LENGTH_SHORT).show();
            } else
                state = adapterView.getItemAtPosition(pos).toString();
        } else {
            if (adapterView.getId() == R.id.s2) {
                city = et2.getText().toString();
                et2.setVisibility(View.INVISIBLE);
                if (adapterView.getItemAtPosition(pos).toString().equals("Other")) {
                    et2.setVisibility(View.VISIBLE);
                    Toast.makeText(this, "Press Enter once Done ", Toast.LENGTH_SHORT).show();
                }
                else
                    city = adapterView.getItemAtPosition(pos).toString();


            }
        }
        tv3.setText(state+city);
    }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }

            @Override
            public boolean onKey(View view, int i, KeyEvent keyEvent) {
                if(keyEvent.getKeyCode()==KeyEvent.KEYCODE_ENTER) {
                    state=et1.getText().toString();
                    city=et2.getText().toString();
                    // Toast.makeText(MainActivity.this, "Key Event", Toast.LENGTH_LONG).show();
                    if(!state.isEmpty())
                    {
                        arrayListState.add(arrayListState.size()-1,state);
                       et1.setText("");
                       et1.setVisibility(View.INVISIBLE);
                        Toast.makeText(this,"State added in Dropdown Menu",Toast.LENGTH_SHORT).show();
                    }
                    if(!city.isEmpty())
                    {
                        arrayListCity.add(arrayListCity.size()-1,city);
                        et2.setText("");
                        et2.setVisibility(View.INVISIBLE);
                        Toast.makeText(this,"City added in Dropdown Menu",Toast.LENGTH_SHORT).show();

                    }
                    if(!state.isEmpty()&&!city.isEmpty())
                        string=state+city;
                }
                return false;
            }
        }

