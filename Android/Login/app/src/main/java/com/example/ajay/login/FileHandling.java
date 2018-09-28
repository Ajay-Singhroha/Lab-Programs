package com.example.ajay.login;

import android.os.Environment;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;


public class FileHandling {

    private FileReader re;

    public void write(String s) throws IOException {

        try {


            File root = new File(Environment.getExternalStorageDirectory().getAbsolutePath(), "Database");
            if (!root.exists())
                root.mkdirs();


            File gpxfile=null;
            if(gpxfile!=null)
            {

                FileWriter writer = new FileWriter(gpxfile);
                BufferedWriter bufferedWriter = new BufferedWriter(writer);


                bufferedWriter.append(s);
                bufferedWriter.append("\n\r");

                bufferedWriter.flush();
                bufferedWriter.close();
                writer.flush();
                writer.close();
            } else{
                gpxfile = new File(root, "Database");
            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String read() throws IOException {
        String s = "";
        int ch;

        try {


            File root = new File(Environment.getExternalStorageDirectory().getAbsolutePath(), "Database");
            if (!root.exists())
                root.mkdirs();



            File gpxfile =null;
            if (gpxfile!=null) {
                FileReader fileReader = new FileReader(gpxfile);
                BufferedReader bufferedReader = new BufferedReader(fileReader);


                s = bufferedReader.readLine();

                bufferedReader.close();
            } else {
                gpxfile = new File(root, "Database");
            }



        } catch (IOException e) {
            e.printStackTrace();
        }
        return s;
    }

    boolean check(String s) {

        String found;

        try {
            File root = new File(Environment.getExternalStorageDirectory().getAbsolutePath(), "Database");
            if (!root.exists())
                root.mkdirs();


            File gpxfile = new File(root, "Database");
            FileReader reader = new FileReader(gpxfile);
            BufferedReader bufferedReader = new BufferedReader(reader);

            found = bufferedReader.readLine();
            while (found != null) {

                if (found.equals(s))
                    return true;
                found = bufferedReader.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }


        return false;
    }
}
