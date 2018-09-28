package com.ajay.splashscreen;

import android.content.Intent;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;

public class SplashScreen extends AppCompatActivity {

    @Override
    public void onCreate(   Bundle savedInstanceState ) {
        super.onCreate(savedInstanceState);
        Intent intent=new Intent(SplashScreen.this, MainActivity.class);
        startActivity(intent);
        SplashScreen.this.finish();
    }
}
