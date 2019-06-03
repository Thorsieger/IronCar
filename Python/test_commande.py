import sys
import serial
import time
from time import sleep

ser = serial.Serial(‘/dev/ttyACM0’,9600)
vit = 2098
dir = 1060

etat = 0
while 1 :
	ser.write(str(dir) + ‘\n’)
	ser.write(str(vit) + ‘\n’)
	if etat == 0:
		dir +=1
	else
		dir -=1
	if dir%10 == 0 :
		if etat == 0 :
			vit +=1
		else
			vit -=1
	if dir >= 1120 :
		etat = 1
	if dir <= 1060 :
		etat =0
	sleep(0.1)
