/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/karissapatel/Lab6Temp/src/Lab6Temp.ino"
/*
 * Project Lab6Temp
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 7 "/Users/karissapatel/Lab6Temp/src/Lab6Temp.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#include "oled-wing-adafruit.h"

OledWingAdafruit display;

//the variables 
uint16_t reading;
double voltage;
double temperature;

// setup() runs once, when the device is first turned on.
void setup()
{
  // Put initialization like pinMode and begin functions here.
  pinMode(A3, INPUT);

  display.setup();
  display.clearDisplay();
  display.display(); // cause the display to be updated
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello, world!");
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  // The core of your code will likely live here.

  //formula for celsius
  reading = analogRead(A3);
  voltage = (reading * 3.3) / 4095.0;
  temperature = (voltage - 0.5) * 100;


  //print the temperature
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Fahrenheit = ");
  display.print((temperature *9/5)+32);
  display.print("\n Celsius= ");
  display.print(temperature);
  display.display();
}