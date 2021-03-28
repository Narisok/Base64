#include "../base64.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int check_safe_decode_run(char*input, char* decoded)
{
    unsigned char * dd = (unsigned char*)malloc(base64_calculate_encoded_size(strlen(input)));
    size_t count = base64_decode_safe(input, strlen(input),dd);
    if(count != strlen(decoded)) return 0;

    int res = strcmp(dd, decoded);

    return res == 0;
}