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
          
      
while 1:
	podatek = "1250"
	temp = podatek.encode()
	ser.write(temp)
	nazaj = ser.readline()
	print(nazaj)
	time.sleep(1)
	
