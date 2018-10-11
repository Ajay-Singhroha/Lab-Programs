package com.ajay.text_to_speech;

import android.content.ActivityNotFoundException;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import android.speech.RecognizerIntent;
import android.content.Intent;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;
import  java.util.Locale;

public class MainActivity extends AppCompatActivity {

        Button b,b2;
        EditText et;
        TextToSpeech textToSpeech;
        TextView tv;
        private final int REQ_SPEECH_INPUT=100;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        b=findViewById(R.id.button);
        b2=findViewById(R.id.button2);
        tv.findViewById(R.id.text);

        et=findViewById(R.id.editText);

        textToSpeech = new TextToSpeech(getApplicationContext(), new TextToSpeech.OnInitListener() {
            @Override
            public void onInit(int status) {
                if(status== TextToSpeech.SUCCESS)
                {
                    int result = textToSpeech.setLanguage(Locale.UK);
                    if(result==TextToSpeech.LANG_NOT_SUPPORTED||result==TextToSpeech.LANG_MISSING_DATA)
                    {
                            Log.e("error","Language not supported ");

                    }
                    else
                    {
                        textToSpeech.speak("aa",TextToSpeech.QUEUE_FLUSH,null);
                    }
                }
                else
                    Log.e("error","initialization failed");
            }
        });

        b.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String s=et.getText().toString();
                textToSpeech.speak(s,TextToSpeech.QUEUE_FLUSH,null);
            }
        });
        b2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

               // startListening();
            }
        });
    }
    private void startListening() {
        Intent intent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);
        intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE, Locale.getDefault());
        intent.putExtra(RecognizerIntent.EXTRA_PROMPT, "How Can I help you?");

        try {
         //   startActivityForResult(intent, REQ_SPEECH_INPUT);
        } catch (ActivityNotFoundException a){
            Log.e("error","Error in listening");
        }
    }



   // @Override
   /* protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        switch(requestCode)
        {
            case REQ_SPEECH_INPUT:
                if(resultCode==RESULT_OK&& data!=null)
                {
                    ArrayList<String> arrayList=data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
                    tv.setText(arrayList.get(0));
                }
        }
    }*/
}
