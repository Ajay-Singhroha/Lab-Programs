package com.ajay.hrc.inc_dec_edittext;



        import android.support.v7.app.AppCompatActivity;
        import android.os.Bundle;
        import android.text.Editable;
        import android.view.View;
        import android.widget.Button;
        import android.widget.EditText;
        import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    TextView t;
    int count=0;
    Button b1,b2,b3;
    EditText et;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        t=(TextView)findViewById(R.id.tv);
        b1=(Button)findViewById(R.id.button1);
        b2=(Button)findViewById(R.id.button2);
        et=(EditText)findViewById(R.id.editText);
        b3=(Button)findViewById(R.id.button3);
        b1.setOnClickListener(this);
        b2.setOnClickListener(this);
        b3.setOnClickListener(this);

    }


    @Override
    public void onClick(View view) {

            if (view.getId() == R.id.button1)
            {
                count += Integer.parseInt(et.getText().toString());
                et.setText(" ");
            }
            else if (view.getId() == R.id.button2)
            {
                count -= Integer.parseInt(et.getText().toString());
                et.setText(" ");
            }
            else
                count = 0;


                et.setText(" ");
                t.setText(" "+count);
            }
        }

