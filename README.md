# The SimChair

## Background

This project is sprung from the disappointment of using a joystick bought from an electronics store for 120€. Being a glider pilot for the last +30 years I do become annoyed when I can´t catch the thermals properly in the Condor gliding simulator. Or at least I blamed the joystick.

I started to think outside the box: How can I do this better with a reasonable budget? This page is my answer to this question.

After a few prototypes I landed in a solution where a control assembly is mounted on a chair. The prototypes proved that adequate control was feasible with surprisingly good flight control dynamics: you tend to forget that you are in a simulator when using a VR-headset. 

![image](https://github.com/speedbird620/SimChair/assets/50543575/214895bf-fdc9-41e7-b973-d6968128a447)

_Iteration 2 of the SimChair._

The second iteration is utilising an Arduino Micro and hall sensors for the flight controls. Then an idea emerged of creating a more comfortable solution which can be reproduced larger numbers and how simulators can be a part of pilot training, especially for us who lives in a country that only allow flight from April to October.

The requirements for the simulator:
 - The parts shall be available in general stores (as far as possible)
 - A simple yet durable construction
 - Dual controlStick, rudder and airbrake
 - Airbrake shall be able to be used as throttle and collector after minor alteration
 - Tow cable release
 - Position of pedals are adjustable

For most people the electronic hardware and software is the main obstacle. Therefore, the SimChair projects is a twostep project: A, an electronics and software package; B, a flight control assembly designed to use an IKEA chair.

## Step 1: Electronics, "the magic stuff"

The first part is an electronics and software package that will simulate a joystick using the built-in drivers in Windows. Either you can get the stuff in the bill of materials, put things together and apply the Arduino libraries. Or feel free to use it as a creative compass for your own build.

The skill level required is an average glider pilot with limited soldering skill. After all this aren’t rocket science.

The electronics and software package contains of:
 - Design schematic (open source) for Arduino Leonardo or Arduino Micro (ATMEGA32U4)
 - Software and libraries (open source)
 - Bill of material for recommended components to order 

Please note: in the first prototype I used potentiometers which broke pretty much instantly. For the second prototype I switched to hall sensors which is working excellent. So, if you are opting for potentiometers, please be aware of the potential limitations.

To make things easier I have developed a bespoke PCB-adaptor between Arduino and electrical connectors as well as a bespoke PCB-adaptor for the hall sensors recommended in the bill of material. Eventually you will be able to order these PCB´s.

![image](https://github.com/speedbird620/SimChair/assets/50543575/3c605845-c650-41a6-91f2-39089f4274d3)
_PCB for adaptor Arduino and hall sensor._

![image](https://github.com/speedbird620/SimChair/assets/50543575/6affe71b-3b06-4f39-a636-f8d2b02d357a)

_PCB-adaptor for Arduino Leonardo or Arduino Micro. The picture shows a PCB with Leonardo, hall sensor and switches (examples)._

## Step 2: Flight control assembly

The flight control assembly is designed to fit onto a [POÄNG](https://www.ikea.com/se/sv/cat/poaeng-serie-07472/) from IKEA. The plan is to offer a kit with CNC-cutout parts from plywood and a bill of material for what to buy in the local hardware store (hinges, 3D-printed brackets, screws, bicycle parts etc.). All you need is some patience, screwdriver and a friend with a 3D-printer as the files needed for 3D-printing will also be provided.

![image](https://github.com/speedbird620/SimChair/assets/50543575/4371f385-88a6-4e2a-ac42-8caab18e3206)

_The SimChair with the flight control assembly mounted to POÄNG. View from the side._

![image](https://github.com/speedbird620/SimChair/assets/50543575/deb65812-16e1-408d-839f-00e0176702fd)

_View from back._

## Step 3: Installing the electronics

In order to install the hall sensors, a few 3D printed items ha been designed. Please find the STL-files in the above repository. 

![image](https://github.com/user-attachments/assets/a8060ea2-dbb9-4f40-8c77-556ec7fdfe7c)

_The holder for the Hall-sensor, arm, link and the bracket._

![image](https://github.com/user-attachments/assets/664167cb-c9f0-4220-96c3-6ec773aa6a8e)

_From the back side._

![image](https://github.com/user-attachments/assets/358a0d4d-c429-4f00-bae5-15e6008fd893)

_A base for the PCB so you can test in on a workingbench._

More information will be provided as the first prototype will be assembled. Meanwile, you can print out the parts.

## Current status

The electrical design has been verified. The first CNC-cutouts will be delivered ... soon. 

So stay tuned ....
