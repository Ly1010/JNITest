package com.ly.jnitest;

import android.widget.TextView;

public class AndroidJni {

    static{
        System.loadLibrary("jnitest");
    }

    private native int getTestData(TestData data);

    public String getTestData(int testI){
        TestData data = new TestData();
        data.setData(testI);
        int i = getTestData(data);
        return "数据：" + i;
    }
}
