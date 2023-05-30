# Toilet Roll Inator

The Toilet Roll Inator is an Arduino-based project that monitors the status of a toilet paper roll and plays an MP3 audio file when the roll is empty. It uses a phototransistor and a tilt ball sensor to detect the level of the toilet paper roll.

## Requirements

- Arduino board
- SoftwareSerial library
- DFRobotDFPlayerMini library

## Circuit Connections

- RX of DFPlayer Mini to Arduino pin 10
- TX of DFPlayer Mini to Arduino pin 11
- Phototransistor output to Arduino analog pin A0
- Tilt ball sensor output to Arduino digital pin 12

## Installation

1. Connect the circuit as per the circuit connections mentioned above.
2. Install the Arduino IDE if not already installed.
3. Install the required libraries by navigating to "Sketch -> Include Library -> Manage Libraries" in the Arduino IDE. Search for "SoftwareSerial" and "DFRobotDFPlayerMini" and install the libraries.
4. Upload the code to the Arduino board.

## Usage

1. Power on the Arduino board.
2. Open the serial monitor in the Arduino IDE to view the sensor values and status messages.
3. Place the phototransistor near the toilet paper roll to detect the light level.
4. Make sure the tilt ball sensor is attached to the toilet paper roll in a way that it closes the circuit when the roll is present and opens the circuit when the roll is empty.
5. The Toilet Roll Inator will monitor the light level and tilt ball sensor state to determine if the toilet paper roll is empty.
6. When the roll is empty, it will play an MP3 audio file using the DFPlayer Mini.
7. The volume level of the MP3 can be adjusted by modifying the `volumeLevel` constant in the code.

Note: The code assumes that you have connected the DFPlayer Mini and the sensors as per the circuit connections mentioned. If you have used different pins, make sure to update the pin numbers in the code accordingly.

## License

This project is licensed under the [MIT License](LICENSE).
