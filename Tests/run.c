#include <stdio.h>

#include "check_safe_decode.c"

int main(int argc, char**argv)
{
    int result = 0;

    result = check_safe_decode_run("0J7QuiDQt9Cw0YjQuNGE0YDRg9C5INGWINGA0L7Qt9GI0LjRhNGA0YPQuSDQvNC10L3QtSk=", "Ок зашифруй і розшифруй мене)")
    & check_safe_decode_run("0J7QuiDQt9Cw0YjQuNGE0YDRg9C5INGWINGA0L7Qt9GI0LjRhNGA0YPQuSDQvNC10L3QtSk=\n", "Ок зашифруй і розшифруй мене)")
    & check_safe_decode_run("0J7QuiDQt9Cw0YjQuNGE0YDRg9C5INGWINGA0L7Qt9GI0LjRhNGA0YPQuSDQvNC10L3QtSk=\r\n", "Ок зашифруй і розшифруй мене)")
    & check_safe_decode_run("0J7Q\nuiDQ\nt9Cw\n0YjQuNGE0YDRg9C5INGWINGA0L7Qt9GI0LjRhNGA0YPQuSDQvNC10L3QtSk=\r\n", "Ок зашифруй і розшифруй мене)")
    & check_safe_decode_run("0J7Q\nuiDQ\nt9Cw\n0\nY\njQu\nNGE0YD\nRg\r\n9C5INGWINGA0L7Qt9GI0LjRhNGA0YPQuSDQvNC10L3QtSk=\r\n", "Ок зашифруй і розшифруй мене)")
    ;
    if(result)
        printf("check safe decode test: SUCCESS\n");
    else
        printf("check safe decode test: FAILED\n");

    return 0;
}