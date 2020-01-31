

#ifndef STASSID
#define STASSID "INFINITUM9C9E_2.4"
#define STAPSK  "dfJAF3Q5bg"
#endif


#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <functional>
#include <Wire.h>

// prototypes
boolean connectWifi();

//on/off callbacks 
void kitchenLightsOn();
void kitchenLightsOff();

// Change this before you flash
//#######################################
const char* ssid     = STASSID; //enter your ssid/ wi-fi(case sensitive) router name - 2.4 Ghz only
const char* password = STAPSK;     // enter ssid password (case sensitive)

boolean wifiConnected = false;



void setup()
{
  Serial.begin(115200);
  // Initialise wifi connection
  wifiConnected = connectWifi();
  
  if(wifiConnected){
    Serial.println("conectado");
  }
  Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
}
 
void loop(){
   if(wifiConnected){
      kitchenLightsOn();
      delay(1000);
      kitchenLightsOff();
      delay(1000);
   }
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//      Arduino Uno Switch on / off
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void kitchenLightsOn() {
    Serial.print("Switch 2 turn on ...");
      Wire.beginTransmission(8); /* begin with device address 8 */
      Wire.write("{\"gpio\":11,\"state\":1}");  /* sends hello string */
      Wire.endTransmission();    /* stop transmitting */
}

void kitchenLightsOff() {
  Serial.print("Switch 2 turn off ...");
    Wire.beginTransmission(8); /* begin with device address 8 */
    Wire.write("{\"gpio\":11,\"state\":0}");  /* sends hello string */
    Wire.endTransmission();    /* stop transmitting */
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting ...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 10){
      state = false;
      break;
    }
    i++;
  }
  
  if (state){
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("");
    Serial.println("Connection failed.");
  }
  
  return state;
}
