import config
import requests
import socket
import re

def grabOauth():
    a = requests.get("https://id.twitch.tv/oauth2/authorize?client_id=" + config.CLIENT_ID +"&redirect_uri=http://localhost&response_type=token%20id_token &scope=openid + chat_login+channel_editor")
    print(a)


def connectToTwitch():
    try:
        client = socket.socket()
        dat = ("irc.chat.twitch.tv",6667)
        client.connect( ("irc.chat.twitch.tv",6667))
        message_user = 'NICK sail338\r\n'
        message = "PASS " + config.OAUTH_TOKEN +"\r\n"
        client.sendto(message.encode('utf-8'),dat)
        client.sendto(message_user.encode('utf-8'),dat)
        client.sendto('JOIN #sail338 \r\n'.encode(),dat)
        while True:
            data = client.recv(1024)
            if data != "b''":
                #Parse data
                data = str(data)
                parsed = data.split(":")
                if len(parsed) >2:
                    print(parsed[2])
    except Exception as e:
        print(str(e))

connectToTwitch()

