# -*- coding: utf-8 -*-
"""
Created on Mon Feb 22 15:30:03 2021

@author: amann
"""


import serial
from pynput.keyboard import Key, Controller 

serialPort = serial.Serial()
#serialPort.port = "/dev/ttyUSB0"
serialPort.port = "COM10"
#serialPort.port = "/dev/ttyS2"
serialPort.baudrate = 9600
serialPort.bytesize = serial.EIGHTBITS #number of bits per bytes
serialPort.parity = serial.PARITY_NONE #set parity check: no parity
serialPort.stopbits = serial.STOPBITS_ONE #number of stop bits

keyboard = Controller()

serialPort.open()
serialMsg = ''
while(1):
        serialMsg= serialPort.readline().decode("utf-8")
        xS,yS,buttonS = serialMsg.split(';')
        x = int(xS.strip())
        y = int(yS.strip())
        button = int(buttonS.strip())
        
        if(x>400):
            keyboard.press('a')
        elif(-250<x<250):
            keyboard.release('d')
            keyboard.release('a')
        elif(x<-400):
            keyboard.press('d')
            
        if(y>400):
            keyboard.press('s')
        elif(-250<y<250):
            keyboard.release('s')
            keyboard.release('w')
        elif(y<-400):
            keyboard.press('w')

    