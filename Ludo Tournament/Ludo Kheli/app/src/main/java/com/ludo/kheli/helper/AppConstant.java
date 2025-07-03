package com.ludo.kheli.helper;

import com.ludo.kheli.remote.APIService;
import com.ludo.kheli.remote.FCMRetrofitClient;

public class AppConstant {

    // Put your api url
    public static final String API_URL = "https://ludotournament.pro/";

    // Put your purchase key
    public static final String PURCHASE_KEY = "88845214888";

    // Put your FCM server key
    public static final String SERVER_KEY = "AAAAiIyCbKM:APA91bElfMzba0ZfsPbMmRvw8Ma0CheYQz0LkdwcCLEfnwKCBLlBgzkETi8FrrqnHgs9ISP7476GkIw8TeM1xPFxdBh5UiBfWUsxEyo9LFyJGgMU8_gD1TZarGdsFUdhs3sJvOrn9fA7";

    // ************************* Below value ca be change from Admin Panel *************************

    // Put your PayTm production merchant id
    public static String PAYTM_M_ID = "XXXXXXXXXXXXXXXXXXX";

    // Put your PayU production Merchant id & key
    public static String PAYU_M_ID = "XXXXXXXXXXXX";
    public static String PAYU_M_KEY = "XXXXXXXXXXX";

    // Set default country code, currency code and sign
    public static String COUNTRY_CODE = "+880";
    public static String CURRENCY_CODE = "BDT";
    public static String CURRENCY_SIGN = "৳";

    // Set default app configuration
    public static int MAINTENANCE_MODE = 0;     // (0 for Off, 1 for On)
    public static int WALLET_MODE =  0;         // (0 for Enable, 1 for Disable)
    public static int MODE_OF_PAYMENT = 0;      // (0 for PayTm, 1 for PayU, 2 for RazorPay)

    // Set Refer Program
    public static int MIN_JOIN_LIMIT = 100;     // (In Amount)
    public static int REFERRAL_PERCENTAGE = 1;  // (In percentage)

    // Set withdraw limit (In Amount)
    public static int MIN_WITHDRAW_LIMIT = 100;
    public static int MAX_WITHDRAW_LIMIT = 5000;

    // Set deposit limit (In Amount)
    public static int MIN_DEPOSIT_LIMIT = 50;
    public static int MAX_DEPOSIT_LIMIT = 5000;

    // Set game name, package name, tutorial link and support email
    public static String GAME_NAME = "Ludo King";
    public static String PACKAGE_NAME = "com.dream.king";
    public static String SUPPORT_EMAIL = "support@ludozonebd.fun";
    public static String SUPPORT_MOBILE = "+8801970179212";
    public static String HOW_TO_PLAY = "https://youtu.be/hQcjIxpP7cc?si=dHrDHQ97EwqdY9H-";

    // ******************************* Don't change below value  ***********************************

    // PayU Production API Details
    public static final long API_CONNECTION_TIMEOUT = 1201;
    public static final long API_READ_TIMEOUT = 901;
    public static final String SERVER_MAIN_FOLDER = "";

    // global topic to receive app wide push notifications
    public static final String TOPIC_GLOBAL = "Global";

    // broadcast receiver intent filters
    public static final String PUSH_NOTIFICATION = "pushNotification";

    // FCM URL
    private static final String FCM_URL = "https://fcm.googleapis.com/";

    public static APIService getFCMService() {
        return FCMRetrofitClient.getClient(FCM_URL).create(APIService.class);
    }

    public interface IntentExtras {
        String ACTION_CAMERA = "action-camera";
        String ACTION_GALLERY = "action-gallery";
    }

    public interface PicModes {
        String CAMERA = "Camera";
        String GALLERY = "Gallery";
    }
}
