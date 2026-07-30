# Software

The recommended software for the DevLab I²C Bosch BMI323 IMU is the
[DevLab BMI323 Arduino library](https://github.com/UNIT-Electronics-MX/unit_library_devlab_bmi323).
It provides sensor initialization, accelerometer, gyroscope, and temperature
readout, plus configuration of ranges, output data rates, filters, FIFO,
interrupts, and motion features.

## Requirements

- An Arduino-compatible board with I²C support
- Arduino IDE or PlatformIO
- The DevLab BMI323 Arduino library
- A 3.3 V or 5 V connection to the module

## Install the Library

Clone or download the library into the Arduino libraries directory:

```sh
git clone https://github.com/UNIT-Electronics-MX/unit_library_devlab_bmi323.git
```

Restart the Arduino IDE after a manual installation, then open the repository's
[`BasicRead.ino`](examples/BasicRead/BasicRead.ino) example.

## I²C Wiring

| Module | Host |
| --- | --- |
| `VCC` | 3.3 V or 5 V |
| `GND` | GND |
| `SDA` | I²C SDA |
| `SCL` | I²C SCL |

The default 7-bit address is `0x69`. Closing the `0x68 Add` jumper changes it
to `0x68`.

## Included Arduino Example

The [`BasicRead`](examples/BasicRead/BasicRead.ino) sketch follows the product
reference manual and demonstrates how to:

- Initialize the BMI323 over I²C at 400 kHz
- Verify that the sensor responds at address `0x69`
- Read raw accelerometer values
- Read raw gyroscope values
- Read the internal temperature
- Print measurements to the Serial Monitor at 115200 baud

Before uploading, change `SDA_PIN` and `SCL_PIN` in the sketch to match the
selected board.

Open the Serial Monitor at **115200 baud** after uploading. A successful
connection prints `BMI323 initialized successfully.` followed by continuous
sensor readings.

For boards with native USB, such as the ESP32-C6 used in the reference manual,
enable **USB CDC On Boot** if the serial output is not visible.

## SPI Use

The module also supports SPI at up to 10 MHz through its bottom six-pin JST SH
connector or castellated pads. Remove the `0x68 Add` jumper shunt before using
SPI. Refer to the [hardware guide](../hardware/README.md) for the complete
signal mapping.

## References

- [Product reference manual](../hardware/unit_datasheet_v_1_0_0_devlab_i2c_bosch_bmi323_imu.pdf)
- [Hardware guide](../hardware/README.md)
- [DevLab BMI323 Arduino library](https://github.com/UNIT-Electronics-MX/unit_library_devlab_bmi323)
