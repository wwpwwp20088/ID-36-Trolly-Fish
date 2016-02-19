#ifndef ENEMIES_H
#define ENEMIES_H

#include <Arduino.h>

#define MAX_ENEMIES             8
#define GAME_LEFT               3

#define GAME_TOP                3
#define GAME_BOTTOM             54

#define ENEMY_BAD               0
#define ENEMY_JELLY             1
#define ENEMY_EEL               2

#define BURST_LENGTH            15
#define BURST_WAIT              20

extern Arduboy arduboy;


byte fishFrame = 0;

PROGMEM const unsigned char badFishy_plus_mask[] = {
// width, height
16, 16,
// frame 0
0x00, 0x80, 0x80, 0xE0, 0xA0, 0xF0, 0x70, 0xF8, 0xD8, 0xFC, 
0x8C, 0xFE, 0xA4, 0xFF, 0xCD, 0xFF, 0xFD, 0xFF, 0xAB, 0xFF, 
0x29, 0xFF, 0x48, 0xFD, 0x70, 0xF8, 0x70, 0xFC, 0xFC, 0xFE, 
0x00, 0xFE, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 
0x02, 0x07, 0x03, 0x07, 0x02, 0x07, 0x03, 0x07, 0x01, 0x07, 
0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x00, 0x03, 0x00, 0x00, 
0x00, 0x01, 0x00, 0x01, 
// frame 1
0x80, 0xE0, 0xA0, 0xF0, 0x70, 0xF8, 0xD8, 0xFC, 0x8C, 0xFE, 
0xA4, 0xFF, 0xCD, 0xFF, 0xFD, 0xFF, 0xAD, 0xFF, 0xAB, 0xFF, 
0xD9, 0xFF, 0x70, 0xF9, 0x60, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 
0x00, 0xFC, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x02, 0x07, 
0x03, 0x07, 0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x05, 0x0F, 
0x06, 0x0F, 0x06, 0x0F, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01, 
0x01, 0x03, 0x00, 0x03, 
// frame 2
0x80, 0xF0, 0x70, 0xF8, 0xD8, 0xFC, 0x8C, 0xFE, 0xA4, 0xFF, 
0xCD, 0xFF, 0xFD, 0xFF, 0xAD, 0xFF, 0xAB, 0xFF, 0x99, 0xFF, 
0xF0, 0xF9, 0x60, 0xF0, 0xE0, 0xF0, 0xF0, 0xF8, 0x00, 0xF8, 
0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x07, 0x03, 0x07, 
0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x05, 0x0F, 0x0E, 0x0F, 
0x0D, 0x0F, 0x00, 0x0F, 0x00, 0x01, 0x01, 0x07, 0x07, 0x0F, 
0x00, 0x0F, 0x00, 0x00, 
// frame 3
0x80, 0xE0, 0xA0, 0xF0, 0x70, 0xF8, 0xD8, 0xFC, 0x8C, 0xFE, 
0xA4, 0xFF, 0xCD, 0xFF, 0xFD, 0xFF, 0xAD, 0xFF, 0xAB, 0xFF, 
0xD9, 0xFF, 0x70, 0xF9, 0x60, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 
0x00, 0xFC, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x02, 0x07, 
0x03, 0x07, 0x02, 0x07, 0x03, 0x07, 0x03, 0x07, 0x05, 0x0F, 
0x06, 0x0F, 0x06, 0x0F, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01, 
0x01, 0x03, 0x00, 0x03, 
};

