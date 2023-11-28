# Background to the JoyStool

This project is sprung from the disapointment of using a joystick bought from an electronics store for 120€. Being unable to fly ass accurate I wanted started to think outside the box: How can I do this better with an reasonable budget? This page is my answer to this question. 

After a few prototypes I landed in a solution where a control assembly is mounted on a chair. The prototyes prooved that adequate control was feasable with surprisingly good flight control dynamics. 

![image](https://github.com/speedbird620/JoyStool/assets/50543575/214895bf-fdc9-41e7-b973-d6968128a447)
Iteration 2 of the JoyStool.

The second iteration is utilising an Arduino Micro and hall sensors for the flight controls and the idea of creating a more comfirtable solution which can be reproduced larger numbers. Just think of how simulators can be a part of pilot training, especially for us who lives in a country that only allow flight from april to october. 

The requirements for the simulator:
 - The parts shall be avilable in general stores (as far as possible)
 - A simple construction
 - Dual control
 - Stick, rudder and airbrake
 - Airbrake shall be able to be used as throttle and collector after minor alteration
 - Tow cable release
 - Position of pedals are adjustable
 - 


For most people the electronic hardware and software is the main obstacle. Therefore the JoyStool projects is a two step project: A, an electronic and software package; B, a flight control assembly designed to use a IKEA chair.

# Step 1: Electronics and magic stuff

The first part is an electronics and software package that will simulate a joystick using the built in drivers in Windows. Either you can get the stuff in the bill of materials and put things toghether, or feel free to use it as a creative

The skill level required is opted for an average glider pilot with limited soldering skill. This is not rocket sience. 

The electronics and software package contains of:
 - Design schematic (open source) for Arduino Leonardo or Arduino Micro (ATMEGA32U4)
 - Software and libraries (open source)
 - Bill of material for recomended components to order

To make things easier I have developed a bespoke PCB-adaptor between Arduino and electrical connectors as well as a bespoke PCB-adaptor for the hall sensors recomended in the bill of material. Eventually you will be able to order these PCB´s. 



package which is easy to use and easy to understand. Secondly, an IKEA-style kit in plywood with prefabricated parts easy to assemble and start flying. If you want you can combine the two into a 

