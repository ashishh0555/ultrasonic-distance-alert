#define trigPin 9
#define echoPin 10
#define buzzer 8
#define led1 7
#define led2 13

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance < 10) {
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    tone(buzzer, 1000); // continuous sound
  }
  else if (distance < 30) {
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    tone(buzzer, 1000);
    delay(200);
    digitalWrite(led1, LOW);
    noTone(buzzer);
    delay(200);
  }
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    noTone(buzzer);
  }

  delay(100);
}