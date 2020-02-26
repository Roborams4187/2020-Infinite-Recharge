#pragma once

// Garrett

// Needs a class specifically defining our mecanum drive
// that accepts arguments for the 4 SparkMAX's CAN bus
// device IDs and the motor type, so they can be declared
// within the class.
//
// There needs to be a 'Set' function accepting a reference
// to the driver controller object, which it will use to 
// read the driver's inputs to control the code operating
// a mecanum drive system.  This function should calculate
// the proper values to set the drive motors to, in order
// to move the bot in the direction indicated by the 
// joystick inputs of the driver.  These values should
// be tuned using encoder inputs from the motors so that
// when driving straight forward, straight side-to-side,
// and turning, all for motors are in sync.  When 
// strafing at any other angle, the LF sould be synced to
// the RR and the RF synced to the LR.
//
// This 'Set' function also needs to accept 4 decimal values
// less than 1, to be used to manually tune each drive motor
// for any other inconsistencies still causing drift. 
//
// There needs to be a 'Stop' function that simply brings the
// bot to a stand-still when called.

/*
#include <>

namespace rr {


class BlahBlahBlah{

  public:

    type            var/object;
    type            var/object;
    type            var/object;

    // constructor
    BlahBlahBlah(type argument1, type argument2) : var1(argument1), var2(argument2){}
    // These allow class argument values to be used below ^^^^^^      ^^^^^^

    // create any objects for this class object
    type object{var1, var2};


    // make any functions needed

    type function1(type arg1, type &arg2) {

      //function var/object declarations;
      type            var/object;
      type            var/object;

      //function code;

      // be sure to return an answer if the function has a type other than 'void'
      //return someVarOrObjectOfThisFunctionsType;
    }// end function1
  
}; // end BlahBlahBlah class

} // end rr namespace
*/