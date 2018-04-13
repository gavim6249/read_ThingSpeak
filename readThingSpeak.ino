#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

 
const char* ssid = "your_wifi_ap_ssid";
const char* password = "your_wifi_ap_password";

// ThingSpeak information
char thingSpeakAddress[] = "api.thingspeak.com";
unsigned long channelID = 1234567;
char* readAPIKey = "WEGINOHGEYQxxxxx";
char* writeAPIKey = "Z1YAMTMSGYIxxxxx";
unsigned int myField_ID = 1;

int ledPin = LED_BUILTIN;
WiFiClient  client;

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  client = server.available();
  ThingSpeak.begin(client);
 
 
}
 
void loop() {
 
	Serial.println("OK");

 float data =  ThingSpeak.readFloatField( channelID, myField_ID, readAPIKey );
  Serial.println( " Data read from ThingSpeak: " + String( data, 9 ) );

  if(data == 1 )
  {
    digitalWrite(ledPin, LOW);
    // if Data =1, LED trun on
  }
  else
    digitalWrite(ledPin, HIGH);    
   
	delay(5000);
}
 
