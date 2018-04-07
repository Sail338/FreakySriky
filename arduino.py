from time import sleep
import serial

# HAUNTED HOUSE INTENTS
# Ghost ------- 40
# Corpse ------ 41
# LightsOut --- 42
# Flicker ----- 43
# Noise ------- 44

def play_out_intent(intent):
    arduinoOut = serial.Serial('COM6', 9600)
    cases = {
        Ghost: 40,
        Corpse: 41,
        LightsOut: 42,
        Flicker: 43,
        Noise: 44
    }
    
    output = str(cases.get(intent, 35))
    arduinoOut.write(output.encode())