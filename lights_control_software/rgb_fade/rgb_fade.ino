/*
 RGBUV fade
  Test code for day light imitating lamp, intended for arduino nano 
 */

int red = 10; 
int blue = 9; 
int green = 11; 
int uv = 6;

float uv_sun = 0;//0.95935;
float b_sun =  .2;//1.00000;
float g_sun = .6;//0.6;
float r_sun =  1;//0.48;

int brightness = 0;

int sensorPin = A7; //Pot for setting brightness
int sensorValue = 1000;

void setup()  { 
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(uv, OUTPUT);
  pinMode(sensorPin, INPUT);
} 

void loop()  { 
  sensorValue = analogRead(sensorPin);    
  float calib = .25;
  brightness = (sensorValue)*calib;
  
  float bb = b_sun*brightness;
  float bg = g_sun*brightness;
  float br = r_sun*brightness;
  float bu = uv_sun*brightness;
  
  analogWrite(red,(int)br);
  analogWrite(blue,(int)bb);  
  analogWrite(green,(int)bg);
  analogWrite(uv, (int)bu);  
}

