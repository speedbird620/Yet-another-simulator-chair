# The JoyStool

## Background

This project is sprung from the disappointment of using a joystick bought from an electronics store for 120€. Being a glider pilot for the last +30 years I do become annoyed when I can´t catch the thermals properly in the Condor gliding simulator. Or at least I blamed the joystick.

I started to think outside the box: How can I do this better with a reasonable budget? This page is my answer to this question.

After a few prototypes I landed in a solution where a control assembly is mounted on a chair. The prototypes proved that adequate control was feasible with surprisingly good flight control dynamics: you tend to forget that you are in a simulator when using a VR-headset. 

![image](https://github.com/speedbird620/JoyStool/assets/50543575/214895bf-fdc9-41e7-b973-d6968128a447)

_Iteration 2 of the JoyStool._

The second iteration is utilising an Arduino Micro and hall sensors for the flight controls. Then an idea emerged of creating a more comfortable solution which can be reproduced larger numbers and how simulators can be a part of pilot training, especially for us who lives in a country that only allow flight from April to October.

The requirements for the simulator:
 - The parts shall be available in general stores (as far as possible)
 - A simple yet durable construction
 - Dual controlStick, rudder and airbrake
 - Airbrake shall be able to be used as throttle and collector after minor alteration
 - Tow cable release
 - Position of pedals are adjustable

For most people the electronic hardware and software is the main obstacle. Therefore, the JoyStool projects is a twostep project: A, an electronics and software package; B, a flight control assembly designed to use an IKEA chair.

## Step 1: Electronics and magic stuff

The first part is an electronics and software package that will simulate a joystick using the built-in drivers in Windows. Either you can get the stuff in the bill of materials, put things together and apply the Arduino libraries. Or feel free to use it as a creative compass for your own build.

The skill level required is an average glider pilot with limited soldering skill. After all this aren’t rocket science.

The electronics and software package contains of:
 - Design schematic (open source) for Arduino Leonardo or Arduino Micro (ATMEGA32U4)
 - Software and libraries (open source)
 - Bill of material for recommended components to order 

Please note: in the first prototype I used potentiometers which broke pretty much instantly. In the second prototype I switched to hall sensors which is working excellent. So, if you are opting for potentiometers, please be aware of the potential limitations.

To make things easier I have developed a bespoke PCB-adaptor between Arduino and electrical connectors as well as a bespoke PCB-adaptor for the hall sensors recommended in the bill of material. Eventually you will be able to order these PCB´s.

![image](https://github.com/speedbird620/JoyStool/assets/50543575/77c1adcf-99c7-4519-a93a-39b401b5d339)

_PCB-adaptor for Arduino Leonardo or Arduino Micro._

![image](https://github.com/speedbird620/JoyStool/assets/50543575/d1bd2dae-a71d-4847-858a-a8d55bbca9c7)

_PCB-adaptor for hall sensors._

## Step 2: Flight control assembly

The flight control assembly is designed to fit onto a [POÄNG](https://www.ikea.com/se/sv/cat/poaeng-serie-07472/) from IKEA. The plan is to offer a kit with CNC-cutout parts from plywood and a bill of material for what to buy in the local hardware store (hinges, 3D-printed brackets, screws, bicycle parts etc.). All you need is some patience, screwdriver and a friend with a 3D-printer as the files needed for 3D-printing will also be provided.

![image](https://github.com/speedbird620/JoyStool/assets/50543575/287bdebb-bac8-4201-b6a1-f34896845bf7)

_The JoyStool with the flight control assembly mounted to POÄNG. View from the side._

![image](https://github.com/speedbird620/JoyStool/assets/50543575/deb65812-16e1-408d-839f-00e0176702fd)

_View from back._

## Current status

The electrical design has been set and parts are orderd. The first CNC-cutouts will be delivered within a week or two. 

So stay tuned ....
