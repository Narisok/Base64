#include "base64.h"
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

static const char base64_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const unsigned char * data, const int size_bytes)
{
    int encodeLength = (size_bytes + 2)/3*4;

    char *encodedData = malloc(encodeLength + 1);
    if(!encodedData) {
        return NULL;
    }

    char *iter = encodedData;
    const unsigned char *dataIter = data;
    int i = 0;

    while(i < size_bytes - 2) {
        *iter++ = base64_map[  dataIter[0] >> 2 ];
        *iter++ = base64_map[ (dataIter[0]&0x3)<<4 | dataIter[1]>>4 ];
        *iter++ = base64_map[ (dataIter[1]&0xF)<<2 | dataIter[2]>>6 ];
        *iter++ = base64_map[  dataIter[2]&0x3F ];
        dataIter += 3;
        i+=3;
    }

    if(size_bytes > i) {
        *iter++ = base64_map[  *dataIter>>2 ];
        if(size_bytes-1 <= i ) {
            *iter++ = base64_map[ (*dataIter&0x3)<<4 ];
            *iter++ = '=';
        } else {
            *iter++ = base64_map[ (dataIter[0]&0x3)<<4 | dataIter[1]>>4 ];
            *iter++ = base64_map[ (dataIter[1]&0xF)<<2 ];
        }
        *iter++ = '=';
    }

    *iter = '\0';
    return encodedData;
}