from time import sleep
import serial

# HAUNTED HOUSE INTENTS
# Ghost ------- 1
# Corpse ------ 2
# LightsOut --- 3
# Flicker ----- 4
# Noise ------- 5

def play_out_intent(intent):
    arduinoOut = serial.Serial('COM7', 9600)
    cases = {
        "Ghost": 1,
        "Corpse": 2,
        "LightsOut": 3,
        "Flicker": 4,
        "Creaking": 5
    }
    print(intent)
    output = str(cases.get(intent, 35))
    print(output)
    machineGun = 0
    while (machineGun < 10):
        arduinoOut.write(output.encode())
        sleep(.1)
        machineGun+=1