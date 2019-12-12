#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

SoftwareSerial BTSerial(10, 11); //RXD 10, TXD 11


MPU6050 mpu6050(Wire);


void setup() {
  Wire.begin();
  Wire.setClock(400000L);
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  Serial.begin(9600);
  BTSerial.begin(115200);
}

void loop() {
    mpu6050.update();
    float angleY = mpu6050.getAngleY();
    float angleX = mpu6050.getAngleX();
    int y = (int)angleY;
    int x = (int)angleX;
    Serial.print("\tangleY : ");
    Serial.print(y);
    Serial.print("\tangleX : ");
    Serial.println(x);
    
    if(y >= 30) {
      BTSerial.print('F');
    }

    if(y <= -30) {
      BTSerial.print('B');

    }

    if(x >= 30) {
      BTSerial.print('L');
    }

     if(x <= -30) {
      BTSerial.print('R');
    }

    if ((y <= 15 && y >= -15) && (x <= 15 && x >= -15)) {
      BTSerial.print('S');
    }
    
  }
  
