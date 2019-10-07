#include <Servo.h> 
Servo servoLeft; 
Servo servoRight; 
void setup() 
{
  tone(4, 3000, 1000); 
  delay(1000); 
  Serial.begin(9600);
  servoLeft.attach(13);
  servoRight.attach(12);
}
void loop()
{

  for(int pulseWidth = 1375; pulseWidth <= 1625; pulseWidth += 25)
  {
    Serial.print("pulseWidth = ");
    Serial.println(pulseWidth);
    Serial.println("Press a key and click");
    Serial.println("Send to start servo...");
    while(Serial.available() == 0); 
    Serial.read(); 
    Serial.println("Running...");
    servoLeft.writeMicroseconds(pulseWidth); 
    servoRight.writeMicroseconds(-pulseWidth); 
    delay(6000); 
    servoLeft.writeMicroseconds(1500); 
    servoRight.writeMicroseconds(1500); 
    tone(4, 4000, 75); 
  }
}