PROGMEM const unsigned char jellyFish_plus_mask[] = {
// width, height
16, 24,

// frame 0
0x00, 0x80, 0x80, 0xE0, 0x60, 0xF0, 0x10, 0xF8, 0x28, 0xFC, 
0xB8, 0xFC, 0x94, 0xFE, 0x84, 0xDE, 0x84, 0xCE, 0x84, 0xCE, 
0x88, 0xDC, 0x08, 0x9C, 0x10, 0xF8, 0x60, 0xF0, 0x80, 0xE0, 
0x00, 0x80, 0x00, 0x07, 0x07, 0x0F, 0x08, 0x1F, 0x08, 0xFF, 
0xEF, 0xFF, 0x0F, 0xFF, 0xE7, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 
0xE7, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0x08, 0xFF, 0x08, 0x1F, 
0x07, 0x0F, 0x00, 0x07, 0x00, 0x0C, 0x08, 0x1C, 0x08, 0x1C, 
0x04, 0x0F, 0x03, 0xF7, 0x70, 0xFF, 0x0F, 0x7F, 0x00, 0x0F, 
0x00, 0x0F, 0x0F, 0x7F, 0x70, 0xFF, 0x03, 0xF7, 0x04, 0x0F, 
0x08, 0x1C, 0x08, 0x1C, 0x00, 0x0C, 
// frame 1
0x00, 0x80, 0x80, 0xC0, 0x40, 0xE0, 0xA0, 0xF0, 0x60, 0xF0, 
0x50, 0xF8, 0x10, 0x78, 0x10, 0x38, 0x10, 0x38, 0x10, 0x38, 
0x10, 0x38, 0x20, 0x70, 0x20, 0x70, 0x40, 0xE0, 0x80, 0xC0, 
0x00, 0x80, 0x0F, 0x1F, 0x10, 0x3F, 0x10, 0x3F, 0x18, 0xFF, 
0xDC, 0xFF, 0x0E, 0xFF, 0xCE, 0xFF, 0x0E, 0xFF, 0x0E, 0xFF, 
0xCE, 0xFF, 0x0E, 0xFF, 0xDC, 0xFF, 0x18, 0xFE, 0x10, 0x3F, 
0x10, 0x3F, 0x0F, 0x1F, 0x04, 0x0E, 0x04, 0x0E, 0x04, 0x6E, 
0x22, 0x77, 0x11, 0x3B, 0x08, 0x1F, 0x07, 0x0F, 0x00, 0x07, 
0x00, 0x07, 0x07, 0x0F, 0x08, 0x1F, 0x11, 0x3B, 0x22, 0x77, 
0x04, 0x6E, 0x04, 0x0E, 0x04, 0x0E, 
// frame 2
0x00, 0x80, 0x80, 0xE0, 0x60, 0xF0, 0x10, 0xF8, 0x28, 0xFC, 
0xB8, 0xFC, 0x94, 0xFE, 0x84, 0xDE, 0x84, 0xCE, 0x84, 0xCE, 
0x88, 0xDC, 0x08, 0x9C, 0x10, 0xF8, 0x60, 0xF0, 0x80, 0xE0, 
0x00, 0x80, 0x00, 0x07, 0x07, 0x0F, 0x08, 0x1F, 0x08, 0xFF, 
0xEF, 0xFF, 0x0F, 0xFF, 0xE7, 0xFF, 0x07, 0xFF, 0x07, 0xFF, 
0xE7, 0xFF, 0x0F, 0xFF, 0xEF, 0xFF, 0x08, 0xFF, 0x08, 0x1F, 
0x07, 0x0F, 0x00, 0x07, 0x00, 0x1C, 0x0C, 0x1E, 0x02, 0x0F, 
0x01, 0x63, 0x20, 0x71, 0x10, 0x3F, 0x0F, 0x1F, 0x00, 0x0F, 
0x00, 0x0F, 0x0F, 0x1F, 0x10, 0x3F, 0x20, 0x71, 0x01, 0x63, 
0x02, 0x0F, 0x0C, 0x1E, 0x00, 0x1C, 
// frame 3
0x00, 0x00, 0x00, 0xE0, 0xE0, 0xF8, 0x18, 0xFC, 0x04, 0xFE, 
0x9A, 0xFF, 0xCD, 0xFF, 0xE1, 0xFF, 0xE1, 0xF3, 0xC1, 0xE3, 
0x82, 0xC7, 0x04, 0x9E, 0x18, 0xFC, 0xE0, 0xF8, 0x00, 0xE0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x04, 0xFF, 
0xF4, 0xFF, 0x07, 0xFF, 0xF7, 0xFF, 0x03, 0xFF, 0x03, 0xFF, 
0xF7, 0xFF, 0x07, 0xFF, 0xF4, 0xFF, 0x04, 0xFF, 0x03, 0x07, 
0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x1F, 0x1F, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 
0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0x1F, 0x3F, 0x00, 0x1F, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

PROGMEM const unsigned char eel_plus_mask[] = {
// width, height
80, 16,
// frame 0
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 
0xC0, 0xE0, 0x40, 0xE0, 0x40, 0xE0, 0xC0, 0xE0, 0xE0, 0xF0, 
0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 
0x60, 0xF0, 0x60, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0x40, 0xE0, 0x40, 0xE0, 0xC0, 0xE0, 
0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x06, 0x04, 0x0F, 0x0B, 0x1F, 0x17, 0x3F, 
0x1C, 0x3F, 0x19, 0x3F, 0x1B, 0x3F, 0x1C, 0x3F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0C, 0x1F, 
0x0E, 0x1F, 0x0E, 0x1F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x05, 0x0F, 0x05, 0x0F, 0x06, 0x0F, 
0x06, 0x0F, 0x03, 0x0F, 0x03, 0x07, 0x01, 0x03, 0x00, 0x03, 

// frame 1
0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0x60, 0xF0, 0xA0, 0xF0, 
0xA0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 
0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 
0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0x40, 0xE0, 0x40, 0xE0, 0xC0, 0xE0, 
0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 
0x02, 0x07, 0x05, 0x0F, 0x0B, 0x1F, 0x0E, 0x1F, 0x0C, 0x1F, 
0x0D, 0x1F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0D, 0x1F, 
0x0C, 0x1F, 0x0C, 0x1F, 0x0C, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x05, 0x0F, 0x05, 0x0F, 0x06, 0x0F, 
0x06, 0x0F, 0x03, 0x0F, 0x03, 0x07, 0x01, 0x03, 0x00, 0x03, 

// frame 2
0x80, 0xC0, 0xC0, 0xE0, 0x20, 0xF0, 0x50, 0xF8, 0xD0, 0xF8, 
0x30, 0xF8, 0xF0, 0xF8, 0xF0, 0xF8, 0xE0, 0xF0, 0xE0, 0xF0, 
0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 
0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0x40, 0xE0, 0x40, 0xE0, 0xC0, 0xE0, 
0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 
0x00, 0x03, 0x01, 0x07, 0x07, 0x0F, 0x06, 0x0F, 0x06, 0x0F, 
0x07, 0x0F, 0x07, 0x0F, 0x07, 0x0F, 0x0F, 0x1F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0D, 0x1F, 
0x09, 0x1F, 0x09, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x05, 0x0F, 0x05, 0x0F, 0x06, 0x0F, 
0x06, 0x0F, 0x03, 0x0F, 0x03, 0x07, 0x01, 0x03, 0x00, 0x03, 

// frame 3
0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0x60, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 
0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0x60, 0xF0, 0xE0, 0xF0, 
0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 0xE0, 0xF0, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 
0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xD0, 0xF8, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 0xA0, 0xF0, 
0xA0, 0xF0, 0xA0, 0xF0, 0x40, 0xE0, 0x40, 0xE0, 0xC0, 0xE0, 
0xC0, 0xE0, 0x80, 0xC0, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00, 
0x00, 0x03, 0x02, 0x07, 0x05, 0x0F, 0x0B, 0x1F, 0x0E, 0x1F, 
0x0C, 0x1F, 0x0D, 0x1F, 0x0E, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x07, 0x1F, 0x08, 0x1F, 0x0D, 0x1F, 
0x0C, 0x1F, 0x0C, 0x1F, 0x0C, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 
0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x0F, 0x1F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 
0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x17, 0x3F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 0x0B, 0x1F, 
0x0B, 0x1F, 0x0B, 0x1F, 0x05, 0x0F, 0x05, 0x0F, 0x06, 0x0F, 
0x06, 0x0F, 0x03, 0x0F, 0x03, 0x07, 0x01, 0x03, 0x00, 0x03, 
};

// Enemy Type variables
int8_t numEels = 0;
int8_t numJellys = 0;
byte jellyMax = 1;
byte eelMax = 1;

struct Enemies
{
  public:
    int16_t  x;
    int16_t y;
    byte width, height;
    int8_t xSpeed, ySpeed;

    byte burst;
    byte burstTimer;

    byte type;
    bool active;

    void resetPos();
    

};

void Enemies::resetPos()
{
   x = 12  * random(12, 20);
   y = 10 * random(1, 6);

   if (type == ENEMY_JELLY)
      --numJellys;
      
   if (type == ENEMY_EEL)
      --numEels;

   active = false;
}

Enemies enemyFish[MAX_ENEMIES];

void createEnemy(byte type)
{
  if (type != ENEMY_JELLY || numJellys < jellyMax)
  if (type != ENEMY_EEL || numEels < eelMax)
  for (byte i = 0; i < MAX_ENEMIES; i++)
  {
    if (enemyFish[i].active == false)
    {
      enemyFish[i].active = true;
      enemyFish[i].type = type;
      enemyFish[i].xSpeed = -3;
      enemyFish[i].ySpeed = 0;
      enemyFish[i].width = 14;
      enemyFish[i].height = 10;

      if (type == ENEMY_JELLY)
      {
        enemyFish[i].ySpeed = -2;
        enemyFish[i].height = 20;
        numJellys++;
      }
      if (type == ENEMY_EEL)
      {
        enemyFish[i].xSpeed = -2;
        enemyFish[i].width = 70;
        numEels++;
      }

      return;
    }
  }
}

void updateEnemies()
{
  if (arduboy.everyXFrames(3))
  {
    for (byte i = 0; i < MAX_ENEMIES; i++)
    {
      if (enemyFish[i].active)
      {
        // ----- Bad Fishy -----
        // Bursts forward, with pause
        if (enemyFish[i].type == ENEMY_BAD)
        {
          if (enemyFish[i].burst > 0)
          {
            // Move while bursting
            enemyFish[i].x +=  enemyFish[i].xSpeed;
            --enemyFish[i].burst;
          }
          else
          {
            // Decrement time before next burst
            --enemyFish[i].burstTimer;
            if (enemyFish[i].burstTimer == 0)
            {
              // Timer up, reset burst and burstTimer
              enemyFish[i].burstTimer = BURST_WAIT;
              enemyFish[i].burst = BURST_LENGTH;
            }
          }
        }
  
        // ----- Jelly Fish -----
        // Bursts upward
        // Moves faster horizontally when bursting
        if (enemyFish[i].type == ENEMY_JELLY)
        {
          
          if (enemyFish[i].burst > 0)
          {
            // Move up while bursting
            enemyFish[i].y +=  enemyFish[i].ySpeed;
            // Faster left movement when bursting
            enemyFish[i].x +=  enemyFish[i].xSpeed;
            
            if (enemyFish[i].y <= GAME_TOP)
              enemyFish[i].burst = 1;
              
            --enemyFish[i].burst;
          }
          else
          {
            // Slower left movement not bursting
            enemyFish[i].x--;
            
            // Decrement time before next burst
            --enemyFish[i].burstTimer;

            // Drop y
            enemyFish[i].y -= enemyFish[i].ySpeed / 2;
            if (enemyFish[i].y > GAME_BOTTOM - enemyFish[i].height)
              enemyFish[i].burstTimer = 0;            // Reset timer when under screen
              
            if (enemyFish[i].burstTimer == 0)
            {
              // Timer up, reset burst and burstTimer
              enemyFish[i].burstTimer = random(10) + BURST_WAIT;
              enemyFish[i].burst = BURST_LENGTH;
            }
          }
        }
  
        // ----- Eel -----
        // Steady left movement
        if (enemyFish[i].type == ENEMY_EEL)
          enemyFish[i].x +=  enemyFish[i].xSpeed;
  
        // Outside of room, deactivate
        if ( enemyFish[i].x < (GAME_LEFT - enemyFish[i].width))  enemyFish[i].resetPos();
      }
    }
  }
}

void drawEnemies()
{
  if (arduboy.everyXFrames(6)) fishFrame++;
  if (fishFrame > 3) fishFrame = 0;
  for (byte i = 0; i < MAX_ENEMIES; i++)
  {
    if (enemyFish[i].type == ENEMY_BAD)
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y - 2, badFishy_plus_mask, (trollyFrame * (min(enemyFish[i].burst, 1))));
    if (enemyFish[i].type == ENEMY_JELLY)
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y - 2, jellyFish_plus_mask, (trollyFrame * (min(enemyFish[i].burst, 1))));
    if (enemyFish[i].type == ENEMY_EEL)
      sprites.drawPlusMask(enemyFish[i].x, enemyFish[i].y - 2, eel_plus_mask, trollyFrame);
  }
}


#endif
