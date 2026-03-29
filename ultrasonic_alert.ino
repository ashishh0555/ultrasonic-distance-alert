#define trigPin 9
#define echoPin 10
#define buzzer 8
#define led1 7   // Red LED
#define led2 13  // Green LED

long duration;
int distance;

unsigned long startTime = 0;
bool objectDetected = false;

// blinking control
unsigned long previousMillis = 0;
bool ledState = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Ultrasonic trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance < 30) {

    if (!objectDetected) {
      startTime = millis();
      objectDetected = true;
    }

    if (millis() - startTime >= 3000) {

      // DANGER (<10 cm)
      if (distance < 10) {
        digitalWrite(led2, LOW);
        digitalWrite(led1, HIGH);
        tone(buzzer, 1000);
      }

      // ⚠️ WARNING (10–30 cm)
      else {
        digitalWrite(led2, LOW);

        unsigned long currentMillis = millis();

        if (currentMillis - previousMillis >= 200) {
          previousMillis = currentMillis;
          ledState = !ledState;
          digitalWrite(led1, ledState);

          if (ledState) {
            tone(buzzer, 1000);
          } else {
            noTone(buzzer);
          }
        }
      }
    }

  } else {
    // SAFE
    objectDetected = false;
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    noTone(buzzer);
  }
}
