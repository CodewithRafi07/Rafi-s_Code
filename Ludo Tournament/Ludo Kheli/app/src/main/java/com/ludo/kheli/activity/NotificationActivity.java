package com.ludo.kheli.activity;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.ludo.kheli.MyApplication;
import com.ludo.kheli.adapter.NotificationAdapter;
import com.ludo.kheli.api.ApiCalling;
import com.ludo.kheli.helper.AppConstant;
import com.ludo.kheli.helper.Function;
import com.ludo.kheli.helper.Preferences;
import com.ludo.kheli.helper.ProgressBar;
import com.ludo.kheli.model.NotificationModel;
import com.dream.zone.R;

import java.util.List;
import java.util.Objects;

public class NotificationActivity extends AppCompatActivity {

    private RecyclerView recyclerView;
    private TextView noDataTv;

    private ProgressBar progressBar;
    private ApiCalling api;
    private NotificationAdapter notificationAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_notification);
        api = MyApplication.getRetrofit().create(ApiCalling.class);
        progressBar = new ProgressBar(this, false);

        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        Objects.requireNonNull(getSupportActionBar()).setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setDisplayShowHomeEnabled(true);

        toolbar.setNavigationOnClickListener(v -> onBackPressed());

        if(Function.checkNetworkConnection(NotificationActivity.this)) {
            getNotification();
        }
    }

    private void getNotification() {
        recyclerView = findViewById(R.id.recyclerView);
        noDataTv = findViewById(R.id.noDataTv);
        progressBar.showProgressDialog();

        Call<List<NotificationModel>> call = api.getNotification(AppConstant.PURCHASE_KEY, Preferences.getInstance(this).getString(Preferences.KEY_USER_ID));
        call.enqueue(new Callback<List<NotificationModel>>() {
            @SuppressLint("NotifyDataSetChanged")
            @Override
            public void onResponse(@NonNull Call<List<NotificationModel>> call, @NonNull Response<List<NotificationModel>> response) {
                progressBar.hideProgressDialog();

                if (response.isSuccessful()) {
                    List<NotificationModel> legalData = response.body();
                    if (legalData != null) {
                        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(NotificationActivity.this);
                        recyclerView.setLayoutManager(linearLayoutManager);
                        notificationAdapter = new NotificationAdapter(NotificationActivity.this, legalData);

                        if (notificationAdapter.getItemCount() != 0) {
                            notificationAdapter.notifyDataSetChanged();
                            recyclerView.setAdapter(notificationAdapter);

                            recyclerView.setVisibility(View.VISIBLE);
                            noDataTv.setVisibility(View.GONE);
                        }
                        else {
                            recyclerView.setVisibility(View.GONE);
                            noDataTv.setVisibility(View.VISIBLE);
                        }
                    }
                }
            }

            @Override
            public void onFailure(@NonNull Call<List<NotificationModel>> call, @NonNull Throwable t) {
                progressBar.hideProgressDialog();
            }
        });
    }
}