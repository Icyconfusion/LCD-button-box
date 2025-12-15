// hello world

#include <BleKeyboard.h>
BleKeyboard bleKeyboard;

#include <TFT_eSPI.h>
#include <SPI.h>
#include <SD.h>

TFT_eSPI tft = TFT_eSPI();

#define SD_CS 17  // Change if you wired differently

#define ICON_SIZE 104


// Matrix pin definitions
//Column pins

#define col_pin1 39
#define col_pin2 36
#define col_pin3 35
#define col_pin4 34

// Row pins

#define row_pin1 25
#define row_pin2 26
#define row_pin3 27
#define row_pin4 14
#define row_pin5 12
// row 6 is GND

int layerstate = 1;

void setup() {
  // put your setup code here, to run once:

bleKeyboard.begin(); // start ble keyboard

// COlumn pins as inputs
pinMode(col_pin1, INPUT);
pinMode(col_pin2, INPUT);
pinMode(col_pin3, INPUT);
pinMode(col_pin4, INPUT);

// Row pins as output

pinMode(row_pin1, OUTPUT);
pinMode(row_pin2, OUTPUT);
pinMode(row_pin3, OUTPUT);
pinMode(row_pin4, OUTPUT);
pinMode(row_pin5, OUTPUT);

 // -------- LCD INITIALIZATION --------

  // Initialize the LCD
  tft.init();

  // Set screen orientation
  // 0 = portrait, 1 = landscape, 2 = upside-down, 3 = mirrored
  tft.setRotation(1);

  // Fill the entire screen with black color
  tft.fillScreen(TFT_BLACK);

  // Set text color to white with black background
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  // Set text size (2 = medium size)
  tft.setTextSize(2);

  // Set the position of the text cursor (x, y)
  tft.setCursor(10, 10);

  // Print text to the LCD
  tft.println("LCD OK");

  // -------- SD CARD INITIALIZATION --------

  // Try to initialize the SD card
  // Uses SPI and the chip select pin defined earlier
  if (!SD.begin(SD_CS)) {

    // If SD initialization fails, move cursor lower
    tft.setCursor(10, 40);

    // Set text color to red
    tft.setTextColor(TFT_RED, TFT_BLACK);

    // Print error message to LCD
    tft.println("SD FAIL");

    // Stop the program forever if SD fails
    while (1);
  }
// If SD card initializes correctly, move cursor
  tft.setCursor(10, 40);

  // Change text color to green
  tft.setTextColor(TFT_GREEN, TFT_BLACK);

  // Print success message
  tft.println("SD OK");

  // -------- DRAW ICONS FROM SD CARD --------

  // Draw first icon at x=13, y=13 - top left corner with 2mm margin from edge
  drawBmp("/icon1.bmp", 13, 13);

  // Draw second icon at x=195, y=13 - 30mm from left top corner
  drawBmp("/icon2.bmp", 195, 13);

  // Draw third icon at x=220, y=80
  drawBmp("/icon3.bmp", 377, 13);

  // Draw fourth icon
  drawBmp("/icon4.bmp", 13, 214);

  // Draw fifth icon
  drawBmp("/icon5.bmp", 195, 214);

  // Draw sixth icon
  drawBmp("/changeicon.bmp", 377, 214);

  layerstate = 1;
}


void loop() {
  // put your main code here, to run repeatedly:
//write row high, then check column

//Button 1
digitalWrite(row_pin1, HIGH);
if(digitalRead(col_pin1) == HIGH || digitalRead(col_pin2) == HIGH || digitalRead(col_pin3) == HIGH || digitalRead(col_pin4) == HIGH){
bleKeyboard.press(KEY_LEFT_CTRL);
bleKeyboard.press(KEY_LEFT_SHIFT);
bleKeyboard.write(KEY_F14);
bleKeyboard.releaseAll();
}
digitalWrite(row_pin1, LOW);

//Button 2
digitalWrite(row_pin2, HIGH);
if(digitalRead(col_pin1) == HIGH || digitalRead(col_pin2) == HIGH || digitalRead(col_pin3) == HIGH || digitalRead(col_pin4) == HIGH){
bleKeyboard.press(KEY_LEFT_CTRL);
bleKeyboard.press(KEY_LEFT_SHIFT);
bleKeyboard.write(KEY_F15);
bleKeyboard.releaseAll();
}
digitalWrite(row_pin2, LOW);

//Button 3
digitalWrite(row_pin3, HIGH);
if(digitalRead(col_pin1) == HIGH || digitalRead(col_pin2) == HIGH || digitalRead(col_pin3) == HIGH || digitalRead(col_pin4) == HIGH){
bleKeyboard.press(KEY_LEFT_CTRL);
bleKeyboard.press(KEY_LEFT_SHIFT);
bleKeyboard.write(KEY_F16);
bleKeyboard.releaseAll();
}
digitalWrite(row_pin3, LOW);

//Button 4
digitalWrite(row_pin4, HIGH);
if(digitalRead(col_pin1) == HIGH || digitalRead(col_pin2) == HIGH || digitalRead(col_pin3) == HIGH || digitalRead(col_pin4) == HIGH){
bleKeyboard.press(KEY_LEFT_CTRL);
bleKeyboard.press(KEY_LEFT_SHIFT);
bleKeyboard.write(KEY_F17);
bleKeyboard.releaseAll();
}
digitalWrite(row_pin4, LOW);

//Button 5
digitalWrite(row_pin5, HIGH);
if(digitalRead(col_pin1) == HIGH || digitalRead(col_pin2) == HIGH || digitalRead(col_pin3) == HIGH || digitalRead(col_pin4) == HIGH){
bleKeyboard.press(KEY_LEFT_CTRL);
bleKeyboard.press(KEY_LEFT_SHIFT);
bleKeyboard.write(KEY_F14);
bleKeyboard.releaseAll();
}
digitalWrite(row_pin5, LOW);

//Button 6
//Change screen button

if(digitalRead(col_pin1) == HIGH || digitalRead(col_pin2) == HIGH || digitalRead(col_pin3) == HIGH || digitalRead(col_pin4) == HIGH){
// change to next LCD screen
layerstate++;
}

if (layerstate > 3){
  layerstate = 1;
}

if (layerstate == 1){
  // Draw layer 1 icons
  drawBmp("/icon1.bmp", 13, 13);
  drawBmp("/icon2.bmp", 195, 13);
  drawBmp("/icon3.bmp", 377, 13);
  drawBmp("/icon4.bmp", 13, 214);
  drawBmp("/icon5.bmp", 195, 214);
  drawBmp("/changeicon.bmp", 377, 214);
}

if (layerstate == 2){
  // Draw layer 2 icons
  drawBmp("/icon6.bmp", 13, 13);
  drawBmp("/icon7.bmp", 195, 13);
  drawBmp("/icon8.bmp", 377, 13);
  drawBmp("/icon9.bmp", 13, 214);
  drawBmp("/icon10.bmp", 195, 214);
  drawBmp("/changeicon.bmp", 377, 214);
}

if (layerstate == 3){
  // Draw layer 3 icons
  drawBmp("/icon11.bmp", 13, 13);
  drawBmp("/icon12.bmp", 195, 13);
  drawBmp("/icon13.bmp", 377, 13);
  drawBmp("/icon14.bmp", 13, 214);
  drawBmp("/icon15.bmp", 195, 214);
  drawBmp("/changeicon.bmp", 377, 214);
}

}


