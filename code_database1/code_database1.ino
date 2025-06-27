// #include <DHT_U.h>

// #include "DHT.h" // DHT sensor library by Adafruit
// #include <ESP8266WiFi.h>
// #include <WiFiClientSecure.h>
// #include <ESP8266HTTPClient.h>

// #define DHTPIN 5 // D1
// #define DHTTYPE DHT11 

// // Replace with your network credentials
// const char* ssid     = "AKJ";
// const char* password = "lovelybee";

// // supabase credentials
// // String API_URL = "https://drdzwhglmztngibdlmdq.supabase.co";
// // String API_KEY = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImRyZHp3aGdsbXp0bmdpYmRsbWRxIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NDk4MjU3NzAsImV4cCI6MjA2NTQwMTc3MH0.wzIUu1Ng3w40w5OIU_1vW-TeE26T6Uxxf3X-BSnf3og";
// // String TableName = "sensor_data2";

//     int id=1;
// int sensor_id=1;
// float temperature=23.9,humidity=45.9;
// int landslide=1;
// int rssi=80;
// int snr=20;
// float latitude=1.2464464;
// float longitude=3.23564533;


// #define supabaseUrl  "https://bxctpsgodrikiqjildog.supabase.co/"
// #define tableRealtime  "sensor_data"
// #define supabaseApiKey "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImJ4Y3Rwc2dvZHJpa2lxamlsZG9nIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NDk0NjYwNDMsImV4cCI6MjA2NTA0MjA0M30.7d0y1pmjADqUzk0voqenYwx3jAtVZo5ZK3gKCq4oU30"
// String API_URL = supabaseUrl;
// String API_KEY = supabaseApiKey;
// String TableName = tableRealtime;
// const int httpsPort = 443;

// // Sending interval of the packets in seconds
// int sendinginterval = 1200; // 20 minutes
// //int sendinginterval = 120; // 2 minutes

// HTTPClient https;
// WiFiClientSecure client;
// DHT dht(DHTPIN, DHTTYPE);

// float h;
// float t;
// int m;

// void setup() {
//   // builtIn led is used to indicate when a message is being sent
//   pinMode(LED_BUILTIN, OUTPUT);
//   digitalWrite(LED_BUILTIN, HIGH); // the builtin LED is wired backwards HIGH turns it off

//   // HTTPS is used without checking credentials 
//   client.setInsecure();

//   // Connect to the WIFI 
//   Serial.begin(115200);
//   dht.begin();
  
//   Serial.print("Connecting to ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
  
//   // Print local IP address
//   Serial.println("");
//   Serial.println("WiFi connected.");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());



// }

// void loop() {

//    // If connected to the internet turn the Builtin led On and attempt to send a message to the database 
//   if (WiFi.status() == WL_CONNECTED) {
//     digitalWrite(LED_BUILTIN, LOW); // LOW turns ON

//     // Read all sensors
//     h = dht.readHumidity();
//     t = dht.readTemperature();
//     m = analogRead(A0);
     
 
//     // Send the a post request to the server
//     https.begin(client,API_URL+"/rest/v1/"+TableName);
//     https.addHeader("Content-Type", "application/json");
//     https.addHeader("Prefer", "return=representation");
//     https.addHeader("apikey", API_KEY);
//     https.addHeader("Authorization", "Bearer " + API_KEY);
//  //   int httpCode = https.POST("{\"temperature\":" + String(t)+ ",\"humidity\":"+ String(h)+",\"moisture\":" + String(1024 - m)+"}" );   //Send the request//
//     // int httpCode = https.POST("{\"id\":" + String(id) + 
//     //                       ",\"temperature\":" + String(t) + 
//     //                       ",\"humidity\":" + String(h) + 
//     //                       ",\"landslide\":" + String(landslide) + 
//     //                       ",\"rssi\":" + String(rssi) + 
//     //                       ",\"snr\":" + String(snr) + 
//     //                       ",\"latitude\":" + String(latitude, 6) + 
//     //                       ",\"longitude\":" + String(longitude, 6) + 
//     //                       "}");
   
//     int httpCode = https.POST("{\"id\":" + String(id) + 
//                           ",\"sensor_id\":\"" + String(sensor_id) + "\"" + 
//                           ",\"temperature\":" + String(t) + 
//                           ",\"humidity\":" + String(h) + 
//                           ",\"landslide\":" + String(landslide) + 
//                           ",\"rssi\":" + String(rssi) + 
//                           ",\"snr\":" + String(snr) + 
//                           ",\"latitude\":" + String(latitude, 6) + 
//                           ",\"longitude\":" + String(longitude, 6) + 
//                           "}");

//     String payload = https.getString(); 
//     Serial.println(httpCode);   //Print HTTP return code
//     Serial.println(payload);    //Print request response payload
//     https.end();

    
//     digitalWrite(LED_BUILTIN, HIGH); // HIGH turns off
//   }else{
//     Serial.println("Error in WiFi connection");
//   }
//   delay(1000*sendinginterval);  //wait to send the next request
//   id++;
// }

#include <time.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
//#include <SupabaseArduino.h>

#define SSID      "AKJ"
#define PASSWORD  "lovelybee"

// Replace with your network credentials
const char* ssid     = "AKJ";
const char* password = "lovelybee";


#define supabaseUrl  "https://bxctpsgodrikiqjildog.supabase.co/"
#define tableRealtime  "sensor_data"
#define supabaseApiKey "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImJ4Y3Rwc2dvZHJpa2lxamlsZG9nIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NDk0NjYwNDMsImV4cCI6MjA2NTA0MjA0M30.7d0y1pmjADqUzk0voqenYwx3jAtVZo5ZK3gKCq4oU30"


