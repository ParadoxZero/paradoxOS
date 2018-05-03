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

#ifndef __STRING_H_
#define __STRING_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================= 
 * Memory manupulation APIs
 * -------------------------
 * 
 * The following APIs may be used to manupulate
 * type generic continuous memory blocks.
 * 
 *=============================================*/

int memcmp(const void* a, const void* b, size_t size);

void* memcpy(void* __restrict dest, const void* __restrict src, size_t size);

void* memmove(void* dst, const void* src, size_t size);

void* memset(void* loc, int val, size_t size);

/* ========================
 * String Manupulation APIs
 * ------------------------
 * 
 * ========================*/

size_t strlen(const char* str);

int strcmp(const char* a, const char* b);   // Unimplemented

void strcat(char* dst, const char* src);    // Unimplemented

void strcpy(char* dst, const char* src);    // Unimplemented

//TODO: Add the rest

#ifdef __cplusplus
}
#endif

#endif //__STRING_H_