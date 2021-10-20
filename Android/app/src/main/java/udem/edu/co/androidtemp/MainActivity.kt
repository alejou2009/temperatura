package udem.edu.co.androidtemp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button;
import android.widget.TextView;

class MainActivity : AppCompatActivity() {

    Button buttonTemperatura;
    TextView temperaturaTexto;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }
}