#include "Arduino.h"
#include "SPI.h"
#include "tft_eSPI.h"
#include "eye_bk_sm.h"

#define GC9A01_DRIVER
#define TFT_BL 3
#define SPI_FREQUENCY 80000000
#define SPI_READ_FREQUENCY 20000000

#define filesystem SPIFFS

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);

int bobble = 1; //debug friend
// locate the sprite in the middle of the screen considering the offset required by the edges 
int eyex = 65; // x position of the ghost eye sprite 76 for waveshare, 65 for sunton
int eyey = 78; // y position of the ghost eye sprite 83 for waveshare, 78 for sunton
int textx = -4; // x position of the text 6 for waveshare, -4 for sunton
int texty = 4; // y position of the text 10 for waveshare, 4 for sunton

void setup() {
  Serial.begin(115200); 
  delay(1000);
  Serial.println("Hello."); // "Hello." more debug friends
  pinMode(TFT_BL, OUTPUT);
  ledcSetup(TFT_BL, 5000, 8);
  ledcAttachPin(TFT_BL, 3); //sunton 3, remember that waveshare might be different
  ledcWrite(TFT_BL, 100);
  
  Serial.println("Hello world."); // "Hello world."  yeah, debug friends again

  tft.init();
  tft.setRotation(0);
  Serial.println("GhostEye");
  
  tft.fillScreen(TFT_GREEN); // Clear the screen with green color
  delay(1000);
  tft.fillScreen(TFT_BLACK); // Clear the screen with black color
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the text color to white with black background
  tft.setTextSize(2);
  tft.setTextFont(2); // Set the text font to font number 2
  
  // Draw a string at position (120, 120) on the screen
  tft.setTextDatum(MC_DATUM); // Set the datum to the middle center of the text
  tft.drawString("GhostEye", 120+textx, 90+texty); //give myself some credit here
  tft.drawString("by", 122+textx, 120+texty);
  tft.drawString("atomicalex", 126+textx, 150+texty); 
  delay(5000);
  
  tft.fillScreen(TFT_BLACK); // Clear the screen with black color
  spr.createSprite(100,100); //create the ghost eye sprite
  spr.setSwapBytes(true);
  spr.pushImage(0,0,100,100,eye_bk_sm); //name the sprite
  spr.pushSprite(eyex, eyey); // locate the sprite and show it on the TFT
  delay(2000);
}

void loop() {
  delay(1000);
  Serial.println(bobble);
  bobble++;

int i;
int j;

tft.fillScreen(TFT_BLACK); // wink the eye by clearing the screen and redrawing the sprite in the same location
delay(250);
Serial.println("Drawing image...");

  //Draw the image:
  spr.pushSprite(eyex,eyey);
  delay(1000);
  // move the image around using the 45degree axis to minimize pixel effects
  for (i=0; i<20; i+=2) {
    spr.pushSprite(eyex+i,eyey);
    delay((i*2)^4);
 }
  delay(400);
  for (j=0; j<20; j+=2) {
    spr.pushSprite(eyex+20-j,eyey);
    delay((j*2)^4);
  }
  delay(1000);
  for (i=0; i<20; i+=2) {
    spr.pushSprite(eyex,eyey+i);
    delay((i*2)^4);
  }
  delay(400);
  for (j=0; j<20; j+=2) {
   spr.pushSprite(eyex,eyey+20-j);
   delay((j*2)^4);
  }
  delay(1000);
  for (i=0; i<20; i+=2) {
    spr.pushSprite(eyex-i,eyey);
    delay((i*2)^4);
  }
  delay(400);
  for (j=0; j<20; j+=2) {
    spr.pushSprite(eyex-20+j,eyey);
    delay((j*2)^4);
  }
  delay(1000);
  for (i=0; i<20; i+=2) {
    spr.pushSprite(eyex,eyey-i);
    delay((i*2)^4);
  }
  delay(400);
  for (j=0; j<20; j+=2) {
    spr.pushSprite(eyex,eyey-20+j);
    delay((j*2)^4);
  } 
  delay(1000);
}
