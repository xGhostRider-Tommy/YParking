#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include "ParkingHandler.h"

const bool TESTING = false; // Set to true to enable testing code

enum Pins
{
  RX_SCANNER = 3,
  TX_SCANNER = 2,
  SERVO_PIN = 7,
  WHITE_LED_PIN = 11,
  RED_LED_PIN = 12
};

SoftwareSerial Scanner(RX_SCANNER, TX_SCANNER);
Servo MyServo;

ParkingHandler ParkingLot(ParkingHandlerSettings(6, 2)); // Price per minute: €6, Max vehicles: 2

char LastVehicle[MAX_VEHICLE_LENGTH];
size_t LastVehicleLenght;

void Test()
{
  // Servo test
  MyServo.write(0);
  delay(500);
  MyServo.write(90);
  delay(500);

  // LED test
  digitalWrite(WHITE_LED_PIN, HIGH);
  digitalWrite(RED_LED_PIN, HIGH);
  delay(500);
  digitalWrite(WHITE_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  delay(500);

  // Scanner test
  while (Scanner.available())
  {
    char c = Scanner.read();

    if (c == '\n') Serial.print("\\n");
    else if (c == '\r') Serial.print("\\r");
    else if (c == '\0') Serial.print("\\0");
    else Serial.print(c);

    Serial.print(" (");
    Serial.print((uint8_t)c);
    Serial.print(")");

    Serial.println();
  }
}

// Returns true if the vehicle was added or removed successfully,
// false if the parking lot is full
bool ProcessParkingEvent()
{
  float price = ParkingLot.HandleVehicle(LastVehicle);

  if (price == -2)
  {
    Serial.println("Parking lot is full. Cannot add vehicle.");
    return false;
  }
  else if (price == -1)
  {
    Serial.print("Vehicle '");
    Serial.print(LastVehicle);
    Serial.println("' added to the parking lot.");
  }
  else
  {
    Serial.print("Vehicle '");
    Serial.print(LastVehicle);
    Serial.println("' removed from the parking lot. Price: $" + String(price, 2));
  }
  return true;
}

void ResetLastVehicle()
{
  LastVehicleLenght = 0;
  LastVehicle[0] = '\0';
}

void ServoOpen()
{
  for (int i = 0; i <= 90; i = i + 5)
  {
    MyServo.write(i);
    delay(15);
  }

  for (int i = 0; i < 3; i++)
  {
    digitalWrite(WHITE_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    delay(1000);

    digitalWrite(WHITE_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    delay(1000);
  }
  digitalWrite(WHITE_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  for (int i = 90; i >= 0; i = i - 5)
  {
    MyServo.write(i);
    delay(15);
  }
}

void setup()
{
  MyServo.attach(SERVO_PIN);
  MyServo.write(0);

  Scanner.begin(9600);
  
  ResetLastVehicle();

  Serial.begin(9600);

  delay(1000);
  Serial.println("YParking ready!");

  if (TESTING)
  {
    Serial.println("Testing mode enabled.");
  }
}

void loop()
{
  if (TESTING)
  {
    Test();
    return;
  }

  if (Scanner.available())
  {
    char incomingChar = (char)Scanner.read();

    if (LastVehicleLenght < MAX_VEHICLE_LENGTH)
    {
      LastVehicle[LastVehicleLenght] = incomingChar;
      LastVehicleLenght++;
    }

    if (incomingChar == '\r')
    {
      LastVehicle[LastVehicleLenght - 1] = '\0';

      if (ProcessParkingEvent())
      {
        ServoOpen();
      }

      ResetLastVehicle();
    }
  }
}