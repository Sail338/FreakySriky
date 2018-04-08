import config
import requests
import socket
import re
import arduino
import watson_developer_cloud
import threading
import operator

intents = ['Ghost','Corpse','LightsOut','Flicker','Noise']
def grabOauth():
    a = requests.get("https://id.twitch.tv/oauth2/authorize?client_id=" + config.CLIENT_ID +"&redirect_uri=http://localhost&response_type=token%20id_token &scope=openid + chat_login+channel_editor")
    print(a)
global count_ds
count_ds = {}

def clearDS():
    for i in intents:
        count_ds[i] = 0

clearDS()

def printit():
  global count_ds
  ds = count_ds
  threading.Timer(3.0, printit).start()
  if len(ds) >0:
     check = max(ds.items(), key=operator.itemgetter(1))[0]
     print("BEFORE" +str(count_ds))
     if(count_ds[check] != 0):
#        arduino.play_out_intent(check)
        clearDS()
        print("AFRER" + str(count_ds))
  else:
     print("nobody has polled yet")
  


def connectToTwitch():
    global count_ds
    try:
        client = socket.socket()
        dat = ("irc.chat.twitch.tv",6667)
        client.connect( ("irc.chat.twitch.tv",6667))
        message_user = 'NICK sail338\r\n'
        message = "PASS " + config.OAUTH_TOKEN +"\r\n"
        client.sendto(message.encode('utf-8'),dat)
        client.sendto(message_user.encode('utf-8'),dat)
        client.sendto('JOIN #sail338 \r\n'.encode(),dat)
        conversation = watson_developer_cloud.ConversationV1(
        username = config.USERNAME, 
        password = config.PASSWORD,
        version = '2017-05-26'
        )

        workspace_id = config.WORKSPACE_ID
        #start polling
        printit()
        while True:
            #poll for 5 seconds
            did_pool = False

            data = client.recv(1024)
            print(data)
            if data != "b''":
                #Parse data
                data = str(data)
                parsed = data.split(":")
                if len(parsed) >2:
                    check = parsed[2]
                    check = check.strip("\\r\\n")
                    
                    check = check.replace("\\r\\n'","")
                    response = conversation.message(
                        workspace_id = workspace_id,
                        input = {
                            'text': check
                        }
                    )
                    intent = response['output']['text']

                    print(intent)
                    if check in intents:
                        print("Found something to increment")
                        count_ds[check] +=1                        
                         

    except Exception as e:
        print(str(e))

connectToTwitch()

