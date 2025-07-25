package com.ludo.kheli.activity;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.google.android.material.textfield.TextInputEditText;
import com.ludo.kheli.MyApplication;
import com.ludo.kheli.api.ApiCalling;
import com.ludo.kheli.helper.AppConstant;
import com.ludo.kheli.helper.Function;
import com.ludo.kheli.helper.Preferences;
import com.ludo.kheli.helper.ProgressBar;
import com.ludo.kheli.model.UserModel;
import com.dream.zone.R;

import java.util.List;
import java.util.Objects;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class WithdrawActivity extends AppCompatActivity {

    private RadioButton payTmRb, googlePayRb, phonePeRb;
    private TextInputEditText nameEt, numberEt, amountEt;
    public TextView codeTv, signTv, noteTv, alertTv;
    private Button submitBt;

    private ProgressBar progressBar;
    private ApiCalling api;

    private String nameSt;
    private String numberSt;
    private String amountSt;
    private String mopSt;
    public double deposit = 0, winning = 0, bonus = 0, total = 0;

    @SuppressLint({"DefaultLocale", "SetTextI18n"})
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_withdraw);
        api = MyApplication.getRetrofit().create(ApiCalling.class);
        progressBar = new ProgressBar(this, false);

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        Objects.requireNonNull(getSupportActionBar()).setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setDisplayShowHomeEnabled(true);

        toolbar.setNavigationOnClickListener(v -> onBackPressed());

        getUserDetails();

        payTmRb = findViewById(R.id.payTmRb);
        googlePayRb = findViewById(R.id.googlePayRb);
        phonePeRb = findViewById(R.id.phonePeRb);
        nameEt = findViewById(R.id.nameEt);
        numberEt = findViewById(R.id.numberEt);
        amountEt = findViewById(R.id.amountEt);
        noteTv = findViewById(R.id.noteTv);
        alertTv = findViewById(R.id.alertTv);
        codeTv = findViewById(R.id.codeTv);
        signTv = findViewById(R.id.signTv);
        submitBt = findViewById(R.id.telegram);

        codeTv.setText(AppConstant.COUNTRY_CODE);
        signTv.setText(AppConstant.CURRENCY_SIGN);

        payTmRb.setOnClickListener(v -> {
            nameEt.setHint("Enter Your Name");
            numberEt.setHint("Enter bKash Number");
            mopSt = "bKash";
        });

        googlePayRb.setOnClickListener(v -> {
            nameEt.setHint("Enter Your Name");
            numberEt.setHint("Enter Nagat Number");
            mopSt = "Nagat";
        });

        phonePeRb.setOnClickListener(v -> {
            nameEt.setHint("Enter Your Name");
            numberEt.setHint("Enter Rocket Number");
            mopSt = "Rocket";
        });

        submitBt.setOnClickListener(v -> {
            submitBt.setEnabled(false);
            try {
                InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
                imm.hideSoftInputFromWindow(getCurrentFocus().getWindowToken(), 0);
            } catch (Exception e) {
                e.printStackTrace();
            }

            if (payTmRb.isChecked()) {
                mopSt = "bKash";
                alertTv.setText("Enter Valid bKash Number");
            } else if (googlePayRb.isChecked()) {
                mopSt = "Nagat";
                alertTv.setText("Enter Valid Nagat Number");
            } else if (phonePeRb.isChecked()) {
                mopSt = "Rocket";
                alertTv.setText("Enter Rocket Number");
            }

            nameSt = Objects.requireNonNull(nameEt.getText()).toString().trim();
            numberSt = Objects.requireNonNull(numberEt.getText()).toString().trim();
            amountSt = Objects.requireNonNull(amountEt.getText()).toString().trim();

            if (!nameSt.isEmpty() && !numberSt.isEmpty() && !amountSt.isEmpty()) {
                double payout = Integer.parseInt(amountEt.getText().toString());

                {
                    submitBt.setEnabled(true);
                    alertTv.setVisibility(View.VISIBLE);
                    alertTv.setTextColor(Color.parseColor("#ff0000"));
                    submitBt.setEnabled(true);
                    alertTv.setVisibility(View.VISIBLE);
                    alertTv.setTextColor(Color.parseColor("#ff0000"));
                    alertTv.setVisibility(View.GONE);
                    postWithdraw();

                    submitBt.setEnabled(true);
                    alertTv.setVisibility(View.VISIBLE);
                    alertTv.setText("You don't have enough won amount to redeem.");
                    alertTv.setTextColor(Color.parseColor("#ff0000"));
                }
            }
            else {
                submitBt.setEnabled(true);
                alertTv.setVisibility(View.VISIBLE);
                alertTv.setText("Please enter valid information.");
                alertTv.setTextColor(Color.parseColor("#ff0000"));
            }
        });

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
                                Preferences.getInstance(WithdrawActivity.this).setString(Preferences.KEY_IS_AUTO_LOGIN,"0");

                                Intent i = new Intent(WithdrawActivity.this, LoginActivity.class);
                                i.putExtra("finish", true);
                                i.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_CLEAR_TASK | Intent.FLAG_ACTIVITY_NEW_TASK);
                                startActivity(i);
                            }
                            else if (res.get(0).getIs_active() == 0) {
                                Preferences.getInstance(WithdrawActivity.this).setString(Preferences.KEY_IS_AUTO_LOGIN,"0");

                                Intent i = new Intent(WithdrawActivity.this, LoginActivity.class);
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

    private void postWithdraw() {
        progressBar.showProgressDialog();

        Call<UserModel> call = api.postWithdraw(AppConstant.PURCHASE_KEY, Preferences.getInstance(this).getString(Preferences.KEY_USER_ID), nameSt, numberSt, Double.parseDouble(amountSt), mopSt );
        call.enqueue(new Callback<UserModel>() {
            @Override
            public void onResponse(@NonNull Call<UserModel> call, @NonNull Response<UserModel> response) {
                progressBar.hideProgressDialog();

                if (response.isSuccessful()) {
                    UserModel legalData = response.body();
                    List<UserModel.Result> res;
                    if (legalData != null) {
                        res = legalData.getResult();
                        Function.showToast(WithdrawActivity.this, res.get(0).getMsg());
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