package com.example.ajay.login;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.io.IOException;

public class LoginActivity extends AppCompatActivity {

    EditText user, pass;
    String s;
    Button login;
    TextView lrtv,lwrong;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        Intent intent = this.getIntent();
        if (intent != null) {
            String from = intent.getStringExtra("from");
            lrtv = findViewById(R.id.lrtv);
            lwrong=findViewById(R.id.lwrong);

            if (from.equals("from register")) {
                lrtv.setVisibility(View.VISIBLE);
            }
        }
        user = findViewById(R.id.luseret);
        pass = findViewById(R.id.lpasset);
        login = findViewById(R.id.loginbutton);
        user.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {
                    s = user.getText().toString();
                    if (s.equalsIgnoreCase("")) {
                        user.setError("Username is Mandatory");
                        return true;
                    }
                }
                return false;
            }
        });
        pass.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {

                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {
                    s = pass.getText().toString();
                    if (s.length() < 8) {
                        pass.setError("Invalid Password");
                        return true;
                    }
                }
                return false;
            }
        });
        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (checkForInput()) {
                    s=user.getText().toString();
                    FileHandling file = new FileHandling();

                        boolean isUser = file.check(s);

                        if(isUser)
                        {
                            s=pass.getText().toString();
                            boolean ispass=file.check(s);
                            if(ispass)
                            {
                                Intent intent1=new Intent(getApplicationContext(),Order.class);
                                startActivity(intent1);
                            }
                            else
                            {
                                lwrong.setVisibility(View.VISIBLE);
                            }
                        }
                        else
                            lwrong.setVisibility(View.VISIBLE);




                }
            }
        });
    }

    boolean checkForInput() {
        String s1;

        s1 = user.getText().toString();
        if (s1.equalsIgnoreCase("")) {
            user.setError("Username is Mandatory");
            return false;
        }

        s1 = pass.getText().toString();
        if (s1.length() < 8) {
            pass.setError("Invalid Password");
            return false;
        }

        return true;
    }
}
