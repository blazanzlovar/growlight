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
	garba = "1255"
	y = garba.encode()
	ser.write(y)
	x=ser.readline()
	print(x)
	time.sleep(1)
