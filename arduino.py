from time import sleep
import serial

arduinoOut = serial.Serial('COM6', 9600)

counter = 32
while True:
     counter +=1
     arduinoOut.write(str(chr(counter)).encode()) # Convert the decimal number to ASCII then send it to the Arduino
     sleep(.1) # Delay for one tenth of a second
     if counter == 255:
        counter = 32