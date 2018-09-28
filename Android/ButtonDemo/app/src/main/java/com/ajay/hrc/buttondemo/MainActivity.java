package com.ajay.hrc.buttondemo;

import android.annotation.SuppressLint;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    Button b,b1;
    RelativeLayout rl;
    TextView t;
    Random r=new Random();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b= (Button)findViewById(R.id.button2);
        b1=(Button)findViewById(R.id.button);
        t=(TextView)findViewById(R.id.tv);
        rl=(RelativeLayout)findViewById(R.id.rl);

    }
    public void foreground(View v1)
    {

        int n=r.nextInt();
        b1.setBackgroundColor(n);
        b.setBackgroundColor(n);
        t.setBackgroundColor(n);
        Toast.makeText(this,"Fore ",Toast.LENGTH_SHORT).show();

    }
    public void background(View v2)
    {
        rl.setBackgroundColor(r.nextInt());
        Toast.makeText(this,"Back ",Toast.LENGTH_SHORT).show();
    }
}
