#!/bin/bash

sudo dfu-programmer at90usb82 erase
sudo dfu-programmer at90usb82 flash --debug 1 Arduino-keyboard-0.3.hex
sudo dfu-programmer at90usb82 reset

