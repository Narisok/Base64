#!bin/bash

mkdir -p ./Build/Tests
touch Build/.gitignore
echo "*" > Build/.gitignore

rm -f ./Build/Tests/cur.test
gcc -g ./Tests/run.c ./base64.c -o ./Build/Tests/cur.test

if [[ -f ./Build/Tests/cur.test ]]
then
    ./Build/Tests/cur.test
else
    echo Compile error!
fi