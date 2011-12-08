package com.aevumlab.gdxcpp.tests;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

import com.aevumlab.gdxcpp.ApplicationManager;

public class LibGdxCppTestActivity extends Activity {
    ApplicationManager manager;
    
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        getWindow().clearFlags(WindowManager.LayoutParams.FLAG_FORCE_NOT_FULLSCREEN);
              
        manager = new ApplicationManager();
                
        manager.initialize(this);
        
        manager.initializeWithSharedLib("BaseTest", getAssets());
        setContentView(manager.createView(this));
    }
    
    @Override
    protected void onDestroy() {
    	manager.unload();
    	super.onDestroy();
    }
}