package com.ajay.hp.calculator;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.Random;

public class MainActivity extends AppCompatActivity {
    TextView tv1;
    Random r=new Random();
    Button b1, b2, b3, b4, b5, b6, b7, b8, b9, b0;
    String s = "";
    String str = "";
    double arr[] = new double[100];
    DecimalFormat df = new DecimalFormat("#.######");
    char op_arr[] = new char[50];
    double result = 0;
    int res = 0;
    char current_op;
    int count = 0;
    int dec_count = 0;
    int op_count = 0;
    Button bdiv, bmul, badd, bsub, bdot, beq, bd;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        b1 = (Button) findViewById(R.id.b1);
        b2 = (Button) findViewById(R.id.b2);
        b3 = (Button) findViewById(R.id.b3);
        b4 = (Button) findViewById(R.id.b4);
        b5 = (Button) findViewById(R.id.b5);
        b6 = (Button) findViewById(R.id.b6);
        b7 = (Button) findViewById(R.id.b7);
        b8 = (Button) findViewById(R.id.b8);
        b9 = (Button) findViewById(R.id.b9);
        b0 = (Button) findViewById(R.id.b0);
        bdiv = (Button) findViewById(R.id.bdiv);
        bmul = (Button) findViewById(R.id.bmul);
        badd = (Button) findViewById(R.id.badd);
        bsub = (Button) findViewById(R.id.bsub);
        beq = (Button) findViewById(R.id.bequal);
        bdot = (Button) findViewById(R.id.bdot);
        bd = (Button) findViewById(R.id.bdel);
        tv1 = (TextView) findViewById(R.id.tv1);
        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                str += "1";
                tv1.setText(str);
                s += "1";
            }
        });
        b2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                str += "2";
                tv1.setText(str);
                s += "2";


            }
        });
        b3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                str += "3";
                tv1.setText(str);
                s += "3";

            }
        });
        b4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                str += "4";
                tv1.setText(str);
                s += "4";
            }
        });
        b5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                str += "5";
                tv1.setText(str);
                s += "5";
            }
        });
        b6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                str += "6";
                tv1.setText(str);
                s += "6";

            }
        });
        b7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                str += "7";
                tv1.setText(str);
                s += "7";

            }
        });
        b8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                str += "8";
                tv1.setText(str);
                s += "8";
            }
        });
        b9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                str += "9";
                tv1.setText(str);
                s += "9";
            }
        });
        b0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(!s.equals("")) {

                    str += "0";
                    tv1.setText(str);
                    s += "0";
                }
            }
        });

        bdiv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!s.equals("") && !s.equals("0.")) {
                    arr[count] = Double.valueOf(s);
                    count++;

                    str += "/";
                    tv1.setText(str);
                    op_arr[op_count] = '/';
                    op_count++;
                    s = "";
                }
                if (count == op_count + 1) {
                    str += "/";

                    tv1.setText(str);
                    op_arr[op_count] = '/';
                    op_count++;
                    s = "";
                }
            }
        });

        bmul.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!s.equals("") && !s.equals("0.")) {
                    arr[count] = Double.valueOf(s);
                    count++;

                    str += "*";
                    tv1.setText(str);
                    op_arr[op_count] = '*';
                    op_count++;
                    s = "";
                }
                if (count == op_count + 1) {
                    str += "*";

                    tv1.setText(str);
                    op_arr[op_count] = '*';
                    op_count++;
                    s = "";
                }
            }
        });
        badd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!s.equals("") && !s.equals("0.")) {
                    arr[count] = Double.valueOf(s);
                    count++;
                    str += "+";

                    tv1.setText(str);
                    op_arr[op_count] = '+';
                    op_count++;
                    s = "";
                }
                if (count == op_count + 1) {
                    str += "+";

                    tv1.setText(str);
                    op_arr[op_count] = '+';
                    op_count++;
                    s = "";
                }
            }
        });
        bsub.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!s.equals("") && !s.equals("0.")) {
                    arr[count] = Double.valueOf(s);
                    count++;

                }
                if (count == op_count + 1) {
                    str += "-";
                    tv1.setText(str);
                    op_arr[op_count] = '-';
                    op_count++;
                    s = "";

                }
            }
        });

        bdot.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (s.equals("")) {
                    str += "0.";
                    tv1.setText(str);
                    s += "0.";

                    dec_count++;
                }
                if (s.indexOf('.') == -1) {
                    str += ".";
                    tv1.setText(str);
                    s += ".";

                }
                if(!s.isEmpty()&&s.indexOf('.')==-1)
                {
                    str += ".";
                    tv1.setText(str);
                    s += ".";
                }

            }
        });
        beq.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {



                if (count == op_count&&!s.isEmpty()) {
                    arr[count] = Double.valueOf(s);
                    s="";
                    count++;
                    calculation();
                    if (result % 1 == 0) {
                        res = (int) result;
                        str=String.valueOf(res);
                        s=String.valueOf(res);
                        tv1.setText(String.valueOf(res));
                    } else {
                        tv1.setText(String.valueOf(df.format(result)));
                        str = String.valueOf(result);
                        s = String.valueOf(result);
                    }

                    count=0;
                    op_count=0;

                }
            }
        });
        bd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Toast.makeText(MainActivity.this, "Press Long To Reset ", Toast.LENGTH_SHORT).show();
                   if(!str.equals("")) {
                       if (count == op_count + 1) {
                           arr[count - 1] /= 10;
                           if (arr[count - 1] == 0)
                               count--;
                           str = str.substring(0, str.length() - 1);
                           tv1.setText(str);
                       } else if (!s.equals("")) {
                           s = s.substring(0, s.length() - 1);
                           str = str.substring(0, str.length() - 1);
                           tv1.setText(str);
                       } else {
                           op_count--;
                           str = str.substring(0, str.length() - 1);
                           tv1.setText(str);
                       }

                   }
            }
        });
        bd.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View view) {
                str = "";
                s = "";
                tv1.setText(str);
                result = count = op_count = dec_count = res = 0;
                return true;
            }
        });

    }
    public int priority(char op)
    {
        switch(op)
        {
            case '/': return 4;
            case '*': return  3;
            case '+': return 2;
            case '-': return 2;
            default: return 0;
        }
    }
    public void shift(int highest)
    {

               for(int i=highest+1;i<count-1;i++)
               {
                    arr[i]=arr[i+1];
               }
               for(int i=highest;i<op_count-1;i++)
               {
                    op_arr[i]=op_arr[i+1];
               }
            op_count--;count--;

    }
    protected void calculation() {

        while(op_count!=0){
            int highest=0;
            for(int j=1;j<op_count;j++)
            {
                if(priority(op_arr[highest])<priority(op_arr[j]))
                {
                        highest=j;
                }
            }

             switch (op_arr[highest]) {
                case '/':
                    arr[highest] /= arr[highest + 1];
                    //arr[highest + 1]=-1;
                    break;
                case '*':
                    arr[highest] *= arr[highest + 1];

                    //arr[highest + 1]=-1;
                    break;
                case '+':
                    arr[highest] += arr[highest+1];
                  //  arr[highest]=-1;
                    break;
                case '-':
                    arr[highest] -= arr[highest+ 1];
                  //  arr[highest + 1]=-1;
                    break;
            }

                shift(highest);
        }

     //   for(int i=0;i<count ; i++)
            result=arr[0];
    }



}