#define pushB 2
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration;
int distance;

const int trigpin=9;
const int echopin=10;
int solinoid=13;
int solenoidPin = 4;


int x=40,y;
void setup() {
 Serial.begin(9600);
 Serial.setTimeout(1);
  pinMode(pushB,INPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(solenoidPin, OUTPUT); 
}
void loop() {
 while (!Serial.available());
 x = Serial.readString().toInt();
 y = Serial.readString().toInt();
 digitalWrite(13,HIGH);
 Serial.print(x + 1, y+1);
 
 digitalWrite(pushB,HIGH);
  if(digitalRead(pushB)==LOW){
    Serial.println("Pressed");
    delay(300);
    
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
  if((distance<=10))
  {
    digitalWrite(solinoid, HIGH);
    
  }
  else if(distance>10)
  {
    digitalWrite(solinoid, LOW);
  }
  }

  digitalWrite(solenoidPin, HIGH); //Switch Solenoid ON
  delay((x%10)*1000); //Wait 1 Second
  digitalWrite(solenoidPin, LOW); //Switch Solenoid OFF
  
  }
