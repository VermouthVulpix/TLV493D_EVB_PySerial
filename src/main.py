'''
What commands to send to tlv493d evb (xmc100 microller) is defined in .ino file.
Send 'r' to read, and send 'u' to update.
As receving 'r' from com port, xmc100 will return string in the format of bx;by;bz;temperature.
Thus, the last step will split the string for further using.
'''

import hall
import serial

def main():
    hall_port = 'COM3'
    hall_ser = hall.connect_hall(hall_port)
    print(hall.read_hall(hall_ser))
    hall_ser.close()

if __name__ == "__main__":
    main()