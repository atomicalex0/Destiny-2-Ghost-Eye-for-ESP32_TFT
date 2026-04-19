#include <Arduino.h>
#include <TFT_eSPI.h>
#include  "eye_bk_sm.h"

#define GC9A01_DRIVER
#define TFT_BACKLIGHT_ON HIGH

#define filesystem SPIFFS

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite spr = TFT_eSprite(&tft);


void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(0);

  tft.fillScreen(TFT_BLACK); // Clear the screen with black color
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the text color to white with black background
  tft.setTextSize(2);
  tft.setTextFont(2); // Set the text font to font number 2
  
  // Draw a string at position (120, 120) on the screen
  tft.setTextDatum(MC_DATUM); // Set the datum to the middle center of the text
  tft.drawString("GhostEye", 126, 100); //give myself some credit here
  tft.drawString("by", 126, 130);
  tft.drawString("atomicalex", 126, 160); 
  delay(5000);
  
  tft.fillScreen(TFT_BLACK); // Clear the screen with black color
  
  spr.createSprite(100,100); //create the ghost eye sprite
  spr.setSwapBytes(true);
  spr.pushImage(0,0,100,100,eye_bk_sm); //name the sprite
  spr.pushSprite(76, 83); // locate the sprite and show it on the TFT
  delay(2000);
}

void loop() {
// locate the sprite in the middle of the screen considering the offset required by the edges 
int i;
int j;
int eyex = 76;
int eyey = 83;

tft.fillScreen(TFT_BLACK); // wink the eye by clearing the screen and redrawing the sprite in the same location
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
