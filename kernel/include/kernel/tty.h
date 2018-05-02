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
 * @file tty.h
 * 
 * @brief Functions to print statements to terminal in early stages of boot.
 */

#ifndef __PARADOX_OS_TTY_
#define __PARADOX_OS_TTY_

#include <string.h>
#include <stddef.h>


/*
 * Function: terminal_initialize
 * 
 * @params      None
 * @return      None
 * 
 * Initializes the terminal display so that it can be used.
 */
void terminal_initialize(void);

void terminal_write(const char* data, size_t size);

void terminal_putchar(char c);

/*
 * Function: terminal_writestring
 * 
 * @param data      Constant character array. The string
 *                  that is to be printed      
 * @return      None
 * 
 * Puts the given string into the terminal.
 */

void terminal_writestring(const char* data);

#endif