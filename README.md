# Welcome to YParking!

Hi! This is a school project. We have decided to create a simplified and basic **parking software** with a **Arduino**.
Written in **C++ (Arduino)** using the **Platform IO** extension in **VS Code**.


# Run

## Requirements
### Software
- **Visual Studio Code**
- The following VS Code **Extensions**: [C/C++ (by Microsoft)](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) and [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
### Hardware
- An **Arduino UNO** board
- An **External Power supply** board for Arduino with at least **one 5V and GND**
- **Servo** for Arduino
- **GR65 Reader QR Code** Scanner

## Pin Configuration
### Servo Motor
| Wire Color | Function | Arduino Pin |
| ---------- | -------- | ----------- |
| Orange     | Signal   | D7          |
| Red        | Power    | 5V          |
| Brown      | Ground   | GND         |
### QR Code Scanner
| Wire Color | Function  | Arduino Pin |
| ---------- | --------- | ----------- |
| Red        | Power     | 5V          |
| Green      | Ground    | GND         |
| Black      | TX / Data | D3          |
| Yellow     | RX / Data | D2          |
### Red LED
| LED Pin             | Connection |
| ------------------- | ---------- |
| Anode (long leg)    | D12        |
| Cathode (short leg) | GND        |
### White LED
| LED Pin             | Connection |
| ------------------- | ---------- |
| Anode (long leg)    | D11        |
| Cathode (short leg) | GND        |

## QR Code Scanner Configuration
- **Connect** the board
- Make sure the scanner is properly **connected**. You should hear a **sound**, see a **red indicator** light, and notice a brief **flash of light**.
- **Scan** the QR Codes in the [Tutorial File](./TutorialResetQRCodeScanner.pdf) and make sure you hear a **sound** after every scan.

## Testing
To test that everything works you can enable the **testing code** by setting the `TESTING` constant in [main.cpp](./src/main.cpp) to `true`. You can find this constant near the top of the file.
The LED lights should start **blinking**, the Servo Motor should **open and close** and the QR Code scanner should **print every character** it reads.

## Running
- **Compile** and **upload** the program to **Arduino**
- Enable the **Serial Monitor**


**NOTE**: To my knowledge, this project cannot be run using the official *Arduino* IDE, as it uses multiple source files.
