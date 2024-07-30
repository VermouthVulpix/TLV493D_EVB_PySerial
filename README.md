#### Read, Update TLV493D EVB from COM with designed command 
For setting up the arduino IDE, please refer to https://github.com/Infineon/TLE493D-3DMagnetic-Sensor
- Hardware\
  TLE493D-P2B6 MS2GO
- Requirement
```
pip install pyserial
```
- Description\
  The TLE493D-P2B6 MS2GO features XMC1100 (ARM® Cortex™-M0 based), which is the destination while setting up in the arduino IDE.
  With the well-defined library, XMC1100 can interact with hall sensor TLE493D via I2C protocol.
  In the original example, XMC1100 will send out bx, by, bz continuously while connected.
  However, I hope it can send out data only when I give it command.
  
- TLV493D.ino\
  This file defines the command for interaction with TLV493D, including,
  - 'r' for reading, output will be bx;by;bz;temperature
  - 'u' for updating, without output
    
 - main.py\
   When the EVB is connected via USB, main program can read bx,by,bz after setting up the correct "COM"

 - source:
   https://github.com/Infineon/arduino-xensiv-3d-magnetic-sensor-tlx493d/tree/master  (latest library)
   https://github.com/Infineon/TLE493D-3DMagnetic-Sensor
