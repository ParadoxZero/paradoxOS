/* 
 * This file is part of the ParadoxOS (https://github.com/ParadoxZero/paradoxOS).
 * Copyright (c) 2018 Sidhin S Thomas.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * @file keycode.h
 * 
 * @brief This file contains the keycode definitions used in the kernel
 * 
 */ 

#include <stdint.h>

enum KeyCodes {
    KEY_ESC,
    
    KEY_1,   
    KEY_2,   
    KEY_3,   
    KEY_4,   
    KEY_5,   
    KEY_6,   
    KEY_7,   
    KEY_8,   
    KEY_9,   
    KEY_0,   
    
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    
    KEY_SHIFT_L,
    KEY_ALT_L,
    KEY_CTR_L,

    KEY_SHIFT_R,
    KEY_ALT_R,
    KEY_CTR_R,
    
    KEY_RETURN,
    KEY_BACKSPACE,
    KEY_TAB,
    KEY_SPACE,
    
    KEY_NUM_1,   
    KEY_NUM_2,   
    KEY_NUM_3,   
    KEY_NUM_4,   
    KEY_NUM_5,   
    KEY_NUM_6,   
    KEY_NUM_7,   
    KEY_NUM_8,   
    KEY_NUM_9,   
    KEY_NUM_0,   

    KEY_NUM_ASTR,
    KEY_NUM_PLUS,
    KEY_NUM_MINUS,
    KEY_NUM_RETURN,
    KEY_NUM_PERIOD,
    
    /* These are keycodes for the punctuation keys */
    
    KEY_SQR_BRKT_OPEN, 
    KEY_SQR_BRKT_CLOSE,
    KEY_BACK_SLASH,
    KEY_SEMICOLON,
    KEY_SINGLE_Q,
    KEY_COMMA,
    KEY_PERIOD,
    KEY_SLASH,
    KEY_MINUS,
    KEY_EQUAL,
    KEY_TILDA,
    
    /* Toggle Keys */
    KEY_CAPS_LOCK,
    KEY_SCROLL_LOCK,
    KEY_NUM_LOCK,
    
    /* Arrow keys */
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,

    /* Function Keys */
    KEY_F1,   
    KEY_F2,   
    KEY_F3,   
    KEY_F4,   
    KEY_F5,   
    KEY_F6,   
    KEY_F7,   
    KEY_F8,   
    KEY_F9,   
    KEY_F10,
    KEY_F11,
    KEY_F12,

    KEY_UNDEFINED

};

#define SCANCODE_1_PRESSED_LIMIT 0x58 // inclusive
#define SCANCODE_1_UNDEFINDE_LIMIT 0xD8  //inclusive

uint_8 scancode[] = {
#ifdef SCANCODE_1
KEY_ESC, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8,
KEY_9, KEY_0, KEY_MINUS, KEY_EQUAL, KEY_BACKSPACE, KEY_TAB, KEY_Q,
KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P,
KEY_SQR_BRKT_OPEN, KEY_SQR_BRKT_CLOSE, KEY_RETURN, KEY_CTR_L,
KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON,
KEY_SINGLE_Q, KEY_TILDA, KEY_SHIFT_L, KEY_BACK_SLASH, KEY_Z, KEY_X,
KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH,
KEY_SHIFT_R, KEY_NUM_ASTR, KEY_ALT_L, KEY_SPACE, KEY_CAPS_LOCK, KEY_F1,
KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10,
KEY_NUM_LOCK, KEY_SCROLL_LOCK, KEY_NUM_7, KEY_NUM_8, KEY_NUM_9, KEY_NUM_MINUS,
KEY_NUM_4, KEY_NUM_5, KEY_NUM_6, KEY_NUM_PLUS, KEY_NUM_1, KEY_NUM_2, KEY_NUM_3,
KEY_NUM_0, KEY_NUM_PERIOD, KEY_F11, KEY_F12
#endif //SCANCODE_1
}; // scancode