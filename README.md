# Welcome to YParking!

Hi! This is a school project. We have decided to create a simplified and basic **parking software** with a **Arduino**.
Written in **C++ (Arduino)** using the **Platform IO** extension in **VS Code**.


# Run

## Requirements
### Software
- **Visual Studio**
- The following VS Code **Extensions**: **C/C++ Extension Pack** and **PlatformIO**
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

## Running
- **Compile** and **upload** the program to **Arduino**
- Enable the **Serial Monitor**


**NOTE**: As long as I know, this project CANNOT be run via the official *Arduino* software as this project uses more than one file for the project
