# FreakySriky
Won most fun hack at HackNY Spring 2018
To see a demo of the project visit: https://devpost.com/software/twitch-plays-horror-house

# What it does

A Twitch streamer showcases his journey through a haunted room. Viewers of the stream are the ones who decide how, when, and where to scare the streamer. The Twitch streamer navigates the room and the viewers orchestrate the scares!

# How We Built It

The project was built in python for the backend, and the microcontroller code was written in C++. We used the Twitch API to get responses from our stream, and sent the responses to our IBM-Watson workspace to get their intent. The intents were then polled through and an action was decided. The hardware itself was built mostly out of cardboard and servo motors, with the haunted house being streamed through a webcam.

# Challenges We Ran Into

The biggest challenge was integrating the components into the system. We had numerous different components such as Python scripts leveraging the Twitch API. These components would interact with Arduino components as well as Amazon Alexa. Bringing all these units to work together was just as challenging as it was rewarding in the end.

The second biggest challenge we’ve encountered is simulating a haunted house. Obviously, we can’t make a live-scale version. We decided to scale down and utilize a cardboard as our haunted room. The scare tactics, the design of the room, and the aesthetics were all very important to us; thus, it was our second biggest challenge.
