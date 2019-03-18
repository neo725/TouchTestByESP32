#include <Arduino.h>

// ref from :
// https://github.com/Serpent999/ESP32_Touch_LED/blob/master/Touch_LED/Touch_LED.ino

/*
   Nikhil.P.Lokhande
   Project: ESP32 Touch Controled LED, using PWM
   Board: ESP32 Dev Module
   Touch Sensor Pin Layout
   T0 = GPIO4
   T1 = GPIO0
   T2 = GPIO2
   T3 = GPIO15
   T4 = GPIO13
   T5 = GPIO12
   T6 = GPIO14
   T7 = GPIO27
   T8 = GPIO33
   T9 = GPIO32 */

uint8_t led_0 = 32;
uint8_t led_1 = 33;
bool flash_mode = false;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  // ledcAttachPin(led_0, 1);                                                    //Configure variable led, pin 18 to channel 1
  ledcSetup(2, 12000, 8);                                                  // 12 kHz PWM and 8 bit resolution
  ledcWrite(2, 100);                                                       // Write a test value of 100 to channel 1

  // ledcSetup(0, 12000, 8);                                                  // 12 kHz PWM and 8 bit resolution
  // ledcWrite(0, 100);                                                       // Write a test value of 100 to channel 1

  // Serial.println("Testing ledc 12 channel 1");

  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);

  // touchAttachInterrupt(T0, gotTouch, threshold);
  // touchAttachInterrupt(T1, gotTouch1, threshold);

}
void loop()
{
  Serial.println("Touch sensor value:");
  Serial.println(touchRead(T0));
  Serial.println(touchRead(T3));

  // {
  //   ledcWrite(1, (buff(T0)));                 // Using T0 for touch data
  // }

  digitalWrite(led_0, flash_mode ? HIGH : LOW);
  digitalWrite(led_1, flash_mode ? LOW : HIGH);

  flash_mode = !flash_mode;

  delay(1000);
}