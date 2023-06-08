/*
  Toilet Paper Roll Monitor
  This code uses a phototransistor to detect if the toilet paper roll is empty.
  If the phototransistor detects light and the tilt ball sensor is closed, it triggers the passive buzzer.
  The buzzer will beep every 5 seconds.
  The buzzer stops if the tilt ball sensor is opened and then closed and toilet paper roll is not empty.
*/

const int phototransistorPin = A0;
const int tiltBallSensorPin = 12;
const int passiveBuzzerPin = 13;

// Light threshold and time variables
const int lightThreshold = 105;
const unsigned long buzzerInterval = 5000; // 5 seconds
const unsigned long buzzerBeepDuration = 500; // 0.5 seconds

// State variables
bool isTiltSensorOpen = false;
bool toiletPaperRollEmpty = false;
unsigned long buzzerStartTime = 0;
bool buzzerActive = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  pinMode(phototransistorPin, INPUT);
  pinMode(tiltBallSensorPin, INPUT_PULLUP);
  pinMode(passiveBuzzerPin, OUTPUT);
}

void loop() {
  // Read phototransistor and tilt ball sensor values
  int lightLevel = analogRead(phototransistorPin);
  bool tiltSensorState = digitalRead(tiltBallSensorPin);

  // Print sensor values
  Serial.print("Phototransistor value: ");
  Serial.println(lightLevel);
  Serial.print("Tilt ball sensor value: ");
  Serial.println(tiltSensorState ? "HIGH" : "LOW");

  // Check if the tilt ball sensor is open
  if (tiltSensorState == HIGH) {
    isTiltSensorOpen = true;
  }

  // Check if the tilt ball sensor is closed
  if (tiltSensorState == LOW && isTiltSensorOpen) {
    isTiltSensorOpen = false;
    if (!toiletPaperRollEmpty) {
      buzzerActive = false;
    }
  }

  // Check if the light level is below the threshold and the tilt sensor is closed (default state)
  if (lightLevel < lightThreshold && tiltSensorState == LOW) {
    toiletPaperRollEmpty = true;
  } else {
    toiletPaperRollEmpty = false;
  }

  // Print toiletPaperRollEmpty value
  Serial.print("Toilet paper roll empty: ");
  Serial.println(toiletPaperRollEmpty ? "true" : "false");

  // Control the buzzer based on toiletPaperRollEmpty and tilt sensor state
  if (toiletPaperRollEmpty && !buzzerActive) {
    buzzerActive = true;
    buzzerStartTime = millis();
  }

  if (buzzerActive) {
    if (millis() - buzzerStartTime >= buzzerInterval) {
      buzzerStartTime = millis();
      tone(passiveBuzzerPin, 1000, buzzerBeepDuration); // Play a 1000Hz tone for 0.5 seconds
    }
  } else {
    buzzerStartTime = 0;
    noTone(passiveBuzzerPin);
  }

  delay(1000); // Add a delay to reduce the frequency of sensor readings and printouts
}
