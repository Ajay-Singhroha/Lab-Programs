package com.ajay.hrc.increment_decrement;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    TextView t;
    String s;int count=0;
    Button b1,b2,b3;
    EditText et;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        t=(TextView)findViewById(R.id.tv);
        b1=(Button)findViewById(R.id.button1);
        b2=(Button)findViewById(R.id.button2);
        et=(EditText)findViewById(R.id.editText);
        b3=(Button)findViewById(R.id.button3);
        b1.setOnClickListener(this);
        b2.setOnClickListener(this);
        b3.setOnClickListener(this);

    }


    @Override
    public void onClick(View view) {
        if(!et.getText().toString().equals(""))
        {
            if(view.getId()==R.id.button1)
            {
               count=Integer.parseInt(t.getText().toString()) + Integer.parseInt(et.getText().toString());
                t.setText(String.valueOf(count));
            }
            else if(view.getId()==R.id.button2){
                count=Integer.parseInt(t.getText().toString()) - Integer.parseInt(et.getText().toString());
                t.setText(String.valueOf(count));
            }

            else {
                count = 0;
                t.setText(String.valueOf(count));
                et.setText("");
            }
        }
        else
        {
            if(view.getId()==R.id.button1)
            {
                count=Integer.parseInt(t.getText().toString()) + 1;
                t.setText(String.valueOf(count));
            }
            else if(view.getId()==R.id.button2){
                count=Integer.parseInt(t.getText().toString()) - 1;
                t.setText(String.valueOf(count));
            }

            else {
                count = 0;

                t.setText(String.valueOf(String.valueOf(count)));

            }
        }
    }
}