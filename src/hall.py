'''
What commands to send to tlv493d evb (xmc100 microller) is defined in .ino file.
Send 'r' to read, and send 'u' to update.
As receving 'r' from com port, xmc100 will return string in the format of bx;by;bz;temperature.
Thus, the last step will split the string for further using.
'''

import serial

def connect_hall(port_name):
    return serial.Serial(port = port_name, baudrate = 9600)

def read_hall(hall_ser):
    hall_ser.write('u'.encode())
    hall_ser.write('r'.encode())
    data = hall_ser.readline()
    data = data.decode().splitlines()[0]
    parse_data = data.split(";")
    return parse_data