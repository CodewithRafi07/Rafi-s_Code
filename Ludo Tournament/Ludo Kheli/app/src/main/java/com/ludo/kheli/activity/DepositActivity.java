package com.ludo.kheli.activity;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.dream.zone.R;
import com.google.android.material.textfield.TextInputEditText;
import com.ludo.kheli.MyApplication;
import com.ludo.kheli.api.ApiCalling;
import com.ludo.kheli.helper.AppConstant;
import com.ludo.kheli.helper.Function;
import com.ludo.kheli.helper.Preferences;
import com.ludo.kheli.helper.ProgressBar;
import com.ludo.kheli.model.UserModel;

import java.util.List;
import java.util.Objects;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class DepositActivity extends AppCompatActivity {

    private RadioButton payTmRb, googlePayRb, phonePeRb;
    private TextInputEditText numberEt, amountEt;
    public TextView codeTv;
    public TextView signTv;
    public TextView alertTv;
    private Button submitBt;

    private ProgressBar progressBar;
    private ApiCalling api;

    public String nameSt;
    private String numberSt;
    private String amountSt;
    private String mopSt;
    public double deposit = 0, winning = 0, bonus = 0, total = 0;

    private WebView webView;

    Handler handler = new Handler(Looper.getMainLooper(), message -> {
        if (message.what == 1) {
            webViewGoBack();
        }
        return true;
    });

    @SuppressLint({"DefaultLocale", "SetTextI18n", "SetJavaScriptEnabled"})
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_deposit);
        api = MyApplication.getRetrofit().create(ApiCalling.class);
        progressBar = new ProgressBar(this, false);

        // Inside your activity
        EditText emailEt = findViewById(R.id.emailEt);
        EditText nameEt = findViewById(R.id.nameEt);

