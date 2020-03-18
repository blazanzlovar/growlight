import time
import serial


      
ser = serial.Serial(
              
	port='/dev/ttyS0',
    baudrate = 9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
    )
    
    
 #loging to cloud
from Adafruit_IO import *
aio = Client("LEDgrow","aio_xqTa62iyYJVwjTIQKBAGvO7J5DGu") 
      

	
      
while 1:
	#podatek = input ("vnesi cifro1:::")
	#temp = podatek.encode()
	#ser.write(temp)
	#ser.flushOutput()
	#ser.flushInput()
	#naza = ser.readline()
	#nazaj = ser.readline()
	#print(nazaj)
	
	#numb = input("vnesi cifro") 
	#aio.send("helloone",numb)
	
	numb = input("vnesi cifro") 
	aio.send("helloone",numb)
	
	
	time.sleep(1)
	
	



