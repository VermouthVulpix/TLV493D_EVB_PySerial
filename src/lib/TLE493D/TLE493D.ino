/** Project CPP includes. */
#include "TLx493D_inc.hpp"


using namespace ifx::tlx493d;


/* Definition of the power pin and sensor objects for Kit2Go XMC1100 boards. */
const uint8_t POWER_PIN = 15; // XMC1100 : LED2

// TLx493D_A1B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);

// TLx493D_A2B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);
TLx493D_P2B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);
// TLx493D_W2B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);


/** Definition of the power pin and sensor objects for S2Go with XMC4700 Relax Lite board. */
// const uint8_t POWER_PIN = 8; // XMC : P1.10

// TLx493D_A1B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);

// TLx493D_A2BW dut(Wire, TLx493D_IIC_ADDR_A0_e);
// TLx493D_W2B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);
// TLx493D_W2BW dut(Wire, TLx493D_IIC_ADDR_A0_e);

// TLx493D_P3B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);
// TLx493D_P3B6 dut(Wire, TLx493D_IIC_ADDR_A1_e);


/** Definition of the power pin and sensor objects for Arduino Uno boards */
/** Care must be taken to level shift down to 3.3V as the sensor boards expect only 3.3V ! */
/** Therefore disabled for here. */
// const uint8_t POWER_PIN = 7;

// TLx493D_W2B6 dut(Wire, TLx493D_IIC_ADDR_A0_e);
// TLx493D_W2BW dut(Wire, TLx493D_IIC_ADDR_A0_e);


/** Definition of a counter variable. */
uint8_t count = 0;
int incoming = 0;
String bx, by, bz, temp, output;
double t, x, y, z;


void setup() {
    Serial.begin(115200);
    delay(2000);

    /** Definition of the power pin to power up the sensor. */
    /** Set delay after power-on to 50 for A1B6 Kit2Go sensor. */
    dut.setPowerPin(POWER_PIN, OUTPUT, INPUT, HIGH, LOW, 0, 250000);
    dut.begin();

}


/** In the loop we continuously reading the temperature value as well as the
 *  magnetic values in X, Y, Z-direction of the sensor and printing them to
 *  the serial monitor
 */
void loop() {
    
    if (Serial.available()>0){
      incoming = Serial.read();
      if (incoming == 117){

        output = "";
      
        dut.setSensitivity(TLx493D_FULL_RANGE_e);
        dut.getMagneticFieldAndTemperature(&x, &y, &z, &t);

        output.concat(String(x));
        output.concat(";");
        output.concat(String(y));
        output.concat(";");
        output.concat(String(z));
        output.concat(";");
        output.concat(String(t));

        Serial.println(output);
/*
        bx = String(x);
        Serial.print(bx);
        Serial.print(";");
        by = String(y);
        Serial.print(by);
        Serial.print(";");
        bz = String(z);
        Serial.print(bz);
        Serial.print(";");
        temp = String(t);
        Serial.println(temp);
*/
        Serial.flush();
        

      }
      else if (incoming == 112){
        dut.reset(true);
      }

    }
}