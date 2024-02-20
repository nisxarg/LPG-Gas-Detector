// Define pins
const int GAS_SENSOR_PIN = A0;
const int GREEN_LED_PIN = 11;
const int RED_LED_PIN = 12;

void setup() {
  // Set up pins
  pinMode(GAS_SENSOR_PIN, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read gas sensor value
  int gasValue = analogRead(GAS_SENSOR_PIN);
  Serial.println(gasValue);

  // Check gas level and display status
  if (gasValue > 500) {
    displayStatus("LPG Detected", GREEN_LED_PIN, RED_LED_PIN);
  } else {
    displayStatus("LPG Not Detected", RED_LED_PIN, GREEN_LED_PIN);
  }
  
  delay(10);
}

void displayStatus(const char* message, int onPin, int offPin) {
  // Print the message
  Serial.println(message);

  // Switch LEDs
  digitalWrite(onPin, HIGH);
  digitalWrite(offPin, LOW);
}
