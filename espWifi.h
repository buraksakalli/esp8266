#include <ESP8266WiFi.h>
WiFiClient client;

const char* ssid = "WIFI SSID";
const char* password = "password";
const char* host = "GET or POST address";
const int httpPort = 80;

String url = "url like /dev/dht11.php";

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.print("Connecting to: ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }

    Serial.println("WiFi connected");
    Serial.println("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop(){
    Serial.print("Connecting to: ")
    Serial.println(host);
    
    if(!client.connect(host, httpPort)){
        Serial.println("Connection Failed!");
        return
    }
    
    Serial.print("Requesting URL: ");
    Serial.println(url);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: "+ host + "\r\n" + "User-Agent: BuildFailureDetectorESP8266\r\n" + "Connection: close\r\n\r\n");
    
    delay(10);
    Serial.println("Connection closing...");
}