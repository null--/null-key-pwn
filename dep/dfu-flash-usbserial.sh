#-----------------------------------------------------------#
# 1. Reset ATMEGA38
# 2. Reset ATMEGA802
#-----------------------------------------------------------#

#!/bin/bash

sudo dfu-programmer at90usb82 erase
sudo dfu-programmer at90usb82 flash --debug 1 Arduino-usbserial-uno.hex
sudo dfu-programmer at90usb82 reset

