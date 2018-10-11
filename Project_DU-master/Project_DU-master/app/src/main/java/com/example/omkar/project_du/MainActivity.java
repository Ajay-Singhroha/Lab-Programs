package com.example.omkar.project_du;

import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity  {

    Animation fromtop,frombottom;
    ImageView logo;
    private static int Splash_Time=4000;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                Intent homeintent = new Intent(MainActivity.this,HansrajActivity2.class);
                startActivity(homeintent);
                finish();

            }
        },Splash_Time);
        logo = findViewById(R.id.logo);

        fromtop = AnimationUtils.loadAnimation(this, R.anim.fromtop);
        frombottom=AnimationUtils.loadAnimation(this,R.anim.fromtop);
        logo.setAnimation(fromtop);

    }


    }