// Now you can use 'emailEt' to interact with the EditText, for example:
        String enteredEmail = emailEt.getText().toString();


        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        Objects.requireNonNull(getSupportActionBar()).setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setDisplayShowHomeEnabled(true);

        toolbar.setNavigationOnClickListener(v -> onBackPressed());

        getUserDetails();

        payTmRb = findViewById(R.id.payTmRb);
        googlePayRb = findViewById(R.id.googlePayRb);
        phonePeRb = findViewById(R.id.phonePeRb);
        emailEt = findViewById(R.id.emailEt);
        nameEt = findViewById(R.id.nameEt);
        numberEt = findViewById(R.id.numberEt);
        amountEt = findViewById(R.id.amountEt);
        alertTv = findViewById(R.id.alertTv);
        codeTv = findViewById(R.id.codeTv);
        signTv = findViewById(R.id.signTv);
        submitBt = findViewById(R.id.telegram);

        codeTv.setText(AppConstant.COUNTRY_CODE);
        signTv.setText(AppConstant.CURRENCY_SIGN);
        alertTv.setText(String.format("Minimum Deposit Amount is %s%d", AppConstant.CURRENCY_SIGN, AppConstant.MIN_DEPOSIT_LIMIT));

        payTmRb.setOnClickListener(v -> {

            numberEt.setHint("Enter sender bKash mobile number");
            mopSt = "bKaash";
        });

        googlePayRb.setOnClickListener(v -> {

            numberEt.setHint("Enter sender nagat mobile number");
            mopSt = "Nagat";
        });

        phonePeRb.setOnClickListener(v -> {

            numberEt.setHint("Enter sender rocket mobile number");
            mopSt = "Rocket";
        });


        try {
            emailEt.setText(Preferences.getInstance(this).getString(Preferences.KEY_EMAIL));
        }catch (IllegalArgumentException e){
            e.printStackTrace();
        }

        emailEt.setText(Preferences.getInstance(this).getString(Preferences.KEY_EMAIL));

        try {
            nameEt.setText(Preferences.getInstance(this).getString(Preferences.KEY_FULL_NAME));
        }catch (IllegalArgumentException e){
            e.printStackTrace();
        }

        nameEt.setText(Preferences.getInstance(this).getString(Preferences.KEY_FULL_NAME));

        submitBt.setOnClickListener(v -> {
            submitBt.setEnabled(false);
            try {
                InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
                imm.hideSoftInputFromWindow(Objects.requireNonNull(getCurrentFocus()).getWindowToken(), 0);
            } catch (Exception e) {
                e.printStackTrace();
            }

            if (payTmRb.isChecked()) {
                mopSt = "bKash ";
                alertTv.setText("Enter Valid bKash Number");
            } else if (googlePayRb.isChecked()) {
                mopSt = "Nagat ";
                alertTv.setText("Enter Valid Nagat Number");
            } else if (phonePeRb.isChecked()) {
                mopSt = "Rocket ";
                alertTv.setText("Enter Rocket Number");
            }


            numberSt = Objects.requireNonNull(numberEt.getText()).toString().trim();
            amountSt = Objects.requireNonNull(amountEt.getText()).toString().trim();

            if (!nameSt.isEmpty() && !numberSt.isEmpty() && !amountSt.isEmpty()) {
                {
                    submitBt.setEnabled(true);
                    alertTv.setVisibility(View.VISIBLE);
                    alertTv.setText("Loading...");
                    alertTv.setTextColor(Color.parseColor("#ff0000"));
                    postDeposit();
                }
            }
            else {
                submitBt.setEnabled(true);
                alertTv.setVisibility(View.VISIBLE);
                alertTv.setText("Please enter valid information.");
                alertTv.setTextColor(Color.parseColor("#ff0000"));

            }
        });

        setSupportActionBar(toolbar);
        Objects.requireNonNull(getSupportActionBar()).setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setDisplayShowHomeEnabled(true);

        //noinspection deprecation
        toolbar.setNavigationOnClickListener(v -> onBackPressed());

        webView = findViewById(R.id.webView);
        webView.setLayerType(View.LAYER_TYPE_SOFTWARE, null);
        webView.setWebViewClient(new MyWebViewClient());
        webView.getSettings().setJavaScriptEnabled(true);

        webView.setOnKeyListener((v, keyCode, event) -> {
            if (keyCode == KeyEvent.KEYCODE_BACK && event.getAction() == MotionEvent.ACTION_UP && webView.canGoBack()) {
                handler.sendEmptyMessage(1);
                return true;
            }
            return false;
        });

        webView = findViewById(R.id.webView);
        webView.setLayerType(View.LAYER_TYPE_HARDWARE, null);


        String userEmail = Preferences.getInstance(this).getString(Preferences.KEY_EMAIL);


        if (userEmail != null) {
            emailEt.setText(userEmail);
        } else {
            // Handle the case where userEmail is null
        }



        webView.loadUrl("https://ludotournament.pro/deposit.php");
        String javascriptCode = "document.getElementById('email').value = '" + userEmail + "';";


        webView.setWebViewClient(new MyWebViewClient() {
            @Override
            public void onPageFinished(WebView view, String url) {
                super.onPageFinished(view, url);
                // Execute the JavaScript code after the page is loaded
                view.evaluateJavascript(javascriptCode, null);
            }
        });
    }

    private void webViewGoBack() {
        webView.goBack();
    }

    private class MyWebViewClient extends WebViewClient {


        @Override
        public void onPageStarted(WebView view, String url, android.graphics.Bitmap favicon) {
            super.onPageStarted(view, url, favicon);
            progressBar.showProgressDialog();
        }

        @Override
        public void onPageFinished(WebView view, String url) {
            progressBar.hideProgressDialog();
        }

        @Override
        public void onReceivedError(WebView view, int errorCode, String description, String failingUrl) {
            super.onReceivedError(view, errorCode, description, failingUrl);
        }

    }
    private void getUserDetails() {
        Call<UserModel> call = api.getUserDetails(AppConstant.PURCHASE_KEY, Preferences.getInstance(this).getString(Preferences.KEY_USER_ID));
        call.enqueue(new Callback<UserModel>() {
            @Override
            public void onResponse(@NonNull Call<UserModel> call, @NonNull Response<UserModel> response) {
                if (response.isSuccessful()) {
                    UserModel legalData = response.body();
                    List<UserModel.Result> res;
                    if (legalData != null) {
                        res = legalData.getResult();
                        if (res.get(0).getSuccess() == 1) {
                            deposit = res.get(0).getDeposit_bal();
                            winning = res.get(0).getWon_bal();
                            bonus = res.get(0).getBonus_bal();
                            total = deposit + winning + bonus;

                            if (res.get(0).getIs_block() == 1) {
                                Preferences.getInstance(DepositActivity.this).setString(Preferences.KEY_IS_AUTO_LOGIN,"0");

                                Intent i = new Intent(DepositActivity.this, LoginActivity.class);
                                i.putExtra("finish", true);
                                i.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
                                startActivity(i);
                            }
                            else if (res.get(0).getIs_active() == 0) {
                                Preferences.getInstance(DepositActivity.this).setString(Preferences.KEY_IS_AUTO_LOGIN,"0");

                                Intent i = new Intent(DepositActivity.this, LoginActivity.class);
                                i.putExtra("finish", true);
                                i.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
                                startActivity(i);
                            }
                        }
                    }
                }
            }

            @Override
            public void onFailure(@NonNull Call<UserModel> call, @NonNull Throwable t) {

            }

        });


    }

    private void postDeposit() {
        progressBar.showProgressDialog();

        Call<UserModel> call = api.postWithdrawal(AppConstant.PURCHASE_KEY, Preferences.getInstance(this).getString(Preferences.KEY_USER_ID), nameSt, numberSt, Double.parseDouble(amountSt), mopSt );
        call.enqueue(new Callback<UserModel>() {
            @Override
            public void onResponse(@NonNull Call<UserModel> call, @NonNull Response<UserModel> response) {
                progressBar.hideProgressDialog();

                if (response.isSuccessful()) {
                    UserModel legalData = response.body();
                    List<UserModel.Result> res;
                    if (legalData != null) {
                        res = legalData.getResult();
                        Function.showToast(DepositActivity.this, res.get(0).getMsg());
                        onBackPressed();
                    }
                }


            }


            @Override
            public void onFailure(@NonNull Call<UserModel> call, @NonNull Throwable t) {
                progressBar.hideProgressDialog();
            }

        });
    }
}