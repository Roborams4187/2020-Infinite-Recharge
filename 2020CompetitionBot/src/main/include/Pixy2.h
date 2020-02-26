#pragma once

#include <frc/I2C.h>

//
namespace rr {

class Pixy2{

  public:

    frc::I2C::Port i2C;
    int            iD;

    // constructor
    Pixy2(frc::I2C::Port i2CPort, int i2CDeviceAddress):i2C(i2CPort),iD(i2CDeviceAddress){}
    // These allow class argument values to be used below ^^^^^^      ^^^^^^

    // create camera object for this class object
    frc::I2C cam{i2C, iD};

    uint8_t getColor(){
      
          //int     answer = 0;
          uint8_t command[6] = {174, 193, 32, 2, 1, 1};
          uint8_t response[20];
          uint8_t* commandPtr = &command[0];
          uint8_t* responsePtr = &response[0];

          cam.Transaction(commandPtr,6,responsePtr,20);
          //answer = unsigned(responsePtr[6]);
          
          //return answer;
          return response[6];
        }
  
}; // end Pixy2 class

} // rr namespace