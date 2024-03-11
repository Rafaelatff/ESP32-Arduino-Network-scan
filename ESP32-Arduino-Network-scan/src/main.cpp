#include <Arduino.h>
#include <WiFi.h>

// put function declarations here:
// IO
const byte blueLED = 2;  // GPIO2

//WiFI
const char* ssid = "Skynet";
const char* senha = "xxxx";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(blueLED,OUTPUT);

  WiFi.mode(WIFI_STA); // Station mode
  Serial.print("\r\n"); // new line, new carriage return
  Serial.print("Connecting to the network ");
  Serial.print(ssid);
  WiFi.begin(ssid, senha);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.println(" ");
  Serial.println("WiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Disconnects from an AP that was previously connected to perform WiFi Scan
  WiFi.disconnect();
  delay(100);
  Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(blueLED, HIGH);
  //Serial.println("Blue LED is on");
  delay(1000);
  //digitalWrite(blueLED, LOW);
  //Serial.println("Blue LED is off");
  //delay(1000);

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();

  if (n == 0) {
    Serial.println("0 network found.");
  }
  else {
    Serial.print("Number of network found = ");
    Serial.println(n);

    for (int i = 0; i < n; ++i) {
    // Displays the SSID and RSSI of each network found on the serial monitor
    Serial.print(i + 1);
    Serial.print(" - SSID: ");
    Serial.print(WiFi.SSID(i));

    Serial.print("  -  RSSI = ");
    Serial.print(WiFi.RSSI(i));
    Serial.println("");
    delay(10);
    }
  }  
}