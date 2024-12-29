# Yet another simulator chair

## Abstract 

This is an open source simulator project where an IKEA chair has been modified into a dual control joystick. The main purpose is to offer a possibility to train students in for example Condor flight simulatior. From the basic flight training, to fine tuning the art thermalling and cross country. All in reach for the reasonable DIY-handy individual.

## Background

This project is sprung from the disappointment of using a joystick bought from an electronics store for 120€. Being a glider pilot for the last +30 years I do become annoyed when I can´t catch the thermals properly in the Condor gliding simulator. Or at least I blamed the joystick.

I started to think outside the box: How can I do this better with a reasonable budget? This page is my answer to this question.

After a few prototypes I landed in a solution where a control assembly is mounted on a chair. The prototypes proved that adequate control was feasible with surprisingly good flight control dynamics: you tend to forget that you are in a simulator when using a VR-headset. 

![image](https://github.com/speedbird620/SimChair/assets/50543575/214895bf-fdc9-41e7-b973-d6968128a447)

_Iteration 2 of the chair._

The second iteration is utilising an Arduino Micro and hall sensors for the flight controls. Then an idea emerged of creating a more comfortable solution which can be reproduced larger numbers and how simulators can be a part of pilot training, especially for us who lives in a country that only allow flight from April to October.

The requirements for the simulator:
 - The parts shall be available in general stores (as far as possible)
 - A simple yet durable construction
 - Dual controlStick, rudder and airbrake
 - Airbrake shall be able to be used as throttle and collector after minor alteration
 - Tow cable release
 - Position of pedals are adjustable

For most people the electronic hardware and software is the main obstacle. Therefore, the chair projects is a twostep project: A, an electronics and software package; B, a flight control assembly designed to use an IKEA chair.

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

The flight control assembly is designed to fit onto a [POÄNG](https://www.ikea.com/se/sv/cat/poaeng-serie-07472/) from IKEA. Please see the blue prints in the DXF-folder in the file repository above for the pieces to cut out. Above you will also find a list of material to buy in the local hardware store (hinges, washers, nuts, screws, bicycle parts etc.)

We plan to offer a kit with CNC-cutout parts from plywood but this is progress right now. Meanwhile, if you have access to a CNC-machine or a laser cutter, please feel free to download the DXF-files and make simulator youself.

![image](https://github.com/user-attachments/assets/efb08bbc-0c84-4f5d-8846-0a5b164729b6)

_The chair with the flight control assembly mounted to POÄNG. View from the side._

![image](https://github.com/user-attachments/assets/32235e13-b1d1-47c4-abeb-899849b73cd0)

_View from back._

_Below are some of the mounting instructions._

![image](https://github.com/user-attachments/assets/f4c4fd63-ba61-429a-8b03-78ad15a9b609)
![image](https://github.com/user-attachments/assets/4ba0644f-8edb-4e2f-8bd6-7cef5fda46a1)
![image](https://github.com/user-attachments/assets/0066c525-5ac4-47df-8fc4-14b8e6680873)
![image](https://github.com/user-attachments/assets/aac32c1b-e04c-422a-afda-2fa244be8f5b)


## Step 3: Installing the electronics

In order to install the hall sensors, a few 3D printed items has been developed. Please find the STL-files in the above repository. 

![image](https://github.com/user-attachments/assets/a8060ea2-dbb9-4f40-8c77-556ec7fdfe7c)

_The holder for the Hall-sensor, arm, link and bracket._

![image](https://github.com/user-attachments/assets/664167cb-c9f0-4220-96c3-6ec773aa6a8e)

_From the back side._

![image](https://github.com/user-attachments/assets/358a0d4d-c429-4f00-bae5-15e6008fd893)

_A base for the PCB so you can test in on a workingbench._

![image](https://github.com/user-attachments/assets/2232b4db-af97-4446-830b-79d78d8e8029)

_An overview of the parts to print._

## Current status

The electrical design has been verified. The first CNC-cutouts are produced.

![image](https://github.com/user-attachments/assets/af9f7d71-a253-40db-b3a3-0c45151bbc9c)

_The pieces are being cut out by a CNC milling machine._

![image](https://github.com/user-attachments/assets/a1bb0b4e-a280-4b20-b4ed-05d5c3fa40a0)

_The PCB-adaptor mounted on the chair._



![image](https://github.com/user-attachments/assets/5a70ea52-f2ca-45bf-8daa-5c055da71a14)

_Inital flight trial._



So stay tuned ....
