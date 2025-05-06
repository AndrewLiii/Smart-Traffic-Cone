#include <Arduino.h>

HardwareSerial SerialPort(2);

void setup() {
  Serial.begin(115200);                         // Monitor baud rate (leave this at 115200)
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);   // Match GNSS module's baud rate

  delay(1000);
  Serial.println("Initializing GNSS...");

  SerialPort.println("AT");            // Check if module is alive
  delay(1000);
  SerialPort.println("AT+CGNSPWR=1");  // Turn on GNSS
  delay(1000);
  SerialPort.println("AT+CGNSINF");    // Request GNSS info
}

void loop() {
  while (SerialPort.available()) {
    char c = SerialPort.read();
    Serial.write(c); // Echo GNSS module response to USB monitor
  }
}
