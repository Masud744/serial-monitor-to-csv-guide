/*
  CSV Serial Logger Example
  -------------------------
  This example demonstrates how to print clean CSV data
  to the serial port for reliable logging using VS Code
  or any external serial terminal.

  Output Format:
  Timestamp_ms,Label,Value
*/

#include <Arduino.h>

// -------- CONFIG --------
const int MAX_LOGS = 100;   // change as needed
int logCount = 0;

// -------- CSV LOGGER --------
void logCSV(const char* label, int value) {
  if (logCount >= MAX_LOGS) return;

  Serial.print(millis());
  Serial.print(",");
  Serial.print(label);
  Serial.print(",");
  Serial.println(value);

  logCount++;

  if (logCount >= MAX_LOGS) {
    Serial.println("=== LOGGING COMPLETE ===");
  }
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  // CSV Header (important)
  Serial.println("Timestamp_ms,Label,Value");
}

void loop() {
  // Simulated data (replace with real sensor values)
  int sensorValue = random(20, 100);

  logCSV("ExampleData", sensorValue);

  delay(1000);  // log every 1 second
}
