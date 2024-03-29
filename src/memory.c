/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdio.h>
/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/***********************************************************
 Function Definitions Assignment 4
***********************************************************/
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	
	for (size_t i = 0; i < length; i++){
		* dst = * src;
		src++;
		dst++;
	}
	return dst;
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

	if (src < dst && dst < (src + length)){
		src = src + length-1;
		dst = dst + length-1;

		for (size_t i = length; i > 0; i--){
			*dst = *src;
			src--;
			dst--;
		}
    
	} else {
		my_memcopy(src, dst, length);
	}

	return dst;
}


uint8_t * my_memset(uint8_t *src, size_t length, uint8_t value){

	for(size_t i = 0; i< length; i++){
		uint8_t *Ptr = src + sizeof(uint8_t) * i;
		*Ptr = value;
    }
	return src;
}

uint8_t * my_memzero(uint8_t *src, size_t length){
	
	for(size_t i = 0; i< length; i++){
		uint8_t *Ptr = src + sizeof(uint8_t) * i;
		*Ptr = 0;
    }
	return src;
}

uint8_t * my_reverse(uint8_t *src, size_t length) {
    
    uint8_t * reverseBuffer = malloc(length * sizeof(uint8_t));
    for(size_t i = 0; i < length; i++){
	uint8_t *ptr = src + sizeof(uint8_t) * i;
	*(reverseBuffer + sizeof(uint8_t) * length - i-1) =  *ptr;
    }
    
    for(size_t i = 0; i < length; i++){
	uint8_t *ptr = src + sizeof(uint8_t) * i;
	uint8_t *reverseBufferPtr = reverseBuffer + sizeof(uint8_t) * i;
	* ptr = *reverseBufferPtr;
    }

    return src;
}

int32_t * reserve_words(size_t length) {

    int32_t *ptr = malloc(length * sizeof(size_t));

    if(ptr == NULL){
       printf("Error: pointer null");
    }
    
    return ptr;
}

void free_words(uint32_t *src) {
    free(src);
}

