#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../base64.h"


int main(int argc, char**argv)
{
    int is_decode = 0;
    for(int i = 1; i < argc; ++i) {
        int cmp = strcmp("-d", argv[i]);
        if(cmp == 0) {
            is_decode = 1;
        }
    }
    
    size_t buff_size = 17280;
    size_t out_buff_size = is_decode ? base64_calculate_decoded_size(buff_size) : base64_calculate_encoded_size(buff_size);
    unsigned char *data_buffer = (unsigned char*)malloc(buff_size);
    unsigned char *out_buffer = (unsigned char*)malloc(base64_calculate_encoded_size(out_buff_size));
    if(!data_buffer || !out_buffer) {
        fprintf(stderr, "Bad malloc\n");
        return -1;
    }
    while(!feof(stdin)) {
        size_t readed_size = fread(data_buffer, 1 ,buff_size, stdin);
        size_t out_size;
        if(is_decode) {
            out_size = base64_decode_safe(data_buffer, readed_size, out_buffer);
        } else {
            out_size = base64_encode(data_buffer,readed_size, out_buffer);
        }
        fwrite(out_buffer,1,out_size, stdout);
    };
    return 0;
}