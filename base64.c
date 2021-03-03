#include "base64.h"

#ifdef __cplusplus
extern "C" {
#endif

static const char base64_map[]    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char base64url_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";


size_t base64_calculate_encoded_size(size_t decoded_bytes_count)
{
    return (decoded_bytes_count + 2)/3*4;
}

size_t base64_calculate_decoded_size(size_t encoded_bytes_count)
{
    return (encoded_bytes_count+3)/4*3;
}

static inline size_t base64_encode_base(const char* map, const unsigned char * data_to_encode, size_t bytes_count, char *encoded_destination)
{
    char *iter = encoded_destination;
    const unsigned char *dataIter = data_to_encode;
    size_t i = 0;
    while(i + 2 < bytes_count) {
        *iter++ = map[  dataIter[0] >> 2 ];
        *iter++ = map[ (dataIter[0]&0x3)<<4 | dataIter[1]>>4 ];
        *iter++ = map[ (dataIter[1]&0xF)<<2 | dataIter[2]>>6 ];
        *iter++ = map[  dataIter[2]&0x3F ];
        dataIter += 3;
        i+=3;
    }

    if(bytes_count > i) {
        *iter++ = map[  *dataIter>>2 ];
        if(bytes_count-1 <= i ) {
            *iter++ = map[ (*dataIter&0x3)<<4 ];
            *iter++ = '=';
        } else {
            *iter++ = map[ (dataIter[0]&0x3)<<4 | dataIter[1]>>4 ];
            *iter++ = map[ (dataIter[1]&0xF)<<2 ];
        }
        *iter++ = '=';
    }

    return iter - encoded_destination;
}

size_t base64_encode(const unsigned char * data_to_encode, size_t bytes_count, char *encoded_destination)
{
    return base64_encode_base(base64_map, data_to_encode, bytes_count, encoded_destination);
}

size_t base64url_encode(const unsigned char * data_to_encode, size_t bytes_count, char *encoded_destination)
{
    return base64_encode_base(base64url_map, data_to_encode, bytes_count, encoded_destination);
}




static const unsigned char base64_ancii [] = {
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 0 - 11
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 12 - 23
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 24 - 35
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 36 - 42
    /* + */ 62, // 43
    0x40, 
    /* - */ 62, // 45
    0x40, // 46
    /* / */ 63, // 47
    /* 0 */ 52, 53, 54, 55, 56, 57, 58, 59, 60, /* 9 */ 61, // 48 - 57
    0x40, 0x40, 0x40, // 58 - 60
    /* = */ 64, // 61
    0x40, 0x40, 0x40, // 62 - 64
    /* A */  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, /* Z */ 25, // 65 - 90
    0x40, 0x40, 0x40, 0x40, // 91 - 94
    /* _ */ 63,  // 95
    0x40, // 96
    /* a */ 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, /* z */ 51, // 97 - 122
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 120 - 131
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 132 - 143
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 144 - 155
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 156 - 167
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 168 - 179
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 180 - 191
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 192 - 203
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 204 - 215
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 216 - 227
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 228 - 239
    0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 240 - 251
    0x40, 0x40, 0x40, 0x40                                          // 252 - 255
};


size_t base64_decode(const char *encoded_data, size_t bytes_count, unsigned char *decoded_destination)
{
    unsigned char *iter = decoded_destination;
    size_t i = 0;
    while(i + 4 < bytes_count) {
        unsigned char a = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char b = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char c = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char d = base64_ancii[(unsigned char)encoded_data[i++]];
        *iter++ = a << 2 | b >> 4;
        *iter++ = b << 4 | c >> 2;
        *iter++ = c << 6 | d;
    }

    if(bytes_count == i + 4) {
        unsigned char a = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char b = base64_ancii[(unsigned char)encoded_data[i++]];
        *iter++ = a << 2 | b >> 4;
        unsigned char c = base64_ancii[(unsigned char)encoded_data[i++]];
        if(c != 64) {
            *iter++ = b << 4 | c >> 2;
            unsigned char d = base64_ancii[(unsigned char)encoded_data[i++]];
            if(d != 64) {
                *iter++ = c << 6 | d;
            }
        }
    }

    return iter - decoded_destination;
}

size_t base64_decode_safe(const char *encoded_data, size_t bytes_count, unsigned char *decoded_destination)
{
    unsigned char *iter = decoded_destination;
    size_t i = 0;
    while(i + 4 < bytes_count) {
        unsigned char a = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char b = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char c = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char d = base64_ancii[(unsigned char)encoded_data[i++]];
        if(a != 64 && b != 64) {
            *iter++ = a << 2 | b >> 4;
            if(c != 64) {
                *iter++ = b << 4 | c >> 2;
                if(d != 64) {
                    *iter++ = c << 6 | d;
                }
            }
        }
    }

    if(bytes_count > i + 1) {
        unsigned char a = base64_ancii[(unsigned char)encoded_data[i++]];
        unsigned char b = base64_ancii[(unsigned char)encoded_data[i++]];
        if(a != 64 && b != 64) {
            *iter++ = a << 2 | b >> 4;
            if(bytes_count > i) {
                unsigned char c = base64_ancii[(unsigned char)encoded_data[i++]];
                if(c != 64) {
                    *iter++ = b << 4 | c >> 2;
                    if(bytes_count > i) {
                        unsigned char d = base64_ancii[(unsigned char)encoded_data[i++]];
                        if(d != 64) {
                            *iter++ = c << 6 | d;
                        }
                    }

                }
            }
        }
    }

    return iter - decoded_destination;
}

#ifdef __cplusplus
}
#endif