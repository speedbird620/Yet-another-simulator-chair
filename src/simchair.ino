// Program bespoke to the SimChair
// Arduino Micro or Leonardo
//
// avionics@skyracer.net
//
// 0.1 - First version
// 0.2 - Added comments and configurable variable
// 0.3 - Added digital signals, now: 15 digital and 4 analog channels
// 0.4 - Added a secondary joysticvk, now: 2 x (15 digital and 4 analog channels)
// 0.5 - Added debug mode
//
// https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-1.0
// https://mheironimus.blogspot.com/2015/11/arduino-joystick-library.html
//------------------------------------------------------------

#include <Joystick.h> 

Joystick_ Joystick1(0x03, //hid report id
  JOYSTICK_TYPE_GAMEPAD, //joystick type
  15, //button count
  0, //Hsw 0-2
  true, //x
  true, //y
  true, //z
  false, //rx
  false, //ry
  false, //rz
  false, //rudder
  true, //Airbrake
  false, //throttle
  false, //brake
  false); //steering

Joystick_ Joystick2(0x04, //hid report id
  JOYSTICK_TYPE_GAMEPAD, //joystick type
  15, //button count
  0, //Hsw 0-2
  true, //x
  true, //y
  true, //z
  false, //rx
  false, //ry
  false, //rz
  false, //rudder
  true, //Airbrake
  false, //throttle
  false, //brake
  false); //steering

  // Configuration variables, FALSE: not reverse, TRUE: reversed
  bool XAxisReverse = true;
  bool YAxisReverse = true;
  bool ZAxisReverse = true;
  bool AirbrakeReverse = true;
  bool TrimReverse = false;
  bool WheelBrakeOnAirbrake = true; //Set false if Airbrake is used as throttle
  bool DebugMode = false;

  // Initialize internal variables
  int XAxis = 0;
  int YAxis = 0;
  int ZAxis = 0;
  int Trim = 0;
  int Airbrake = 0;
  int MaxAirbrake = 0;
  int MinAirbrake = 1024;
  float AirbrakeRatio = 0.0;
  
void setup() 
  {
  // Starting the joystick engine
  Joystick1.begin();
  Joystick2.begin();
  // Setting up IO´s
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  }

void loop() 
  {
  //  Reading analog signals

  XAxis = analogRead(A1);
  if (XAxisReverse) {Joystick1.setXAxis(XAxis);}             //  The input is normal (due to mounting of the sensor)
    else {Joystick1.setXAxis(1024-XAxis);}                   //  The input is reversed (due to mounting of the sensor)

  YAxis = analogRead(A2);
  if (YAxisReverse) {Joystick1.setYAxis(YAxis);}             //  The input is normal (due to mounting of the sensor)
    else {Joystick1.setYAxis(1024-YAxis);}                   //  The input is reversed (due to mounting of the sensor)

  ZAxis = analogRead(A3);
  if (ZAxisReverse) {Joystick1.setZAxis(ZAxis);}             //  The input is normal (due to mounting of the sensor)
    else {Joystick1.setZAxis(1024-ZAxis);}                   //  The input is reversed (due to mounting of the sensor)

  Trim = analogRead(A5);
  if (TrimReverse) {Joystick2.setYAxis(Trim);}             //  The input is normal (due to mounting of the sensor)
    else {Joystick2.setYAxis(1024-Trim);}                   //  The input is reversed (due to mounting of the sensor)

  Airbrake = analogRead(A4);
  if (Airbrake > MaxAirbrake) {MaxAirbrake = Airbrake;}  //  Finding out the max Airbrake value since boot
  if (Airbrake < MinAirbrake) {MinAirbrake = Airbrake;}  //  Finding out the min Airbrake value since boot
  AirbrakeRatio = ((float)Airbrake-(float)MinAirbrake)/((float)MaxAirbrake - (float)MinAirbrake);   // Calculating the degree of deployed Airbrake (throttle)
  if (AirbrakeReverse) {Joystick2.setXAxis(Airbrake);}             //  The input is normal (due to mounting of the sensor)
    else {Joystick2.setXAxis(1024-(Airbrake));}                   //  The input is reversed (due to mounting of the sensor)
  if (WheelBrakeOnAirbrake) //  Emulating the wheelbrake (the Airbrake axis is used for the Airbrakes)
    {Joystick1.setButton(14,(AirbrakeRatio > 0.99));
    if (AirbrakeRatio > 0.99) {Serial.print("WheelBrake!");}}         //  If the Airbrake is deployed more than 95%, then the wheelbrake is activated.

  if (DebugMode) {                    // Sending debug information to the serial port
    Serial.print(", A1: ");
    Serial.print(XAxis);
    Serial.print(", A2: ");
    Serial.print(YAxis);
    Serial.print(", A3: ");
    Serial.print(ZAxis);
    Serial.print(", A4: ");
    Serial.print(Airbrake);
    Serial.print(", A5: ");
    Serial.println(Trim);
  }

  Joystick1.setThrottle(int(0));     //  Setting the output to the joystick output
  Joystick1.setRudder(int(0));       //  Setting the output to the joystick output
  Joystick2.setThrottle(int(0));     //  Setting the output to the joystick output
  Joystick2.setRudder(int(0));       //  Setting the output to the joystick output

  //  Digital signals. Note: the digital pinputs are reversed due to the signal is set to ground
  //                                            Button in software, signal in Arduino, button in Windows
  Joystick1.setButton(0,(not digitalRead(0)));   //     0                       D0              1
  Joystick1.setButton(1,(not digitalRead(1)));   //     1                       D1              2       
  Joystick1.setButton(2,(not digitalRead(2)));   //     2                       D2              3       
  Joystick1.setButton(3,(not digitalRead(3)));   //     3                       D3              4       
  Joystick1.setButton(4,(not digitalRead(4)));   //     4                       D4              5       
  Joystick1.setButton(5,(not digitalRead(5)));   //     5                       D5              6       
  Joystick1.setButton(6,(not digitalRead(6)));   //     6                       D6              7       
  Joystick1.setButton(7,(not digitalRead(7)));   //     7                       D7              8       
  Joystick1.setButton(8,(not digitalRead(8)));   //     8                       D8              9       
  Joystick1.setButton(9,(not digitalRead(9)));   //     9                       D9              10       
  Joystick1.setButton(10,(not digitalRead(10))); //     10                      D10             11       
  Joystick1.setButton(11,(not digitalRead(11))); //     11                      D11             12       
  Joystick1.setButton(12,(not digitalRead(12))); //     12                      D12             13       
  Joystick1.setButton(13,(not digitalRead(13))); //     13                      D13             14       
  
  delay(20);
  }
