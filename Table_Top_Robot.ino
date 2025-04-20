int ena =12;
int enb = 13; 
int in1 = 5 ;
int in2 = 3;
int in3 = 11;
int in4 = 6;
// trigpin = 9
// echopin = 10

const int trigpin = 9 ;
const int echopin = 10 ;
int duration ;
int distance ;

void setup() {
  pinMode(trigpin , OUTPUT);
  pinMode(echopin , INPUT);
  pinMode(ena , OUTPUT);
  pinMode(enb , OUTPUT);

  digitalWrite(ena , HIGH);
  digitalWrite(enb , HIGH);
  Serial.begin(9600);
}

  void forward(){
    analogWrite(in1 , 65);
    analogWrite(in2 , 0);
    analogWrite(in3 , 65);
    analogWrite(in4 , 0);
  }
  int revs = 1 ;
  void rotate(int revs) {
    for (int i = 0 ; i < revs ; i = i + 1) {
      analogWrite(in1 , 40);
      analogWrite(in2 , 0);
      analogWrite(in3 , 0);
      analogWrite(in4 , 40);
      delay(1000);
      analogWrite(in1 ,0);
      analogWrite(in4 ,0);
      delay(1000);
    }
  }
  void left(){
    rotate(revs);
    delay(500);
  }
// void left() {
//   analogWrite(in1 , 40);
//   analogWrite(in2 , 0);
//   analogWrite(in3 , 0);
//   analogWrite(in4 , 0);
// }

void loop() {
  
  
  digitalWrite(trigpin , LOW);
  delayMicroseconds(2);


  digitalWrite(trigpin , HIGH);
  delayMicroseconds(10);

  digitalWrite(trigpin , LOW);


  duration = pulseIn(echopin , HIGH);
  distance = (duration * 0.034) / 2 ;
  Serial.print("The Distance is in cm : "); 
  Serial.println(distance);
  if (distance > 25) {
    left();
  }
  else {
    forward();
  }
  delay(20);
}