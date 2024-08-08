////// ARDUINO PROGRAM //////////////////////////////////
////// Programming the ESP32 to interface with GPS //////
#define BLYNK_TEMPLATE_ID "TMPL3QymhU0E8"
#define BLYNK_TEMPLATE_NAME "ClosedLoop Traffic system"
#define BLYNK_AUTH_TOKEN "ifUPjtzZNV1h-I7mhf2GZ89q9Lf9k5Ot"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <TinyGPS++.h>
TinyGPSPlus gps;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Dhanu";
char pass[] = "Dhanu@2004";
void setup() {
 Serial.begin(115200);
 Serial2.begin(9600, SERIAL_8N1, 16, 17);
 Blynk.begin(auth, ssid, pass);
}
void loop() {
 Blynk.run();
 while (Serial2.available() > 0) {
 if (gps.encode(Serial2.read())) {
 // Get GPS data
 float latitude = gps.location.lat();
 float longitude = gps.location.lng();
 float altitude = gps.altitude.meters();
 int satellites = gps.satellites.value();
 // Print GPS data
 Serial.print("Latitude: ");
 Serial.println(latitude, 6);
 Blynk.virtualWrite(V4, latitude, 6);
 Serial.print("Longitude: ");
 Serial.println(longitude, 6);
 Blynk.virtualWrite(V5, longitude, 6);
 Serial.print("Altitude: ");
 Serial.println(altitude);
 Serial.print("Satellites: ");
 Serial.println(satellites);
 }
 }
}
