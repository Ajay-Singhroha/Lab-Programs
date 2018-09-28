package com.ajay.hrc.veg_nonveg;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements RadioGroup.OnCheckedChangeListener{
RadioGroup rg;
RadioButton veg,non;
CheckBox c1,c2,c3,c4,c5,c6,c7,c8;
TextView tv1,order;
Button b;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        rg=findViewById(R.id.rg);
        veg=findViewById(R.id.veg);
        non=findViewById(R.id.nonveg);
        c1=findViewById(R.id.cb1);
        c2=findViewById(R.id.cb2);
        c3=findViewById(R.id.cb3);
        c4=findViewById(R.id.cb4);
        c5=findViewById(R.id.cb5);
        c6=findViewById(R.id.cb6);
        c7=findViewById(R.id.cb7);
        c8=findViewById(R.id.cb8);
        tv1=findViewById(R.id.tv);
        order=findViewById(R.id.order);
        b=findViewById(R.id.button);
        c1.setVisibility(View.INVISIBLE);
        c2.setVisibility(View.INVISIBLE);
        c3.setVisibility(View.INVISIBLE);
        c4.setVisibility(View.INVISIBLE);
        c5.setVisibility(View.INVISIBLE);
        c6.setVisibility(View.INVISIBLE);
        c7.setVisibility(View.INVISIBLE);
        c8.setVisibility(View.INVISIBLE);
        b.setVisibility(View.INVISIBLE);
        order.setVisibility(View.INVISIBLE);
        rg.setOnCheckedChangeListener(this);
       // veg.setOnCheckedChangeListener(this);
       // non.setOnCheckedChangeListener(this);
    }

    @Override
    public void onCheckedChanged(RadioGroup group, int checkedId) {
        if(group.getId()==R.id.rg)
        {

                c1.setVisibility(View.VISIBLE);
                c2.setVisibility(View.VISIBLE);
                c3.setVisibility(View.VISIBLE);
                c4.setVisibility(View.VISIBLE);
                c5.setVisibility(View.VISIBLE);
                c6.setVisibility(View.VISIBLE);
                c7.setVisibility(View.VISIBLE);
                c8.setVisibility(View.VISIBLE);
                order.setVisibility(View.VISIBLE);
                b.setVisibility(View.VISIBLE);
            if(checkedId==R.id.veg)
            {
                   c1.setText(R.string.v1);
                c2.setText(R.string.v2);
                c3.setText(R.string.v3);
                c4.setText(R.string.v4);
                c5.setText(R.string.v5);
                c6.setText(R.string.v6);
                c7.setText(R.string.v7);
                c8.setText(R.string.v8);

            }
            else if(checkedId==R.id.nonveg)
            {
                c1.setText(R.string.n1);
                c2.setText(R.string.n2);
                c3.setText(R.string.n3);
                c4.setText(R.string.n4);
                c5.setText(R.string.n5);
                c6.setText(R.string.n6);
                c7.setText(R.string.n7);
                c8.setText(R.string.n8);

            }
        }
    }
}
