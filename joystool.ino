// Program bespoke to the JoyStool
// Arduino Micro or Leonardo
//
// jingel@skyracer.net
//
// 0.1 - First version
// 0.2 - Added comments and configurable variable
//
//------------------------------------------------------------

#include <Joystick.h> // https://github.com/gmarty2000-ARDUINO/arduino-JOYSTICK

Joystick_ Joystick(0x03, //hid report id
  JOYSTICK_TYPE_GAMEPAD, //joystick type
  12, //button count
  0, //Hsw 0-2
  true, //x
  true, //y
  true, //z
  false, //rx
  false, //ry
  false, //rz
  false, //rudder
  true, //throttle
  false, //accelerator
  false, //brake
  false); //steering

  // Konfiguration variables, FALSE: not reverse, TRUE: reversed
  bool XAxisReverse = false;
  bool YAxisReverse = true;
  bool ZAxisReverse = true;
  bool ThrottleReverse = true;

  // Initialize internal variables
  int Throttle = 0;
  int MaxThrottle = 0;
  int MinThrottle = 1024;
  float ThrottleRatio = 0.0;
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

  if (ThrottleReverse)
  {Throttle = analogRead(A4);}                            //  The input is reversed due to mounting of the sensor
  else {Throttle = 1024-analogRead(A4);}                  //  The input is reversed due to mounting of the sensor

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
  if (Throttle > MaxThrottle) {MaxThrottle = Throttle;}  //  Finding out the max throttle value since boot
  if (Throttle < MinThrottle) {MinThrottle = Throttle;}  //  Finding out the min throttle value since boot
  ThrottleRatio = ((float)Throttle-(float)MinThrottle)/((float)MaxThrottle - (float)MinThrottle);   // Calculating the degree of deployed throttle (airbrake)
  Joystick.setThrottle(int(ThrottleRatio * 1024));       //  Setting the output to the joystick output
  
  //  Emulating the wheelbrake (the throttle axis is used for the airbrakes)
  Joystick.setButton(11,(ThrottleRatio > 0.95));         //  If the throttle (airbrakes) is deployed more than 95%, then the wheelbrake is activated.

  //  Digital signals
  Joystick.setButton(0,(not digitalRead(2)));   //  Note: the digital pinputs are reversed due to the signal is set to ground
  Joystick.setButton(1,(not digitalRead(3))); 
  Joystick.setButton(2,(not digitalRead(4))); 
  Joystick.setButton(3,(not digitalRead(5))); 
  Joystick.setButton(4,(not digitalRead(6))); 
  Joystick.setButton(5,(not digitalRead(7))); 
  Joystick.setButton(6,(not digitalRead(8))); 
  Joystick.setButton(7,(not digitalRead(9))); 
  Joystick.setButton(8,(not digitalRead(10))); 
  Joystick.setButton(9,(not digitalRead(11))); 
  Joystick.setButton(10,(not digitalRead(12))); 
  
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
  //Serial.println(int(ThrottleRatio * 1024));

  delay(50);
  }
