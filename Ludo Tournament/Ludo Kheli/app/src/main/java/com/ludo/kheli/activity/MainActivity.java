package com.ludo.kheli.activity;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.SwitchCompat;
import androidx.appcompat.widget.Toolbar;
import androidx.browser.customtabs.CustomTabsIntent;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.ludo.kheli.helper.AppConstant;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.dream.zone.R;
import com.ludo.kheli.fragment.MatchFragment;
import com.ludo.kheli.fragment.SettingFragment;
import com.google.firebase.analytics.FirebaseAnalytics;

import com.google.firebase.messaging.FirebaseMessaging;

import java.util.Objects;

@SuppressWarnings("ALL")
public class MainActivity extends AppCompatActivity {

    Button button2;
    Button button3;

    public Toolbar toolbar;
    public FrameLayout notificationFl;
    public TextView counterTv;
    public SwitchCompat switchNotification;

    public static BottomNavigationView navigationView;
    public boolean doubleBackToExitPressedOnce = false;

    public SharedPreferences preferences;
    public String clickAction;

    public String isSubscribe;
    public FirebaseAnalytics mFirebaseAnalytics;

    @SuppressLint("NonConstantResourceId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mFirebaseAnalytics = FirebaseAnalytics.getInstance(this);

        button2 = findViewById(R.id.button2);

        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                gotoUrl("https://wa.me/+380947128411");
            }
        });

        button3 = findViewById(R.id.button3);

        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                gotoUrl("https://t.me/apurborahman1");
            }
        });

        ;try {
            clickAction = Objects.requireNonNull(getIntent().getExtras()).getString("click_action","default");
        }catch (NullPointerException e){
            clickAction = "default";
        }

        toolbar = findViewById(R.id.toolbar);
        notificationFl = toolbar.findViewById(R.id.notificationFl);
        counterTv = toolbar.findViewById(R.id.counterTv);
        switchNotification = findViewById(R.id.switchNotification);

        notificationFl.setOnClickListener(v -> {
            Intent intent = new Intent(getApplicationContext(), NotificationActivity.class);
            startActivity(intent);
        });

        Bundle bundle = new Bundle();
        bundle.putString("click_action", clickAction);

        MatchFragment matchFragment = new MatchFragment();
        matchFragment.setArguments(bundle);
        getSupportFragmentManager().beginTransaction().replace(R.id.mainContainer, matchFragment).commit();

        navigationView = findViewById(R.id.navigationView);
        navigationView.setOnNavigationItemSelectedListener(item -> {
            switch (item.getItemId()) {
                case R.id.navigation_game:
                    getSupportFragmentManager().beginTransaction().replace(R.id.mainContainer, new MatchFragment()).commit();
                    return true;
                case R.id.navigation_leaderboard:
                    try {
                        CustomTabsIntent.Builder builder = new CustomTabsIntent.Builder();
                        CustomTabsIntent customTabsIntent = builder.build();
                        customTabsIntent.launchUrl(MainActivity.this, Uri.parse(AppConstant.HOW_TO_PLAY));
                    }catch (Exception e){
                        e.printStackTrace();
                    }
                    return true;
                case R.id.navigation_more:
                    getSupportFragmentManager().beginTransaction().replace(R.id.mainContainer,new SettingFragment()).commit();
                    return true;
            }
            return false;
        });

        SharedPreferences sharedPreferences = getSharedPreferences("Setting", Context.MODE_PRIVATE);
        isSubscribe = sharedPreferences.getString("SUB_STATUS", "true");

        switchNotification.setChecked(!TextUtils.isEmpty(isSubscribe) && !isSubscribe.equals("false"));

        if (switchNotification.isChecked()){
            FirebaseMessaging.getInstance().subscribeToTopic(AppConstant.TOPIC_GLOBAL);
        }
        else {
            FirebaseMessaging.getInstance().unsubscribeFromTopic(AppConstant.TOPIC_GLOBAL);
        }

        switchNotification.setOnCheckedChangeListener((buttonView, isChecked) -> {
            if (switchNotification.isChecked()){
                FirebaseMessaging.getInstance().subscribeToTopic(AppConstant.TOPIC_GLOBAL);

                SharedPreferences.Editor editor = sharedPreferences.edit();
                editor.putString("SUB_STATUS", "true");
                editor.apply();
            }
            else{
                FirebaseMessaging.getInstance().unsubscribeFromTopic(AppConstant.TOPIC_GLOBAL);

                SharedPreferences.Editor editor = sharedPreferences.edit();
                editor.putString("SUB_STATUS", "false");
                editor.apply();
            }
        });

    }

    private void gotoUrl(String s) {
        Uri uri =  Uri.parse(s);
        startActivity(new Intent(Intent.ACTION_VIEW,uri));

    }

    @Override
    protected void onPostResume() {
        super.onPostResume();
    }

    @Override
    public void onBackPressed() {
        if (doubleBackToExitPressedOnce) {
            finish(); return;
        }

        doubleBackToExitPressedOnce = true;
        Toast.makeText(this, "Please click BACK again to exit", Toast.LENGTH_SHORT).show();

        new Handler().postDelayed(() -> doubleBackToExitPressedOnce = false, 1500);
    }
}