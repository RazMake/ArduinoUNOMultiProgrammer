/*
   EEPROMSizeConfirmation

   I used this sketch to figure out the size of the EEPROM on my ESP07 board.
   I found some notes on the internet saying that it has 1MB of memory, but I wanted to make sure.
   This program has two aspects:
    1. Keeps writting to the EEPROM until it reaches the max size specified in the const.
    2. Keeps reading from the EEPROM until it reaches the max size specified in the const.
    In both cases we should not encounter any error and the values we write should be read the same way
*/

#include <EEPROM.h>
#include <Adafruit_NeoPixel.h>

// Maximum EEPROM size: --------------------------------------
#define MAXSIZE 40
// -----------------------------------------------------------

// For controlling the RGB LED: -----------------------------
// There is only one LED:
#define NUM_LEDS 1
// The pin connected to the data input of the RGB LED
#define DATA_PIN 13 // GPIO13
// ----------------------------------------------------------

// The address where to read or write from EEPROM.
int addr = 0;

// 0 = execute write test, 1 = execute read test,  2 = faulted stop executing, 3 = success stop executing
int status = 0;

// The controller for the RGB LED:
Adafruit_NeoPixel strip(NUM_LEDS, DATA_PIN, NEO_RGB + NEO_KHZ800);

// Status Colors: -------------------------------------------
// Iteration Completed Successfully:
int BLUE = strip.Color(0, 0, 255);

// Test Completed Successfully:
int GREEN = strip.Color(0, 255, 0);

// Failure encountered:
int RED = strip.Color(255, 0, 0);
// ----------------------------------------------------------

void setup() {

  Serial.begin(115200);
  
  EEPROM.begin(1024);
  strip.begin();
  strip.show();
  pinMode(LED_BUILTIN, OUTPUT);

    // To verify the colors are correct, light up the led R then G then B:
    strip.setBrightness(125);
    strip.setPixelColor(0, RED);
    strip.show();
    delay(1000);

    strip.setPixelColor(0, GREEN);
    strip.show();
    delay(1000);

    strip.setPixelColor(0, BLUE);
    strip.show();
    delay(1000);

    strip.setBrightness(0);
    strip.show();
    delay(1000);
}

void loop() {
  Serial.print("loop ");
  Serial.println(status, DEC);
  strip.setBrightness(125); // Make the LED as bright (about half possible brightness).
  if (status == 2) // Test Failed
  {
    strip.setPixelColor(0, RED);
    strip.show();
  }
  else if (status == 3) // Test completed succesfully
  {
    strip.setPixelColor(0, GREEN);
    strip.show();
  }
  else // We are not finished with the tests, continue doing them
  {
    strip.setPixelColor(0, BLUE);
    strip.show();
    if (status == 0) // Test Writes
    {
      if (!WriteToEEPROMTest(addr))
      {
        status = 2; // Failed
      }
    }
    else if (status == 1) // Test Reads
    {
      if (!ReadFromEEPROMTest(addr))
      {
        status = 2; // Failed
      }
    }

    // Advance the address being tested:
    addr = addr + 1;
    if (addr == MAXSIZE)
    {
      status = 3; // All writes completed succesfully
    }
  }

  delay(1000);

  Serial.println("OFF");
  strip.setBrightness(0);
  strip.show();
  delay(1000);
}

// The write test
bool WriteToEEPROMTest(int addr)
{
  byte value = addr % 256; // We write a value based on the address, so we can know what to expect when reading.
  Serial.print(value, DEC);
  EEPROM.write(addr, value);

   // Commit and return true = succesfull commit, false = commit failed.
   return EEPROM.commit();
}

// The read test
bool ReadFromEEPROMTest(int addr)
{
  byte value = EEPROM.read(addr);
  byte expectedValue = addr % 256;

  return value == expectedValue;
}
