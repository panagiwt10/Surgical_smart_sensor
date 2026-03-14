// C++ code

int force_sensor = 0; // force sensor variable
int redPin = 10;      // pin connected to the red LED
int greenPin = 8;     // pin connected to the green LED
int bluePin = 9;      // pin connected to the blue LED
int buzzer = 12;      // pin connected to the buzzer
int motorPin = 3;     // pin for the vibration motor

void setup()
{
  Serial.begin(9600);
  
  pinMode(A0, INPUT);         // analog input for the force sensor
  pinMode(redPin, OUTPUT);    // digital pin 10
  pinMode(greenPin, OUTPUT);  // digital pin 8
  pinMode(bluePin, OUTPUT);   // digital pin 9
  pinMode(buzzer, OUTPUT);    // digital pin 12
  pinMode(motorPin, OUTPUT);  // digital pin 3 via an NPN transistor
}

void loop()
{
  force_sensor = analogRead(A0); // read analog value from A0
  Serial.println(force_sensor);  // print the force sensor value to the Serial Monitor
  
  if(force_sensor <= 750){ 
 
    analogWrite(redPin, 128);  // activate the red LED (partial brightness)
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 128); // activate the blue LED (partial brightness)
    // this creates a purple color output
    
    digitalWrite(buzzer, LOW); 
    // if the value is <= 750, the buzzer remains inactive
    
    digitalWrite(motorPin, LOW);
    // if the value is <= 750, the vibration motor remains inactive
  } else {
    
    // if the value is > 750 then: 
    analogWrite(redPin, 255); // activate only the red LED (full brightness)
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    
    digitalWrite(buzzer, HIGH);   // the buzzer is activated
    digitalWrite(motorPin, HIGH); // the vibration motor is activated
  }
  
  delay(100); // short delay for stability
}
