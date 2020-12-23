#!/bin/sh
#sed -i 's/<iarduino_I2C_Motor\.h>/\"\.\.\/iarduino_I2C_Motor\.h\"/' *.ino
#sed -i '3d' *.ino
#sed -i '3 s/\ \ \ //' *.cpp
#sed -i '2 a #include "Serial.h"' *.ino
sed -i '28 s/.cpp//g' Makefile
#sed -i 's/void setup/int main/' *.ino
#sed -i '7 s/{/{  /' *
#sed -i '11 a \ \ \ \ loop();' *.cpp
#for i in *.ino; do f=`echo $i | cut -d. -f1`; mv $i $f.cpp; done
