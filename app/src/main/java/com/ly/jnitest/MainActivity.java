package com.ly.jnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    private Button btn_main_change;
    private TextView tv_main_content;

    private AndroidJni androidJni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn_main_change = (Button)findViewById(R.id.btn_main_change);
        tv_main_content = (TextView)findViewById(R.id.tv_main_content);
        androidJni = new AndroidJni();

        btn_main_change.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String data = androidJni.getTestData(3);
                tv_main_content.setText(data);
            }
        });
    }
}
