
int analogPin = 0;
int modePin = 2;
int revPin = 8;
int enAPin = 7;
int in1Pin = 6;
int in2Pin = 5;
int enBPin = 12;
int in3Pin = 11;
int in4Pin = 10;
int val = 0;
bool rev = false;
bool mode = false;

void setup() {
  Serial.begin(9600);
  pinMode(modePin, INPUT); 
  pinMode(revPin, INPUT);
  pinMode(enAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enBPin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  digitalWrite(enAPin, LOW);

}

void loop() {
  val = analogRead(analogPin);
  val = map(val, 0, 1023, 0, 255);
  //mode = digitalRead(modePin);
  rev = digitalRead(revPin);
  if (digitalRead(modePin) == HIGH) {
    mode = !mode;
  }
  
  
  if (mode == false) {
    if (rev == false) {
      digitalWrite(enAPin, HIGH);
      digitalWrite(enBPin, LOW);
      analogWrite(in1Pin, val);
      digitalWrite(in2Pin, LOW);
    }  
    if (rev == true) {
      digitalWrite(enAPin, HIGH);
      digitalWrite(enBPin, LOW);
      digitalWrite(in1Pin, LOW);
      analogWrite(in2Pin, val);
    }
  }

  else if (mode == true) {
      if (rev == false) {
      digitalWrite(enBPin, HIGH);
      digitalWrite(enAPin, LOW);
      analogWrite(in3Pin, val);
      digitalWrite(in4Pin, LOW);
    }  
    if (rev == true) {
      digitalWrite(enBPin, HIGH);
      digitalWrite(enAPin, LOW);
      digitalWrite(in3Pin, LOW);
      analogWrite(in4Pin, val);
    }
  }
}



