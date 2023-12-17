// Program bespoke to the SimChair
// Arduino Micro or Leonardo
//
// avionics@skyracer.net
//
// 0.1 - First version
// 0.2 - Added comments and configurable variable
// 0.3 - Added digital signals, now: 15 digital and 4 analog channels
//
// https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-1.0
// https://mheironimus.blogspot.com/2015/11/arduino-joystick-library.html
//------------------------------------------------------------


#include <Joystick.h> 

Joystick_ Joystick(0x03, //hid report id
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
  bool XAxisReverse = false;
  bool YAxisReverse = true;
  bool ZAxisReverse = true;
  bool AirbrakeReverse = true;
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
  
void setup() 
  {
  // Starting the joystick engine
  Joystick.begin();
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

  if (YAxisReverse) {YAxis = (analogRead(A2)*0.9)-200;}   //  The input is normal (due to mounting of the sensor)
    else {YAxis = 1024-((analogRead(A2)*0.9)-200);}       //  The input is reversed (due to mounting of the sensor)

  if (ZAxisReverse) {ZAxis = analogRead(A3);}             //  The input is normal (due to mounting of the sensor)
    else {ZAxis = 1024-analogRead(A3);}                   //  The input is reversed (due to mounting of the sensor)

  if (AirbrakeReverse) {Airbrake = analogRead(A4);}                            //  The input is reversed due to mounting of the sensor
  else {Airbrake = 1024-analogRead(A4);}                  //  The input is reversed due to mounting of the sensor

  //  Adjusting the output in relation to the minimum and maximum input
  // The X-axis
  if (XAxis > MaxXAxis) {MaxXAxis = XAxis;}     //  Finding maximum input
  if (XAxis < MinXAxis) {MinXAxis = XAxis;}     //  Finding minimum input
  XRatio = ((float)XAxis-(float)MinXAxis)/((float)MaxXAxis - (float)MinXAxis);  // Calculating the current ratio
  Joystick.setXAxis(int(XRatio * 1024));        //  Setting the output to the joystick output

  // The Y-axis
  if (YAxis > MaxYAxis) {MaxYAxis = YAxis;}     //  Finding maximum input
  if (YAxis < MinYAxis) {MinYAxis = YAxis;}     //  Finding minimum input
  YRatio = ((float)YAxis-(float)MinYAxis)/((float)MaxYAxis - (float)MinYAxis);  // Calculating the current ratio
  Joystick.setYAxis(int(YRatio * 1024));        //  Setting the output to the joystick output

  // The Z-axis
  if (ZAxis > MaxZAxis) {MaxZAxis = ZAxis;}     //  Finding maximum input
  if (ZAxis < MinZAxis) {MinZAxis = ZAxis;}     //  Finding minimum input
  ZRatio = ((float)ZAxis-(float)MinZAxis)/((float)MaxZAxis - (float)MinZAxis);  // Calculating the current ratio
  Joystick.setZAxis(int(ZRatio * 1024));        //  Setting the output to the joystick output

  // The thottle a.k.a. airbrake
  if (Airbrake > MaxAirbrake) {MaxAirbrake = Airbrake;}  //  Finding out the max airbrake value since boot
  if (Airbrake < MinAirbrake) {MinAirbrake = Airbrake;}  //  Finding out the min airbrake value since boot
  AirbrakeRatio = ((float)Airbrake-(float)MinAirbrake)/((float)MaxAirbrake - (float)MinAirbrake);   // Calculating the degree of deployed airbrake (throttle)
  Joystick.setThrottle(int(AirbrakeRatio * 1024));       //  Setting the output to the joystick output

  //  Digital signals. Note: the digital pinputs are reversed due to the signal is set to ground
  //                                            Button in software, signal in Arduino, button in Windows
  Joystick.setButton(0,(not digitalRead(0)));   //     0                       D0              1
  Joystick.setButton(1,(not digitalRead(1)));   //     1                       D1              2       
  Joystick.setButton(2,(not digitalRead(2)));   //     2                       D2              3       
  Joystick.setButton(3,(not digitalRead(3)));   //     3                       D3              4       
  Joystick.setButton(4,(not digitalRead(4)));   //     4                       D4              5       
  Joystick.setButton(5,(not digitalRead(5)));   //     5                       D5              6       
  Joystick.setButton(6,(not digitalRead(6)));   //     6                       D6              7       
  Joystick.setButton(7,(not digitalRead(7)));   //     7                       D7              8       
  Joystick.setButton(8,(not digitalRead(8)));   //     8                       D8              9       
  Joystick.setButton(9,(not digitalRead(9)));   //     9                       D9              10       
  Joystick.setButton(10,(not digitalRead(10))); //     10                      D10             11       
  Joystick.setButton(11,(not digitalRead(11))); //     11                      D11             12       
  Joystick.setButton(12,(not digitalRead(12))); //     12                      D12             13       
  Joystick.setButton(13,(not digitalRead(13))); //     13                      D13             14       
  if (WheelBrakeOnAirbrake) //  Emulating the wheelbrake (the airbrake axis is used for the airbrakes)
    {Joystick.setButton(14,(AirbrakeRatio > 0.95));} //  If the airbrake is deployed more than 95%, then the wheelbrake is activated.
  
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
  Serial.println(int(AirbrakeRatio * 1024));

  delay(50);
  }
