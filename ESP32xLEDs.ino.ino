//////////////////////////////////// ARDUINO PROGRAM //////////////////////////////
//////Programming the ESP32 microcontroller to manage a traffic light system///////

#define BLYNK_TEMPLATE_ID "TMPL3QymhU0E8"
#define BLYNK_TEMPLATE_NAME "ClosedLoop Traffic system"
#define BLYNK_AUTH_TOKEN "ifUPjtzZNV1h-I7mhf2GZ89q9Lf9k5Ot"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define R1 25
#define R2 14
#define R3 21
#define R4 5
#define Y1 22
#define Y2 27
#define Y3 19
#define Y4 4
#define G1 23
#define G2 26
#define G3 18
#define G4 2
char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "Dhanu"; 
char pass[] = "Dhanu@2004";
 int Dir1;
 int Dir2;
 int Dir3;
 int Dir4;
void setup() {
 
pinMode(R1, OUTPUT);
pinMode(R2, OUTPUT);
pinMode(R3, OUTPUT);
pinMode(R4, OUTPUT);
pinMode(Y1, OUTPUT);
pinMode(Y2, OUTPUT);
pinMode(Y3, OUTPUT);
pinMode(Y4, OUTPUT);
pinMode(G1, OUTPUT);
pinMode(G2, OUTPUT);
pinMode(G3, OUTPUT);
pinMode(G4, OUTPUT);
Blynk.begin(auth, ssid, pass);
Serial.begin(115200);
}
BLYNK_WRITE(V0) {
 Dir1 = param.asInt(); 
}
BLYNK_WRITE(V1) { 
 Dir2 = param.asInt(); 
}
BLYNK_WRITE(V2) { 
 Dir3 = param.asInt(); 
}
BLYNK_WRITE(V3) { 
 Dir4 = param.asInt(); 
}
void loop() {
Blynk.run();
if(Dir1 > Dir2 && Dir1 > Dir3 && Dir1 > Dir4){
straight();
delay(10000);
}else if(Dir2 > Dir1 && Dir2 > Dir3 && Dir2 > Dir4){
back();
delay(10000);
}else if(Dir3 > Dir1 && Dir3 > Dir2 && Dir3 > Dir4){
left();
delay(10000);
}else if(Dir4 > Dir1 && Dir4 > Dir2 && Dir4 > Dir3){
right();
delay(10000);
}
}
void straight(){
digitalWrite(R1,0);
digitalWrite(Y1,1);
digitalWrite(G1,0);
digitalWrite(R2,1);
digitalWrite(Y2,0);
digitalWrite(G2,0);
digitalWrite(R3,1);
digitalWrite(Y3,0);
digitalWrite(G3,0);
digitalWrite(R4,1);
digitalWrite(Y4,0);
digitalWrite(G4,0);
delay(2500);
digitalWrite(R1,0);
digitalWrite(Y1,0);
digitalWrite(G1,1);
digitalWrite(R2,1);
digitalWrite(Y2,0);
digitalWrite(G2,0);
digitalWrite(R3,1);
digitalWrite(Y3,0);
digitalWrite(G3,0);
digitalWrite(R4,1);
digitalWrite(Y4,0);
digitalWrite(G4,0);
}
void back(){
digitalWrite(R1,1);
digitalWrite(Y1,0);
digitalWrite(G1,0);
digitalWrite(R2,0);
digitalWrite(Y2,1);
digitalWrite(G2,0);
digitalWrite(R3,1);
digitalWrite(Y3,0);
digitalWrite(G3,0);
digitalWrite(R4,1);
digitalWrite(Y4,0);
digitalWrite(G4,0);
delay(2500);
digitalWrite(R1,1);
digitalWrite(Y1,0);
digitalWrite(G1,0);
digitalWrite(R2,0);
digitalWrite(Y2,0);
digitalWrite(G2,1);
digitalWrite(R3,1);
digitalWrite(Y3,0);
digitalWrite(G3,0);
digitalWrite(R4,1);
digitalWrite(Y4,0);
digitalWrite(G4,0);
}
void left(){
digitalWrite(R1,1);
digitalWrite(Y1,0);
digitalWrite(G1,0);
digitalWrite(R2,1);
digitalWrite(Y2,0);
digitalWrite(G2,0);
digitalWrite(R3,0);
digitalWrite(Y3,1);
digitalWrite(G3,0);
digitalWrite(R4,1);
digitalWrite(Y4,0);
digitalWrite(G4,0);
delay(2500);
digitalWrite(R1,1);
digitalWrite(Y1,0);
digitalWrite(G1,0);
digitalWrite(R2,1);
digitalWrite(Y2,0);
digitalWrite(G2,0);
digitalWrite(R3,0);
digitalWrite(Y3,0);
digitalWrite(G3,1);
digitalWrite(R4,1);
digitalWrite(Y4,0);
digitalWrite(G4,0);
}
void right(){
digitalWrite(R1,1);
digitalWrite(Y1,0);
digitalWrite(G1,0);
digitalWrite(R2,1);
digitalWrite(Y2,0);
digitalWrite(G2,0);
digitalWrite(R3,1);
digitalWrite(Y3,0);
digitalWrite(G3,0);
digitalWrite(R4,0);
digitalWrite(Y4,1);
digitalWrite(G4,0);
delay(2500);
digitalWrite(R1,1);
digitalWrite(Y1,0);
digitalWrite(G1,0);
digitalWrite(R2,1);
digitalWrite(Y2,0);
digitalWrite(G2,0);
digitalWrite(R3,1);
digitalWrite(Y3,0);
digitalWrite(G3,0);
digitalWrite(R4,0);
digitalWrite(Y4,0);
digitalWrite(G4,1);
}
