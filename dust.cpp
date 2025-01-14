const int dustSensorPin = 10;
const int echoPin = 9;
const int alertBuzzer = 8;

float pulseDuration, dustDistance;

void setup() {
  pinMode(alertBuzzer, OUTPUT);
  pinMode(dustSensorPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(dustSensorPin, LOW);
  delayMicroseconds(2);
  digitalWrite(dustSensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(dustSensorPin, LOW);

  pulseDuration = pulseIn(echoPin, HIGH);
  dustDistance = (pulseDuration * 0.0343) / 2;

  delay(200);

  if (dustDistance <= 5) {
    digitalWrite(alertBuzzer, HIGH);
    delay(500);
  } else {
    digitalWrite(alertBuzzer, LOW);
  }
}
