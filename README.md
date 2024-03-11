# ESP32-Arduino-Network-scan
Repositorie created to aid my ESP32 with Arduino studies. This repositorie shall perform similar results as the one created during idf.py studies, [Network scan](https://github.com/Rafaelatff/ESP32-SCAN) and [NodeMCU Network](https://github.com/Rafaelatff/NodeMCU-PK2v2-network) (esp12e (wifi module) + ESP8266 (uC from Espressif) = NodeMCU).

## Connecting to the WiFi

I don't need to be connected to a WiFi in order to search for the available networks. But I am also using this git repositorie to post how to do it. The code for setting the ESP32 as station and connecting to a network is presented next.

```cpp
#include <Arduino.h>
#include <WiFi.h>

// put function declarations here:
// IO
const byte blueLED = 2;  // GPIO2

//WiFI
const char* ssid = "Skynet";
const char* senha = "";


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
}
```

As results:

![image](https://github.com/Rafaelatff/ESP32-Arduino-Network-scan/assets/58916022/a85daa84-50b1-455a-9efe-b019b22e4c52)

![image](https://github.com/Rafaelatff/ESP32-Arduino-Network-scan/assets/58916022/6da87492-152d-4134-8c15-b299cfa52c58)

## Scan network

The scan code is presented next:

```cpp
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

  delay(1000);
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
```

As result:

![image](https://github.com/Rafaelatff/ESP32-Arduino-Network-scan/assets/58916022/5bd37576-8011-4670-a459-71232617c35f)

## Bibliography

[](https://www.upesy.com/blogs/tutorials/how-to-connect-wifi-acces-point-with-esp32)
