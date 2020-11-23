//Version 0.1.2 11/23/2020

#define Pump 6
#define LED 13

int power = 80;
bool initialized = false;
bool calibrated = false;
int a = 0;
int LED_power = 0;

void setup() {
  pinMode(Pump, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  while(!initialized){
    a = analogRead(A0);
    LED_power = map(a, 0, 1023, 0, 255);
    analogWrite(LED, LED_power); 
    if (a > 1020){
      initialized = true;
    }
  }
  analogWrite(LED, 0); 
  analogWrite(Pump, 250);
  Serial.println("Power up ESC."); 
  while(!calibrated){
    a = analogRead(A0);
    power = map(a, 0, 1023, 0, 250);
    analogWrite(Pump, power);
    if (power < 2){
      calibrated = true;
    }
  }
  Serial.println("Pump started."); 

}

void loop() {
  a = analogRead(A0);
  power = map(a, 0, 1023, 0, 250);
  analogWrite(Pump, power);
  LED_power = map(a, 0, 1023, 0, 255);
  analogWrite(LED, LED_power);
}
