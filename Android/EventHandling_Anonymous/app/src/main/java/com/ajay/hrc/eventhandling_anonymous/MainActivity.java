package com.ajay.hrc.eventhandling_anonymous;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.view.View.OnClickListener;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    TextView tv;
    Button btn,btn2;
    RelativeLayout rl;
    Random r=new Random();
    int count=0,count1=0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn=(Button)findViewById(R.id.button1);
        btn2=(Button)findViewById(R.id.button2);
        tv=(TextView)findViewById(R.id.textview);
        rl=(RelativeLayout)findViewById(R.id.rlt);
        btn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                count++;
                tv.setText("Background Color Changed "+count+" times");
                rl.setBackgroundColor((int)r.nextInt());


            }
        });
        btn2.setOnClickListener(new OnClickListener() {
            @Override

            public void onClick(View view) {
                count1++;
                tv.setText("ForeGround Color Changed "+count1+ " times ");
                tv.setBackgroundColor((int)r.nextInt());
                btn.setBackgroundColor((int)r.nextInt());
                btn2.setBackgroundColor((int)r.nextInt());



            }
        });
    }

}
