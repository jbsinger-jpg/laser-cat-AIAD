# laser-cat-AIAD
This was apart of a three week project that I did at WSU. All of the coding was done on my end while others built the physical device that takes input from this code to move a laser via bipolar stepper motors.

To configure the environment it is important that the following python packages are installed:
pyserial
pynput

We are also going to want to make sure that you are running your python environment in an OS
that you are familiar with.

This might sound obvious, but with pyserial I have found that for both Windows and Linux you need to
provide the logged in user permissions to use the serial port.

I found this easiest to do within Linux.
1. Open a terminal session
2. Run the command: 
ls /dev/ttyUSB* 
to view all of the avaliable USB ports
3. Use the port that is listed from this command in place of the ser variable within the python script.

If you don't see anything from the ls command then that means the serial connection you plugged in is not being registered and most likely need to either make sure the cable is fully plugged in or get a new serial cable.
