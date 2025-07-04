package com.ludo.kheli.remote;

import com.ludo.kheli.helper.AppConstant;
import com.ludo.kheli.model.MyResponse;
import com.ludo.kheli.model.Sender;

import retrofit2.Call;
import retrofit2.http.Body;
import retrofit2.http.Headers;
import retrofit2.http.POST;

public interface APIService {
    @Headers({
            "Content-Type:application/json",
            "Authorization:key="+ AppConstant.SERVER_KEY
    })
    @POST("fcm/send")
    Call<MyResponse> sendNotification(@Body Sender body);
}