String API_URL = supabaseUrl;
String API_KEY = supabaseApiKey;
String TableName = tableRealtime;
const int httpsPort = 443;

// Sending interval of the packets in seconds
int sendinginterval = 5; // 20 minutes
//int sendinginterval = 120; // 2 minutes

HTTPClient https;
WiFiClientSecure client;


int id;
int sensor_id;
float temperature,humidity;
int landslide;
int rssi;
int snr;
float latitude;
float longitude;


void setup() {
 Serial.println("Starting please wait");
   pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // the builtin LED is wired backwards HIGH turns it off

  // HTTPS is used without checking credentials 
  client.setInsecure();


  // put your setup code here, to run once:
  Serial.begin(9600);
  // Supabase supabase(SSID, PASSWORD,supabaseUrl ,tableRealtime ,tableRealtime);
  //  supabase.begin();

  //  delay(500);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  // Print local IP address
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("at\r\n");
  delay(1000);
  Serial.print("at+mode=test\r\n");
  delay(1000);
  Serial.print("AT+TEST=RFCFG, 865.0625,sf12\r\n");
  delay(1000);
  Serial.print("AT+TEST=RXLRPKT");

 id=random();
//  sensor_id=2;
//  temperature=23,humidity=45;
//  landslide=1;
//  rssi=80;
//  snr=20;

 latitude=25.672245177321727;
 longitude=91.9113144431422;

}





// void parseRSSIandSNR(char* input) {
//   char* token = strtok(input, ",");  // split by comma
//   int rssi = 0;
// int snr = 0;

//   while (token != NULL) {
//     if (strstr(token, "RSSI:") != NULL) {
//       rssi = atoi(token + 6); // skip "RSSI:" (5 chars + 1 space)
//     } else if (strstr(token, "SNR:") != NULL) {
//       snr = atoi(token + 5); // skip "SNR:" (4 chars + 1 space)
//     }

//     token = strtok(NULL, ",");
//   }

//   Serial.print("RSSI: ");
//   Serial.println(rssi);
//   Serial.print("SNR: ");
//   Serial.println(snr);
// }

void parseInput(char* input) {
 // int rssi = 0, snr = 0;
 // int sensor_id = 0, temperature = 0, humidity = 0, landslide = 0;

  // ----- Extract RSSI -----
  char* rssiPtr = strstr(input, "RSSI:");
  if (rssiPtr != NULL) {
    rssi = atoi(rssiPtr + 5);  // skip "RSSI:"
  }

  // ----- Extract SNR -----
  char* snrPtr = strstr(input, "SNR:");
  if (snrPtr != NULL) {
    snr = atoi(snrPtr + 4);  // skip "SNR:"
  }

  // ----- Extract RX payload -----
  char* rxPtr = strchr(input, '"');  // find the first double quote
  if (rxPtr != NULL && strlen(rxPtr) >= 9) {
    char sensorData[9] = {0};  // 8 digits + null
    strncpy(sensorData, rxPtr + 1, 8);  // copy 8 digits

    sensor_id = (sensorData[1] - '0') * 10 + (sensorData[2] - '0');
    temperature  = (sensorData[3] - '0') * 10 + (sensorData[4] - '0');
    humidity     = (sensorData[5] - '0') * 10 + (sensorData[6] - '0');
    landslide    = (sensorData[7] - '0') ;
  }

  // ----- Print results -----
  Serial.print("RSSI: ");
  Serial.println(rssi);
  Serial.print("SNR: ");
  Serial.println(snr);

  Serial.print("Sensor #: ");
  Serial.println(sensor_id);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Landslide detected: ");
  Serial.println(landslide == 1 ? "YES" : "NO");


  // supabase.update(1, "temperature", 234);
  // supabase.update(1, "humidity", 12);
}


void loop() {
  // put your main code here, to run repeatedly:
int startTime= millis();
int timeoutMs=4000;
char recvBuffer[100];
 while(millis()-startTime< timeoutMs)
{
 int index = 0;
 while(Serial.available() >0 && index < sizeof(recvBuffer)-1) {
    recvBuffer [index++] = Serial.read();
 //   Serial.print(recvBuffer[index-1]);
    delay(1);
 }
}


for(int i = 0;i<50;i++)
{
  if(i==0)
  Serial.println("-------------------");
Serial.print(recvBuffer[i]);

 if(i==99)
 {
  Serial.println("");
Serial.println("-------------------");
 }

//delay(20);
}


Serial.println();
parseInput(recvBuffer);

 if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW); // LOW turns ON
    https.begin(client,API_URL+"/rest/v1/"+TableName);
    https.addHeader("Content-Type", "application/json");
    https.addHeader("Prefer", "return=representation");
    https.addHeader("apikey", API_KEY);
    https.addHeader("Authorization", "Bearer " + API_KEY);
    
      int httpCode = https.POST("{\"id\":" + String(id) + 
                          ",\"sensor_id\":\"" + String(sensor_id) + "\"" + 
                          ",\"temperature\":" + String(temperature) + 
                          ",\"humidity\":" + String(humidity) + 
                          ",\"landslide\":" + String(landslide) + 
                          ",\"rssi\":" + String(rssi) + 
                          ",\"snr\":" + String(snr) + 
                          ",\"latitude\":" + String(latitude, 6) + 
                          ",\"longitude\":" + String(longitude, 6) + 
                          "}");
 
 String payload = https.getString(); 
    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
    https.end();

    
    digitalWrite(LED_BUILTIN, HIGH); // HIGH turns off
  }else{
    Serial.println("Error in WiFi connection");
  }
  delay(1000*sendinginterval);  //wait to send the next request
  id++;



delay(8000);
}
