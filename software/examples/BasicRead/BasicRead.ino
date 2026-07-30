#include <DevLab_BMI323.h>

/*
  DevLab BMI323 - Basic I2C Read

  Reads raw accelerometer and gyroscope values plus the internal temperature
  from the DevLab I2C Bosch BMI323 IMU.

  Wiring:
    BMI323 VCC -> 3.3 V or 5 V
    BMI323 GND -> GND
    BMI323 SDA -> Host SDA
    BMI323 SCL -> Host SCL

  The module uses I2C address 0x69 by default. Closing the 0x68 Add jumper
  changes the address to 0x68.
*/

#define SDA_PIN 6
#define SCL_PIN 7

DevLab_BMI323 imu(Wire, 0x69);
BMI323_SensorData data;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("==================================================");
  Serial.println(" DevLab BMI323 - Basic I2C Read");
  Serial.println("==================================================");
  Serial.println("Initializing BMI323...");

  if (!imu.begin(SDA_PIN, SCL_PIN, 400000)) {
    Serial.println("ERROR: BMI323 initialization failed.");

    while (true) {
      delay(1000);
    }
  }

  Serial.println("BMI323 initialized successfully.");
}

void loop() {
  if (imu.readData(data)) {
    Serial.println("--------------------------------------------------");

    Serial.print("Accelerometer [raw] X: ");
    Serial.print(data.accX);
    Serial.print(" Y: ");
    Serial.print(data.accY);
    Serial.print(" Z: ");
    Serial.println(data.accZ);

    Serial.print("Gyroscope [raw]     X: ");
    Serial.print(data.gyrX);
    Serial.print(" Y: ");
    Serial.print(data.gyrY);
    Serial.print(" Z: ");
    Serial.println(data.gyrZ);

    Serial.print("Temperature [C]: ");
    Serial.println(data.temperatureC, 2);
  } else {
    Serial.println("ERROR: Failed to read BMI323 data.");
  }

  delay(200);
}
