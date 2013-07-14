null-key-pwn
============

An arduino-based virtual keyboard for physical penetration test. (like teensy usb @ SET project)

Debian usage:
       Connect arduino to your PC
       
       # cd dep/

       Put usb/serial micro (not atmega micro) at reset mode.
       
       Reprogram arduino as an usb programmer:
              # ./dfu-flash-usbserial.sh

       Put atmega micro at reset mode.
       
       compile and upload null-key-pwn.ino

       Put usb/serial micro at reset mode.
       
       Reprogram arduino as an usb keyboard:
       # ./