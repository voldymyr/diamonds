#!/usr/bin/python

# Python script for downloading and installing SDl1.2 Development ibrary on Linux
# @author Aliks

import os

os.system("date")
print "\n********** Preparing to install SDL1.2 Development Library **********\n"
print "\t BE READY TO ENTER YOUR PASSWORD\n"

os.system("sudo apt-get install -y libsdl1.2-dev")
os.system("sudo apt-get install -y libsdl-image1.2-dev")
os.system("sudo apt-get install -y libsdl-mixer1.2-dev")
os.system("sudo apt-get install -y libsdl-ttf2.0-dev")

print "\n\t\t********** DONE **********\n"