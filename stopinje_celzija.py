import glob
import time

base_dir = '/sys/bus/w1/devices/'
device_folder = glob.glob(base_dir + '28*')[0]
device_file = device_folder + '/w1_slave'



def read_temp_raw():
    f = open(device_file, 'r')
    lines = f.readlines()
    f.close()
    return lines

def read_temp():
    lines = read_temp_raw()
    while lines[0].strip()[-3:] != 'YES':
        time.sleep(0.2)
        lines = read_temp_raw()
    equals_pos = lines[1].find('t=')
    if equals_pos != -1:
        temp_string = lines[1][equals_pos+2:]
        temp_c = float(temp_string) / 1000.0
        temp_f = temp_c * 9.0 / 5.0 + 32.0
        return temp_c
    
             

    
#loging to cloud
from Adafruit_IO import *
aio = Client("LEDgrow","aio_xqTa62iyYJVwjTIQKBAGvO7J5DGu") 


while True:
    print(read_temp())   
    temp_c = read_temp()
    var=temp_c

    if [temp_c < 35]:
         print ("temparatura je pod 35 stopinj celzija")
         print (aio.send("helloone",temp_c))
    else:
        while temp_c > 35:
           continue
#    aio.send("helloone",temp_c)
                  
    time.sleep(1)




 


