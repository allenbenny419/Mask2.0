// defines pins numbers
int val;
int tempPin = 1;
int trigPin = 9;
int echoPin = 10;
#define TILT 2 // pin 2 for front-left sensor
#define LED 13 // pin 3 for front-right sensor


void setup() {
  Serial.begin(9600); 
   pinMode(13, OUTPUT);
   pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);// Sets the echoPin as an Input
  pinMode(TILT, INPUT);//define Data input pin input pin
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)*0.034;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("CM");
  delay(10);


//--------
  if((distance<=100)) 
  {
    Serial.print("Person Near...Stay Back ");
    digitalWrite(13,HIGH);
}
   else if(distance>100)
 {
     digitalWrite(13,LOW);
   }
//--------
  val = analogRead(tempPin);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);
  if((cel>=32)) 
  {
    Serial.println("high temp");
    digitalWrite(13,HIGH);
}
   else if(cel<100)
 {
     digitalWrite(13,LOW);
   }
  //--------------------------tiltsensor part
int TILT_SENSED = digitalRead(TILT);// read TILT sensor

  // if tilt is sensed
  if( TILT_SENSED ==LOW)
  {
    digitalWrite(13,HIGH);// set the LED pin HIGH 
    Serial.println("Mask Tilted");
  }else{
    digitalWrite(13,LOW); // Set the LED pin LOW
    Serial.println("Normal");
  }

  delay(10);
}
   
