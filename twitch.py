import config
import requests
import socket
import re

def grabOauth():
    a = requests.get("https://id.twitch.tv/oauth2/authorize?client_id=" + config.CLIENT_ID +"&redirect_uri=http://localhost&response_type=token%20id_token &scope=openid + chat_login+channel_editor")
    print(a)


def connectToTwitch():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("irc.chat.twitch.tv",6667))
    client.send("< PASS" + config.OAUTH_TOKEN)
    client.send("< NICK Sail338")

connectToTwitch()

