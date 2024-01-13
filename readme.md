# arduino-tempino

``` Descontinued, should still work ```

![Arduino connection sketch](https://github.com/eduardomota/arduino-tempino/raw/master/assets/sketch.svg)

Demonstration thermometer application with arduino uno, multi function shield, and max6675 thermocouple. Measures current temperature with good accuracy up to one (1) decimal place. You can extend the thermometer to use more of the shields capabilities such as  buttons, buzzer, leds, and potentiometer/trimpot.

## Parts Needed

- 1x Arduino Uno
- 1x Multi Function Shield
- 1x Thermocouple MAX6675
- 1x Thermocouple Probe
- 1x USB2 Type B Cable
- 5x Jumper Cables (probably Female-Female)
- 1x Power bank with USB (optional)

## Quick Start

1. Download and install Arduino software IDE and libraries needed for the project;
2. Build Arduino Uno with multi function shield and thermocouple according to the sketch;
3. Git clone this project or just download `tempino.ino`;
4. Adjust temperature readings per second to your preferred value with `REFRESH_RATE` inside `tempino.ino`;
5. Connect your built Arduino to the computer;
6. On Arduino IDE select board type (if not selected) and port;
7. Send `tempino.ino` to Arduino;
8. Enjoy

## Libraries

This project uses 3 libraries, you can find a copy of each inside `libs` folder or at the addresses below.

- TimerOne (included in Arduino IDE), [GitHub PaulStoffregen](https://github.com/PaulStoffregen/TimerOne)

- Wire (included in Arduino IDE), [GitHub Arduino Official](https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/Wire)

- MultiFuncShield, [Cohesivecomputing website](https://files.cohesivecomputing.co.uk/MultiFuncShield-Library-1_3.zip)

## Brief Q&A

Q.: My screen shows NaN, how can i solve it?

A.: There's probably bad contact somewhere, refit every connection and try again. If it persists replace connection cables, as last resort change the thermocouple.

Q.: My thermocouple is not working correctly, what can i do?

A.: Buy more than one piece of each item to make sure you're able to troubleshoot any defective parts correctly, have in hand at least two times (2x) more of each needed part.

## Where to buy parts

- Arduino Uno

[Arduino Official Store](https://store.arduino.cc/arduino-uno-rev3) / [AliExpress](https://www.aliexpress.com/wholesale?SearchText=arduino+uno) / [eBay](https://www.ebay.com/sch/i.html?_nkw=arduino+uno)

- Multi Function Shield

[AliExpress](https://www.aliexpress.com/wholesale?SearchText=multi+function+shield) / [eBay](https://www.ebay.com/sch/i.html?_nkw=arduino+multi+function+shield)

- MAX6675 Thermocouple

[AliExpress](https://www.aliexpress.com/wholesale?SearchText=max6675) / [eBay](https://www.ebay.com/sch/i.html?_nkw=Max+6675)

## License

Distributed under MIT License. See `license.md` for more information.
