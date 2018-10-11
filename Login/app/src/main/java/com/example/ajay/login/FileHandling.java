package com.example.ajay.login;

import android.content.Context;
import android.os.Environment;
import android.util.Log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;


public class FileHandling {

    private
    Context context;

    FileHandling(Context c)  {

        context = c;
    }

    public void write(String s) throws IOException {

        try {


            //FileWriter writer = new FileWriter(new File(c.getFilesDir(), "Data.txt"));

            //  BufferedWriter bufferedWriter = new BufferedWriter(writer);
//
            File root=new File(context.getFilesDir(),"Fold");
            if(!root.exists())
                root.mkdir();

            File file=new File(root,"Log.txt");
            if(!file.exists())
                file.createNewFile();
            BufferedWriter bufferedwriter = new BufferedWriter(new FileWriter(file));


            bufferedwriter.append(s);
            bufferedwriter.append('\n');
            Log.i("Written", s);
            bufferedwriter.flush();
            bufferedwriter.close();


        } catch (IOException e) {
            e.printStackTrace();
        }
    }

   /* public String read() throws IOException {
        String s = "";


        try {


           // File gpxfile = null;
           // gpxfile = new File("Data.txt");


            ///FileReader fileReader = new FileReader(gpxfile);
            //BufferedReader bufferedReader = new BufferedReader(fileReader);


            s = bufferedReader.readLine();

            bufferedReader.close();


        } catch (IOException e) {
            e.printStackTrace();
        } finally {

            return s;
        }
    }*/

    boolean check(String s) throws IOException {

        String found = "12";

        try {

            File root=new File(Environment.getExternalStorageDirectory(),"Fold");
            if(!root.exists())
                root.mkdir();

            File file=new File(root,"Log.txt");
            BufferedReader bufferedReader = new BufferedReader(new FileReader(file));

             found = bufferedReader.readLine();
            while (found != null) {

                if (found.equals(s))
                    return true;
                found = bufferedReader.readLine();
            }
            bufferedReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }


        return false;
    }
}
