int TEMPS_MAX = 12;
int TEMPS_ATT = 100;
int c = 0;
bool boutonAppuye = false;
void setup() {
  // put your setup code here, to run once:


pinMode (0, INPUT_PULLUP);//Bouton Marche
pinMode (2, OUTPUT);
pinMode (3, OUTPUT);//Moteur fwd
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
pinMode (6, OUTPUT);
pinMode (7, OUTPUT);
pinMode (8, OUTPUT);//Moteur rev
pinMode (9, OUTPUT);//moteur enable
pinMode (10, OUTPUT);
pinMode (11, OUTPUT);
pinMode (12, OUTPUT);
pinMode (A0, OUTPUT);
pinMode (A1, OUTPUT);
pinMode (A2, OUTPUT);
pinMode (A3, OUTPUT);
pinMode (A4, INPUT_PULLUP);//Bouton Reverse
digitalWrite (9, HIGH);};

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead (0) == LOW){
  boutonAppuye = true;}
if (boutonAppuye){
c ++;
if (c < 10 * TEMPS_MAX){
  digitalWrite (3, HIGH);
  if (digitalRead (A4) == HIGH){
    digitalWrite (8, HIGH);
    digitalWrite (3, LOW);}
  else{digitalWrite(8, LOW);
  digitalWrite (3, HIGH);}
  }
else {digitalWrite (8, LOW);
    digitalWrite (3, LOW);}
if (c%12 == 0){
  digitalWrite(5, HIGH);
digitalWrite (A2, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 1){
  digitalWrite(A1, HIGH);
digitalWrite (5, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 2){
  digitalWrite(A3, HIGH);
digitalWrite (A1, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 3){
  digitalWrite(10, HIGH);
digitalWrite (A3, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 4){
  digitalWrite(6, HIGH);
digitalWrite (10, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 5){
  digitalWrite(11, HIGH);
digitalWrite (6, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 6){
  digitalWrite(7, HIGH);
digitalWrite (11, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 7){
  digitalWrite(4, HIGH);
digitalWrite (7, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 8){
  digitalWrite(12, HIGH);
digitalWrite (4, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 9){
  digitalWrite(2, HIGH);
digitalWrite (12, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 10){
  digitalWrite(A0, HIGH);
digitalWrite (2, LOW);
delay (TEMPS_ATT);}
else if (c%12 == 11){
  digitalWrite(A2, HIGH);
digitalWrite (A0, LOW);
delay (TEMPS_ATT);}}}
