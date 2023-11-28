# Background to the JoyStool

This project is sprung from the disapointment of using a joystick bought from an electronics store for 120€. Being unable to fly ass accurate I wanted started to think outside the box: How can I do this better with a reasonable budget? This page is my answer to this question. 

After a few prototypes I landed in a solution where a control assembly is mounted on a chair. The prototyes prooved that adequate control was feasable with surprisingly good flight control dynamics. 

![image](https://github.com/speedbird620/JoyStool/assets/50543575/214895bf-fdc9-41e7-b973-d6968128a447)

_Iteration 2 of the JoyStool._

The second iteration is utilising an Arduino Micro and hall sensors for the flight controls and the idea emerged of creating a more comfirtable solution which can be reproduced larger numbers. Just think of how simulators can be a part of pilot training, especially for us who lives in a country that only allow flight from april to october. 

The requirements for the simulator:
 - The parts shall be avilable in general stores (as far as possible)
 - A simple yet durable construction
 - Dual control
 - Stick, rudder and airbrake
 - Airbrake shall be able to be used as throttle and collector after minor alteration
 - Tow cable release
 - Position of pedals are adjustable

For most people the electronic hardware and software is the main obstacle. Therefore the JoyStool projects is a two step project: A, an electronic and software package; B, a flight control assembly designed to use a IKEA chair.

## Step 1: Electronics and magic stuff

The first part is an electronics and software package that will simulate a joystick using the built in drivers in Windows. Either you can get the stuff in the bill of materials, put things toghether and apply the Arduino libraries. Or feel free to use it as a creative compass for your own build.

The skill level required is an average glider pilot with limited soldering skill. After all this ain´t rocket sience. 

The electronics and software package contains of:
 - Design schematic (open source) for Arduino Leonardo or Arduino Micro (ATMEGA32U4)
 - Software and libraries (open source)
 - Bill of material for recomended components to order

Please note: in the first prototype I used potentiomeres which broke pretty much instantly. In the second prototype I switched to hall sensors which is working excellent. So if you are opting for potentiometers, please be aware of the technical limitations.

To make things easier I have developed a bespoke PCB-adaptor between Arduino and electrical connectors as well as a bespoke PCB-adaptor for the hall sensors recomended in the bill of material. Eventually you will be able to order these PCB´s. 

![image](https://github.com/speedbird620/JoyStool/assets/50543575/a8166cdc-2423-4460-81cd-4b2bcd056d11)

_PCB-adaptor for Arduino Leonardo or Arduino Micro._

![image](https://github.com/speedbird620/JoyStool/assets/50543575/d1bd2dae-a71d-4847-858a-a8d55bbca9c7)

_PCB-adaptor for hall sensors._

## Step 2: Flight control assembly

This is kit in plywood with prefabricated parts suited to mount on an IKEA chair called POÄNG. All you need are some hinges, brackets (3D-printed), screws, bicycle parts, patience and a screwdriver. A bill of material is provided as well as files for 3D-printing.

![image](https://github.com/speedbird620/JoyStool/assets/50543575/287bdebb-bac8-4201-b6a1-f34896845bf7)

_The JoyStool with the flight control assembly mounted to POÄNG. View from the side._

![image](https://github.com/speedbird620/JoyStool/assets/50543575/deb65812-16e1-408d-839f-00e0176702fd)

_View from back._



