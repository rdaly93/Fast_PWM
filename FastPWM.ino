void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3,100);       // Pin 3 is connected to Timer Counter 0; default f = 976 Hz
  analogWrite(11,100);      // Pin 11 is connected to Timer counter 0; default f = 976 Hz
  analogWrite(9,100);       // Pin 9 is connected to Timer Counter 1; default f = 488 Hz
  analogWrite(10,100);      // Pin 10 is connected to Timer Counter 1; default f = 488 Hz
  analogWrite(5,100);       // Pin 5 is connected to Timer Counter 3; default f = 488 Hz  
  analogWrite(6,100);       // Pin 6 is connected to Timer Counter 4; default f = 488 Hz
  analogWrite(13,100);      // Pin 13 is connected to Timer Counter 4; default f = 488 Hz
  FrequencyReader();        // Call Frequency Reader Subroutine
                            // Connect pin you want to read frequency of to analog pin 0                        
}

void FrequencyReader()
{
 unsigned long highPulse = pulseIn(A0,HIGH);  // Read the duration that the square wave is high
 unsigned long lowPulse = pulseIn(A0,LOW);    // Read the duration that the square wave is low
 float period = highPulse + lowPulse;         // Add both of these durations and it will give you the period of the square wave in microseconds
 float frequency = 1 / (period/1000000);      // f=1/T ; We divide the period by 1,000,000 to convert to seconds
 Serial.print("Frequency: ");                 // Display frequency in Serial Monitor
 Serial.print(frequency);
 Serial.println(" Hz");
}

