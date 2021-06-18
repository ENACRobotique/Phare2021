int TEMPS_MAX = 12;
int TEMPS_ATT = 100;

#include <FastLED.h>

#define NbLED 30
int c = 0;
bool boutonAppuye = false;
bool versBas = false;
int LEDaAllumer=0;
int LEDaEteindre=NbLED-1;
CRGB leds[NbLED];

void setup() {
  // put your setup code here, to run once:

pinMode (0, INPUT_PULLUP);//Bouton Marche
pinMode (2, OUTPUT);//LED data pin
FastLED.addLeds<WS2812B, 2, RGB>(leds, NbLED);
pinMode (3, OUTPUT);//Moteur fwd
pinMode (8, OUTPUT);//Moteur rev
pinMode (9, OUTPUT);//moteur enable
pinMode (A4, INPUT_PULLUP);//ContactBas
pinMode (A5, INPUT_PULLUP);//ContactHaut
digitalWrite (9, HIGH);
versBas = digitalRead (A5)==LOW;};

void loop() {
  c++;
  // put your main code here, to run repeatedly:
  if (digitalRead (0)==LOW){
  boutonAppuye = true;};
  
  if (boutonAppuye) {
    if (versBas and digitalRead (A4)==LOW){
      digitalWrite(8,LOW);}
    else if (versBas and digitalRead (A4)==HIGH){
      digitalWrite (8,HIGH);}
    else if  ((not versBas) and digitalRead (A5)==HIGH){
      digitalWrite (3,HIGH);}
    else {digitalWrite (3,LOW);};
   LEDaEteindre = LEDaAllumer;
   LEDaAllumer = c%NbLED;
   leds[LEDaAllumer]=CRGB::White;
   leds[LEDaEteindre]=CRGB::Black;
   FastLED.show();
   
    };
    delay(100);
}
