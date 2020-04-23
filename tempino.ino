#include <Wire.h>
#include <MultiFuncShield.h>
#include <TimerOne.h>

// User Configuration
// REFRESH_RATE
//    Thermocouple reads per second / Screen refresh rate
#define REFRESH_RATE  2

// MAX6675 Thermocouple configuration
#define MAX6675_CS    6
#define MAX6675_SO    5
#define MAX6675_SCK   9

// setup()
//    Execute on arduino startup
void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1); // Initialize multi-function shield library
  startupTest();
}

// loop()
//    Main arduino loop
void loop() {
  float tempRead = readThermocouple();
  MFS.write(tempRead);
  delay(1000/REFRESH_RATE);
}

// startupTest()
//    Tests multi function shield screen segments and show delay between readings
void startupTest() {
  MFS.write("2222");
  delay(500);
  MFS.write("0000");
  delay(500);
  MFS.write("8888");
  delay(500);
  MFS.write("----");
  delay(500);
  MFS.write(1000/REFRESH_RATE);
  delay(500);
  MFS.write("----");
  delay(1000);
}

// readThermocouple()
//  Reads thermocouple current temperature in ºC
double readThermocouple() {

  uint16_t v;
  pinMode(MAX6675_CS, OUTPUT);
  pinMode(MAX6675_SO, INPUT);
  pinMode(MAX6675_SCK, OUTPUT);

  digitalWrite(MAX6675_CS, LOW);
  delay(1);

  // Read in 16 bits,
  //  15    = 0 always
  //  14..2 = 0.25 degree counts MSB First
  //  2     = 1 if thermocouple is open circuit
  //  1..0  = uninteresting status

  v = shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);
  v <<= 8;
  v |= shiftIn(MAX6675_SO, MAX6675_SCK, MSBFIRST);

  digitalWrite(MAX6675_CS, HIGH);
  if (v & 0x4)
  {
    // Bit 2 indicates if the thermocouple is disconnected
    return NAN;
  }

  // The lower three bits (0,1,2) are discarded status bits
  v >>= 3;

  // The remaining bits are the number of 0.25 degree (C) counts
  return v*0.25;
}
