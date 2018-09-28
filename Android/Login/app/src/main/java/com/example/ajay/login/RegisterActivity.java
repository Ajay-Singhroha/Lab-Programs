package com.example.ajay.login;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public  class RegisterActivity extends AppCompatActivity {

    EditText name, user, roll, email, mob, pass, conf;
    String array[];
    
    String s;
    Button register;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        name = findViewById(R.id.rnameet);
        user = findViewById(R.id.ruseret);
        roll = findViewById(R.id.rrollet);
        email = findViewById(R.id.remailet);
        mob = findViewById(R.id.rnoet);
        pass = findViewById(R.id.rpasset);
        conf = findViewById(R.id.rconfet);
        register = findViewById(R.id.registerbutton);
        name.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {
                    s = name.getText().toString();
                    if (s.equalsIgnoreCase("")) {
                        name.setError("Name is Mandatory");
                        return true;
                    }
                }
                return false;
            }
        });
        user.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {

                    s = user.getText().toString();
                    if (s.equalsIgnoreCase("")) {
                        user.setError("Username not Available");
                        return true;
                    }
                }
                return false;
            }
        });
        roll.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {

                    s = roll.getText().toString();
                    if (s.length() != 4) {
                        roll.setError("Invalid Roll No.");

                        return true;
                    }
                }
                return false;
            }
        });
        email.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {

                    s = email.getText().toString();
                    if (!validateEmailAddress(s)) {
                        email.setError("Invalid Email");
                        return true;
                    }
                }
                return false;
            }
        });
        mob.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {

                    s = mob.getText().toString();
                    if (s.length() != 10) {
                        mob.setError("Invalid Mobile No.");
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
                        pass.setError("Password must be at least 8 characters long");

                        return true;
                    }
                }
                return false;
            }
        });
        conf.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View v, int keyCode, KeyEvent event) {
                if (event.getKeyCode() == KeyEvent.KEYCODE_ENTER) {
                    String s2 = pass.getText().toString();
                    String s1 = conf.getText().toString();
                    if (!s2.equals(s1)) {
                        conf.setError("Password Doesn't Match");

                        return true;
                    }
                }
                return false;
            }
        });
        register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                if (checkforinput()) {

                    String use,pas;
                    use = user.getText().toString();
                    pas=pass.getText().toString();
                    FileHandling file = new FileHandling();
                    try {
                        file.write(use+pas);


                    } catch (IOException e) {
                        e.printStackTrace();
                    }



                    Intent intent = new Intent(getApplicationContext(), LoginActivity.class);
                    intent.putExtra("from","from register");
                    startActivity(intent);


                    finish();
                }


            }
        });
    }


    private boolean validateEmailAddress(String emailAddress) {
        String expression = "^[\\w\\-]([\\.\\w])+[\\w]+@([\\w\\-]+\\.)+[A-Z]{2,4}$";
        CharSequence inputStr = emailAddress;
        Pattern pattern = Pattern.compile(expression, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(inputStr);
        return matcher.matches();
    }

    boolean checkforinput()
    {
        String s1,s2;

        //s1=name.getText().toString();
      /* if (s1.equalsIgnoreCase("")) {
            name.setError("Name is Mandatory");
            return false;
        }

        s1=user.getText().toString();
        if (s1.equalsIgnoreCase("")) {
            user.setError("Username not Available");
            return false;
        }

        s1=roll.getText().toString();
        if (s1.length() != 4) {
            roll.setError("Invalid Roll No.");

            return false;
        }

        s1=email.getText().toString();
        if (!validateEmailAddress(s1)) {
            email.setError("Invalid Email");
            return false;
        }

        s1=mob.getText().toString();
        if (s1.length() != 10) {
            mob.setError("Invalid Mobile No.");
            return false;
        }

        s1=pass.getText().toString();
        if (s1.length() < 8) {
            pass.setError("Password must be at least 8 characters long");

            return false;
        }

        s1 = conf.getText().toString();
         s2 = pass.getText().toString();
        if (!s2.equals(s1)) {
            conf.setError("Password Doesn't Match");

            return false;
        }*/
        s1=user.getText().toString();
        if (s1.equalsIgnoreCase("")) {
            user.setError("Username not Available");
            return false;
        }
        s1=pass.getText().toString();
        if (s1.length() < 8) {
            pass.setError("Password must be at least 8 characters long");

            return false;
        }

        return true;
    }
}
