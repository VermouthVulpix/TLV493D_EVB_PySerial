/**
* For basic setup just create a Tle493d() object. If you want to use the wake up mode please use Tle493d_w2b6(). Also
* the setUpdateRate() method is slightly different for different variants
*/


#include <Tle493d.h>

Tle493d Tle493dMagnetic3DSensor = Tle493d();
int incoming = 0;
String bx, by, bz, temp;


void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  //If using the MS2Go-Kit: Enable following lines to switch on the sensor
  // ***
  pinMode(LED2, OUTPUT);
  digitalWrite(LED2, HIGH);
  delay(500);
  // ***
  
  Tle493dMagnetic3DSensor.begin();
  Tle493dMagnetic3DSensor.enableTemp();
}

//input -> int : incoming (r for reading, u for updating)
//output -> string : "bx;by;bz;temperature"
void loop() {
  
  if (Serial.available()>0){
    
    incoming = Serial.read();

    if (incoming == 117){
      //117 is byte encoding of 'u', referring to "updating" in this program
      Tle493dMagnetic3DSensor.updateData();
    }
    else if (incoming == 114){
      //114 is byte encoding of 'r', referring to "reading" in this program
      bx = String(Tle493dMagnetic3DSensor.getX(),2);
      Serial.print(bx);
      Serial.print(";");
      by = String(Tle493dMagnetic3DSensor.getY(),2);
      Serial.print(by);
      Serial.print(";");
      bz = String(Tle493dMagnetic3DSensor.getZ(),2);
      Serial.print(bz);
      Serial.print(";");
      temp = String(Tle493dMagnetic3DSensor.getTemp(),2);
      Serial.println(temp);

    }

  }

}


