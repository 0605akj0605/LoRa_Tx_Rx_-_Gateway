// #include <DHT_U.h>

// #define DHTPIN 5 // D1
// #define DHTTYPE DHT11 





// int h;
// int t;
// int m;
// int sensor_id = 1;  //first sensor


// int landslide_pin = 6;
// int landslide_sensor_value = 0;//

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
  
//   pinMode(landslide_pin, input);
//   landslide_sensor_value = 0;//
//   Serial.print("at\r\n");
// delay(1000);
// Serial.print("at+mode=test\r\n");
// delay(1000);
// Serial.print("AT+TEST=RFCFG, 865.0625,sf12\r\n");
// delay(1000);

// }

// void loop() {
//   // put your main code here, to run repeatedly:

//  // 
//     h = dht.readHumidity();
//     t = dht.readTemperature();
//     m = analogRead(A0);

//   landslide_sensor_value = digitalRead(landslide_pin);


// Serial.print("AT+TEST=TXLRPKT, \"0028731\"\r\n");  //first two digifts sensor number, next two digits temoerature, next two humidirty, next 1 landslide    {II,TT,HH,L}
// delay(10000);
// Serial.print("AT+TEST=TXLRPKT, \"0234930\"\r\n");
// delay(10000);

// Serial.print("AT+TEST=TXLRPKT, \"0324970\"\r\n");
// delay(10000);

// Serial.print("AT+TEST=TXLRPKT, \"BS24451\"\r\n");
// delay(10000);
// }
// // AT+TEST=RFCFG, 865.0625,sf12

#include <DHT.h>

#define DHTPIN 5 // D1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT object

int h;
int t;
int m;
int sensor_id = 1;  // first sensor

int landslide_pin = 6;
int landslide_sensor_value = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();  // Start the DHT sensor
  
  pinMode(landslide_pin, INPUT);
  Serial.print("at\r\n");
  delay(1000);
  Serial.print("at+mode=test\r\n");
  delay(1000);
  Serial.print("AT+TEST=RFCFG, 865.0625,sf12\r\n");
  delay(1000);
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  m = analogRead(A0);
  landslide_sensor_value = digitalRead(landslide_pin);

  // Handle potential NaN values
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Clamp values to 2-digit format
  int t_send = constrain(t, 0, 99);
  int h_send = constrain(h, 0, 99);
  
  
 

  // Format each component to string
  String idStr = sensor_id < 10 ? "0" + String(sensor_id) : String(sensor_id);
  String tStr = t_send < 10 ? "0" + String(t_send) : String(t_send);
  String hStr = h_send < 10 ? "0" + String(h_send) : String(h_send);
  String lStr = String(landslide_sensor_value);
   Serial.print(h_send);
  Serial.print(" =humidity  ");
  Serial.print(t_send);
  Serial.print(" =tempearure ");
  Serial.print(idStr);
  Serial.print(" =sensor id ");
  Serial.print(lStr);
  Serial.println(" =Landslide detected? ");

  // Final LoRa string
  String payload = idStr + tStr + hStr + lStr;

  // Send it via LoRa command
  Serial.print("AT+TEST=TXLRPKT, \"" + payload + "\"\r\n");

  delay(2000);  // wait before sending again
}

