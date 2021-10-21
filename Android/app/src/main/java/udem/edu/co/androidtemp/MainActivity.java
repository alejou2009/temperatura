package udem.edu.co.androidtemp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

public class MainActivity extends AppCompatActivity {

    Button btnTemp;
    TextView textViewTemp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnTemp = findViewById(R.id.btnTemp);
        textViewTemp = findViewById(R.id.textViewTemp);

        btnTemp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                LeerRest();
            }
        });
    }

    private void LeerRest(){
        String url = "http://172.20.10.7:3000";

        StringRequest getRequest = new StringRequest(Request.Method.GET, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                try {
                    JSONObject jsonObject = new JSONObject(response);
                    String temp = jsonObject.getString( "temperatura");
                    textViewTemp.setText(temp);
                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

            }
        });
        Volley.newRequestQueue(this).add(getRequest);
    }
}