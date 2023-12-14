/*
 * lines 193,194,215, and 216 in 'ScrollingText8x8Display.cpp', the 
 * HIGH an LOW statements can be flipped if using a common anode 
 * or common cathode 8x8 led matrix,  at compile time.     
 * Harold Moore --- 12/13/23
 * 
 *
 *---------Arduino Nano an 1088AB led dot matrix connections--------
 *------------------------------------------------------------------      
 *  ROWS               1      2     3     4     5     6     7     8
 *  1088AB pins        9     14     8    12     1     7     2     5
 *  NANO   pins       D2     D3    D4    D5    D6    D7    D8    D9

 *  COLUMNS            1      2     3     4     5     6     7     8
 *  1088AN pins       13      3     4    10     7    11    15    16    
 *  NANO   pins      D10    D11   D12   D13    A0    A1    A2    A3  
---------------------------ARDUINO NANO----------------------------
                            
              GND - - - - - - - - |                  |
               B3- - - - - - - -| |
              +5V - - - - - - | | |
                              o o o  
                              o o o 
                             /  |  \
                            B4  B5  C6 
 
                           _ _ _ _ _ _
                          |   o o o   |
                          |   o o o   |
                     - D1 |o         o| VIN
                     - C0 |o         o| GND   
                     - C6 |o         o| RESET
                      GND |o         o| +5V
        9     220ohms- D2 |o         o| A7
       14     220ohms- D3 |o         o| A6
        8     220ohms- D4 |o         o| A5  
       12     220ohms- D5 |o         o| A4  
        1     220ohms- D6 |o Arduino o| A3 -         16
        7     220ohms- D7 |o   NANO  o| A2 -         15
        2     220ohms- D8 |o         o| A1 -         11
        5     220ohms- D9 |o         o| A0 -          6
       13            -D10 |o   ___   o| AREF
        3            -D11 |o  |USB|  o| +3.3V
        4            -D12 |o__|___|__o| D13          10
 

*/ 
 


#include "ScrollingText8x8Display.h"

ScrollingText8x8Display render;

void setup()
{

//------------------NANO----------------------------------------
  byte displayRowPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 
  byte displayColumnPins[] = {10, 11, 12, 13, A0, A1, A2, A3};
//--------------------------------------------------------------
  
//----------------ATtiny3226----------------------------------  
//  byte displayRowPins[] = {0, 1, 2, 3, 4, 5, 6, 7}; 
//  byte displayColumnPins[] = {10, 11, 12, 13, 17, 14, 15, 16};
//--------------------------------------------------------------

 // ScrollingDirection scrollingDirection = RIGHT_TO_LEFT;
  ScrollingDirection scrollingDirection = TOP_TO_BOTTOM;
  CharacterOrientation characterOrientation = TOP;
  render.init(displayRowPins, displayColumnPins, scrollingDirection, characterOrientation);
}

void loop()
{
 // float scrollingSpeed = 100;

  render.displayText("  M E R R Y  C H R I S T M A S !      ");
 // render.displayText("   K E 6 J M G    ");
 
 //  render.displayText(" C Q  C Q  C Q  D E ");
//  render.displayText("   K E 6 J M G    ");

//    render.displayText(" Moore Signs ");
//    render.displayText(" Dave is the Man !!! "); 
//    render.displayText(" HE ROCKS !!! ");

  render.displayText(" ");

//  float scrollingSpeed = 55.5;
//  render.displayText("slow.... text!", scrollingSpeed);
}
