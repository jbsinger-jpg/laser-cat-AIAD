# Import necessary libraries
import serial
from pynput import keyboard


# Connect to the Arduino on /dev/ttyUSB0 with baud rate of 9600
ser = serial.Serial('/dev/ttyUSB0', 9600)


# Define a set of valid keys
valid_keys = set(['a', 'w', 's', 'd'])


# Define the motor numbers for vertical and horizontal motor
HORZ_MOTOR = 0
VERT_MOTOR = 1




# Define function to move the motor forward
def move_forward(motor_number):
   # Construct the command to send to the Arduino
   command = 'm' + str(motor_number) + 'fz'
   command_bytes = command.encode()


   # Send the command to the Arduino
   ser.write(command_bytes)




# Define function to move the motor backward
def move_backward(motor_number):
   # Construct the command to send to the Arduino
   command = 'm' + str(motor_number) + 'bz'
   command_bytes = command.encode()
   print(command_bytes)


   # Send the command to the Arduino
   ser.write(command_bytes)




# Define a callback function for key presses
def on_press(key):
   try:
       # Check if the pressed key is valid
       if key.char == 'a':
           # Move the horizontal motor backward
           move_backward(HORZ_MOTOR)
       elif key.char == 'd':
           # Move the horizontal motor forward
           move_forward(HORZ_MOTOR)
       elif key.char == 's':
           # Move the vertical motor backward
           move_backward(VERT_MOTOR)
       elif key.char == 'w':
           # Move the vertical motor forward
           move_forward(VERT_MOTOR)
   except AttributeError:
       # Ignore special keys (e.g. shift, ctrl, etc.)
       pass




# Define a callback function for key releases


# Start listening for key presses and releases
with keyboard.Listener(on_press=on_press) as listener:
   listener.join()


# Disconnect from the Arduino
ser.close()
