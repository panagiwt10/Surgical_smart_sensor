// C++ code
//

int force_sensor =0; //μεταβλητη του αισθητηρα πιεσης 
int redPin = 10; // μεταβλητη που συνδεει το κοκκινο led
int greenPin = 8;  //μεταβλητη που συνδεει το πρασινο led
int bluePin = 9; //μεταβλητη που συνδεει το μπλε led
int buzzer = 12; 
int motorPin = 3; //για το κινητηρα δονησης 

void setup()
{
  Serial.begin(9600);
  
  pinMode(A0, INPUT); // εισοδος για τον ασιθητηρα πιεσης  
  pinMode(redPin,OUTPUT); // θεση 10 
  pinMode(greenPin,OUTPUT); // θεση 8  
  pinMode(bluePin,OUTPUT); // θεση 9 
  pinMode(buzzer,OUTPUT); // θεση 12 digital 
  pinMode(motorPin,OUTPUT); // θεση 3 μεσω npn transistor 
}

void loop()
{
  force_sensor=analogRead(A0); // διαβασε αναλογικα Α0 
  Serial.println(force_sensor); // print τιμη του force sensor
  
  if(force_sensor<=750){ 
 
    analogWrite(redPin,128); // ενεργοποιω το redpin  
    analogWrite(greenPin,0); 
    analogWrite(bluePin,128); // ενεργοποιει το blupin 
    // εχω μωβ σαν output 
    
    digitalWrite(buzzer,LOW); 
    // αν εχω τιμη <750 το buzzer ειναι ανενεργο
    
    digitalWrite(motorPin,LOW);
    // αν εχω τιμη <750 ο κινητηρας ειναι ανενεργος
  }else{
    
    //εαν η τιμη >750 τοτε: 
    analogWrite(redPin,255); //ενεργοποιω μονο το κοκκινο 
    analogWrite(greenPin,0);
    analogWrite(bluePin,0);
    
    digitalWrite(buzzer,HIGH);  //το buzzer ενεργοποιειται
    digitalWrite(motorPin,HIGH);  // το motor ενεργοποιειται
  }
  
  delay(100);
}