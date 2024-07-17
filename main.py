'''
What commands to send to tlv493d evb (xmc100 microller) is defined in .ino file.
Send 'r' to read, and send 'u' to update.
As receving 'r' from com port, xmc100 will return string in the format of bx;by;bz;temperature.
Thus, the last step will split the string for further using.
'''

import serial
ser = serial.Serial(
        port = 'COM3', #Type in the com port
        baudrate = 9600
    )

def main():
    while True:
        
        ser.write('u'.encode())
        ser.write('r'.encode())
        data = ser.readline()
        data = data.decode().splitlines()[0]
        parse_data = data.split(";")
        print(parse_data)

if __name__ == "__main__":
    main()