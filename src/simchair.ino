// Program bespoke to the SimChair
// Arduino Micro or Leonardo
//
// avionics@skyracer.net
//
// 0.1 - First version
// 0.2 - Added comments and configurable variable
// 0.3 - Added digital signals, now: 15 digital and 4 analog channels
// 0.4 - Added a secondary joystick, now: 2 x (15 digital and 4 analog channels)
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
  true, //airbrake
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
  true, //airbrake
  false, //throttle
  false, //brake
  false); //steering

  // Configuration variables, FALSE: not reverse, TRUE: reversed
  bool XAxisReverse = true;
  bool YAxisReverse = true;
  bool ZAxisReverse = true;
  bool AirbrakeReverse = true;
  bool TrimReverse = false;
  bool WheelBrakeOnAirbrake = false; //Set false if airbrake is used as throttle

  // Initialize internal variables
  int Airbrake = 0;
  int MaxAirbrake = 0;
  int MinAirbrake = 1024;
  float AirbrakeRatio = 0.0;
  int XAxis = 0;
  int MaxXAxis = 0;
  int MinXAxis = 1024;
  float XRatio = 0.0;
  int YAxis = 0;
  int MaxYAxis = 0;
  int MinYAxis = 1024;  
  float YRatio = 0.0;
  int ZAxis = 0;
  int MaxZAxis = 0;
  int MinZAxis = 1024;
  float ZRatio = 0.0;
  int Trim = 0;
  int MaxTrim = 0;
  int MinTrim = 1024;
  float TrimRatio = 0.0;
  
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
  if (XAxisReverse) {XAxis = analogRead(A1);}             //  The input is normal (due to mounting of the sensor)
    else {XAxis = 1024-analogRead(A1);}                   //  The input is reversed (due to mounting of the sensor)

  if (YAxisReverse) {YAxis = analogRead(A2);}   //  The input is normal (due to mounting of the sensor)
    else {YAxis = 1024-analogRead(A2);}       //  The input is reversed (due to mounting of the sensor)

  if (ZAxisReverse) {ZAxis = analogRead(A3);}             //  The input is normal (due to mounting of the sensor)
    else {ZAxis = 1024-analogRead(A3);}                   //  The input is reversed (due to mounting of the sensor)

  if (AirbrakeReverse) {Airbrake = analogRead(A4);}                            //  The input is reversed due to mounting of the sensor
  else {Airbrake = 1024-analogRead(A4);}                  //  The input is reversed due to mounting of the sensor

  if (TrimReverse) {Trim = analogRead(A5);}                            //  The input is reversed due to mounting of the sensor
  else {Trim = 1024-analogRead(A5);}                  //  The input is reversed due to mounting of the sensor

  //  Adjusting the output in relation to the minimum and maximum input
  // The X-axis
  if (XAxis > MaxXAxis) {MaxXAxis = XAxis;}     //  Finding maximum input
  if (XAxis < MinXAxis) {MinXAxis = XAxis;}     //  Finding minimum input
  XRatio = ((float)XAxis-(float)MinXAxis)/((float)MaxXAxis - (float)MinXAxis);  // Calculating the current ratio
  Joystick1.setXAxis(int(XRatio * 1024));        //  Setting the output to the joystick output

  // The Y-axis
  if (YAxis > MaxYAxis) {MaxYAxis = YAxis;}     //  Finding maximum input
  if (YAxis < MinYAxis) {MinYAxis = YAxis;}     //  Finding minimum input
  YRatio = ((float)YAxis-(float)MinYAxis)/((float)MaxYAxis - (float)MinYAxis);  // Calculating the current ratio
  Joystick1.setYAxis(int(YRatio * 1024));        //  Setting the output to the joystick output

  // The Z-axis
  if (ZAxis > MaxZAxis) {MaxZAxis = ZAxis;}     //  Finding maximum input
  if (ZAxis < MinZAxis) {MinZAxis = ZAxis;}     //  Finding minimum input
  ZRatio = ((float)ZAxis-(float)MinZAxis)/((float)MaxZAxis - (float)MinZAxis);  // Calculating the current ratio
  Joystick1.setZAxis(int(ZRatio * 1024));        //  Setting the output to the joystick output

  // The thottle a.k.a. airbrake
  if (Airbrake > MaxAirbrake) {MaxAirbrake = Airbrake;}  //  Finding out the max airbrake value since boot
  if (Airbrake < MinAirbrake) {MinAirbrake = Airbrake;}  //  Finding out the min airbrake value since boot
  AirbrakeRatio = ((float)Airbrake-(float)MinAirbrake)/((float)MaxAirbrake - (float)MinAirbrake);   // Calculating the degree of deployed airbrake (throttle)
  if (AirbrakeRatio < (10)) {Joystick2.setXAxis(int(0));}        //  Hysteresis to open the airbrake
  else  {Joystick2.setXAxis(int(AirbrakeRatio * 1024));}       //  Setting the output to the joystick output

  // The trim
  if (Trim > MaxTrim) {MaxTrim = Trim;}  //  Finding out the max Trim value since boot
  if (Trim < MinTrim) {MinTrim = Trim;}  //  Finding out the min Trim value since boot
  TrimRatio = ((float)Trim-(float)MinTrim)/((float)MaxTrim - (float)MinTrim);   // Calculating the degree of deployed Trim 
  Joystick2.setYAxis(int(TrimRatio * 1024));       //  Setting the output to the joystick output

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
  if (WheelBrakeOnAirbrake) //  Emulating the wheelbrake (the airbrake axis is used for the airbrakes)
    {Joystick1.setButton(14,(AirbrakeRatio > 0.95));
    if (AirbrakeRatio > 0.95) {Serial.print("WheelBrake!");}}         //  If the airbrake is deployed more than 95%, then the wheelbrake is activated.
  
  //  Debugging
  //Serial.print("X: ");
  //Serial.print(XAxis);
  //Serial.print(", XRatio: ");
  //Serial.print(int(XRatio * 1024));
  //Serial.print(", MaxX: ");
  //Serial.print(MaxXAxis);
  //Serial.print(", MinX: ");
  //Serial.println(MinXAxis);
  //Serial.print(", Y: ");
  //Serial.print(int(YRatio * 1024));
  //Serial.print(", Z: ");
  //Serial.print(int(ZRatio * 1024));
  //Serial.print(", A4: ");
  //Serial.print(int(AirbrakeRatio * 1024));
  //Serial.print(", A5: ");
  //Serial.println(int(TrimRatio * 1024));

  delay(50);
  }
