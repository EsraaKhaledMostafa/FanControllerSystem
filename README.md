# FanControllerSystem

## Used Hardware:
- ATmega32 Microcontroller.
- 2x16 LCD with 4-bit mode.
- LM35 Temperature Sensor.
- DC Motor and H-Bridge.

## SW Drivers:
- MCAL:
GPIO
PWM
ADC
- HAL:
LCD
Temperature Sensor
DC Motor
- APP

## Project on Proteus: 
![image]![Proteus_photo](https://github.com/EsraaKhaledMostafa/FanControllerSystem/assets/87395019/82e587f6-e797-4d6c-90de-eea21e02f0b7)

## Specifications:
- Temperature-controlled fan in which the fan is automatically turned ON or OFF according to the
temperature.
- The microcontroller will continuously monitor the temperature and based on the
temperature value, the microcontroller will drive the fan with a certain speed by generating a relative PWM signal to the DC Motor in order to rotate with varying speeds.
