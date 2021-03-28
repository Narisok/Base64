#!bin/bash

mkdir -p Build/Examples
touch Build/.gitignore
echo "*" > Build/.gitignore
gcc -O2 Examples/utility.c base64.c -o Build/Examples/utility
