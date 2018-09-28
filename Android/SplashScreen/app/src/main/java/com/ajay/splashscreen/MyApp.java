package com.ajay.splashscreen;

import android.app.Application;
import android.os.SystemClock;

public class MyApp extends Application {

    public void onCreate()
    {
        super.onCreate();
        SystemClock.sleep(1500);
    }
}
