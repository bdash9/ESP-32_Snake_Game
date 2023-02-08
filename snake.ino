// Origional code found https://www.hackster.io/magicbit0/snake-game-from-magicbit-361446

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#define OLED_RESET 4
#include "pitches.h"
#include "themes.h";
#include <ESP32Servo.h>
//Adafruit_ST7789 display(240, 135);
//#define Rbutton 34
//#define Lbutton 35

#define Lbutton 6   //Left
#define Rbutton 5   //Left

// set pin numbers
//const int touchPin_UP = 10;   //UP
//const int touchPin_DOWN = 9;   //DOWN
//const int touchPin_LEFT = 6;    //LEFT
//const int touchPin_RIGHT = 5;   //RIGHT
//const int Lbutton = 6;    //LEFT
//const int Rbutton = 5;   //RIGHT

//With controller
//const int threshold = 25000;
//const int threshold = 25000;

//int touchValue_UP;
//int touchValue_DOWN;
//int touchValue_LEFT;
//int touchValue_RIGHT;

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int Grid = 5;
int HeadX=40;
int HeadY=40;
int nextX=40;
int nextY=40;
int index_X[23];
int index_Y[23];
int indexes=3;
bool R_State=1;
bool L_State=1;
int highestScore=1000;
int Score=0;
int foodX,foodY;
bool choose=false;
bool lost=false;
unsigned long previousTime=0;
int buzzer=25;

void IRAM_ATTR ISR_Right(){
//touchValue_RIGHT = touchRead(Rbutton);
if(millis()-previousTime>200) {   //works without controller
//if(touchValue_RIGHT > threshold){
//if((touchValue_RIGHT > threshold) && (millis()-previousTime>200)) {
R_State=0;
L_State=1;
previousTime=millis();
delay(50);
  }
}

void IRAM_ATTR ISR_Left(){
//touchValue_LEFT = touchRead(Lbutton);
if(millis()-previousTime>300) {    //works without controller
//if(touchValue_LEFT > threshold){
//if((touchValue_LEFT > threshold) && (millis()-previousTime>300)) {
L_State=0;
R_State=1;
previousTime=millis();
delay(50);
  }
}
void setup() {
 index_X[0]=40;
 index_X[1]=35;
 index_X[2]=30;
 index_Y[0]=index_Y[1]=index_Y[2]= 40;

 pinMode(Rbutton,INPUT);
 pinMode(Lbutton,INPUT);
 //
 // Syntax:   attachInterrupt(digitalPinToInterrupt(Pin),ISR,mode);
 // Modes: LOW=trigger when pin is low; CHANGE=trigger when pin changes value; RISING=when low to high; FALLING=high to low;
 // HIGH=pin is high
 // ISR is Interupt Service Routine
 //attachInterrupt(digitalPinToInterrupt(Rbutton),ISR_Right,FALLING);
 //attachInterrupt(digitalPinToInterrupt(Lbutton),ISR_Left,FALLING);
// 
 attachInterrupt(digitalPinToInterrupt(Rbutton),ISR_Right,RISING);
 attachInterrupt(digitalPinToInterrupt(Lbutton),ISR_Left,RISING);
 /*
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);
  display.clearDisplay();
  */
    Serial.begin(115200);

  // turn on backlite
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);

    // turn on the TFT / I2C power supply
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  //delay(10);
  tft.init(135, 240); // Init ST7789 240x135
  tft.setRotation(3);
  //tft.fillScreen(ST77XX_BLACK);
  tft.fillScreen(ST77XX_WHITE);
  tft.setTextSize(2);
wallpaper();
delay(4000);
  Serial.begin(115200);
  Location();
  tft.println(foodX);
  tft.println(foodY);
  
}

void loop() {
  lose();
  //Serial.println(millis());
 if(indexes<highestScore && lost==false){
  
  if(R_State==0){
    Clockwise();
    R_State=1;

  }
  else if(L_State==0){
    antiClockwise();
    L_State=1;

  }
  else{
    Go();
  }
  Eat();
updateArray();
HeadY=index_Y[0];
HeadX=index_X[0];
limit();

//display.clearDisplay();
tft.fillScreen(ST77XX_BLACK);

drawSnake();
drawFood();
//display.display();
scoreBoard();
//Serial.print("foodX = ");
//Serial.print(foodX);
//Serial.print(" foodY = ");
//Serial.print(foodY);
//Serial.print(" headX = ");
//Serial.print(nextX);
//Serial.print(" headY = ");
//Serial.println(nextY);

 }
 else{
  winOrlost();
  
 }
 delay(100);
 noTone(buzzer);

// touch sensor loops
 //loop_UP();
 //loop_DOWN();
 //loop_LEFT();
 //loop_RIGHT();
}

// Touch sensor stuff

/*
void loop_UP(){
  // read the state of the pushbutton value:
  touchValue_UP = touchRead(touchPin_UP);
  if(touchValue_UP < threshold){
  
  }
  else{
   
    tft.setCursor(100, 10);     // (x,y)
    tft.setTextColor(ST77XX_BLUE);
    tft.print("UP");
    tft.fillScreen(ST77XX_BLACK);      
  }
}

void loop_DOWN(){
  // read the state of the pushbutton value:
  touchValue_DOWN = touchRead(touchPin_DOWN);
  if(touchValue_DOWN < threshold){
   
  }
  else{
    tft.setCursor(85, 105);
    tft.setTextColor(ST77XX_GREEN);
    tft.print("DOWN");
    tft.fillScreen(ST77XX_BLACK);
    
  }
}
*/

/* Is this doing anything?
void loop_LEFT(){
  // read the state of the pushbutton value:
  touchValue_LEFT = touchRead(touchPin_LEFT);
  //touchValue_LEFT = touchRead(Lbutton);
  if(touchValue_LEFT < threshold){
  }
  else{
    tft.setCursor(10, 60);
    tft.setTextColor(ST77XX_RED);
    tft.print("LEFT");
    tft.fillScreen(ST77XX_BLACK);  
  }
}

void loop_RIGHT(){
  // read the state of the pushbutton value:
  touchValue_RIGHT = touchRead(touchPin_LEFT);
  //touchValue_RIGHT = touchRead(Rbutton);
  if(touchValue_RIGHT < threshold){
  }
  else{
    tft.setCursor(120, 60);
    tft.setTextColor(ST77XX_YELLOW);
    tft.print("RIGHT");
    tft.fillScreen(ST77XX_BLACK);     
  }
}

*/

void updateArray(){
  
for(int x=indexes-2; x>=0; x--){
   index_X[x+1]=index_X[x];
   
}

for(int y=indexes-2; y>=0; y--){
   index_Y[y+1]=index_Y[y];
   
}
 index_X[0]=nextX;
 index_Y[0]=nextY;
  
}
