package com.example.omkar.project_du;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.ViewFlipper;

// This is the Second Activity
public class HansrajActivity extends AppCompatActivity implements View.OnClickListener {

    TextView Clicktxt,hansrajtxt;
    ImageButton hansrajlocation;
    ViewFlipper hansraj_flipper;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hansraj);
        Clicktxt = findViewById(R.id.clicktext);
        hansrajtxt = findViewById(R.id.locateHansrajtext);
        hansrajlocation = findViewById(R.id.Hansrajlocation);
        hansraj_flipper = findViewById(R.id.hansajslide);
        hansrajlocation.setOnClickListener(this);

        int image[] = {R.drawable.path, R.drawable.hansrajslide2,R.drawable.hansrajslide3,R.drawable.hansrajslide4};

        for(int imageloop: image){
            flipperImage(imageloop);
        }
    }

    public void flipperImage(int image){

        ImageView imageView = new ImageView(this);
        imageView.setBackgroundResource(image);

        hansraj_flipper.addView(imageView);
        hansraj_flipper.setFlipInterval(3000);
        hansraj_flipper.setAutoStart(true);

        hansraj_flipper.setInAnimation(this,android.R.anim.fade_in);
        hansraj_flipper.setOutAnimation(this, android.R.anim.fade_out);


    }

    @Override
    public void onClick(View v) {
        if(v.getId()==R.id.Hansrajlocation){
            Intent viewhansrajloc = new Intent(Intent.ACTION_VIEW,Uri.parse("geo:28°40'50.5\"N 77°12'34.9\"E"));
            startActivity(viewhansrajloc);
        }
    }
}
