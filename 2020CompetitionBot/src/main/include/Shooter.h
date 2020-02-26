#pragma once

// Pretzel & Eatin'

// Needs a class specifically defining our shooter
// that accepts arguments for the 2 SparkMAX's CAN bus
// device IDs and the motor type, so they can be declared
// within the class.
//
// There needs to be a 'Shoot' function that takes
// into account all situations, then deciding how to
// shoot using the targetting information.  This function
// should assume that the operator has indicated the
// desire to shoot by selecting the correct control on
// the stick/controller, which is why the function has
// been called.
//
// There needs to be a 'Position' function which will 
// set the shooter to intake, low-goal/fill-hopper,
// high-goal-from-line, or high-goal-from-safe-zone.
// It should be called when the operator has indicated
// a non-intake position by selecting the appropriate
// control on the controller.
// It should also be called by the 'intake' function of
// this class to move shooter to the intake position for
// intaking fuel cells from the floor.
//
// There needs to be an 'intake' function to set up the
// shooter for intaking fuel cells from the floor.  This
// function needs to have some sort of way of makeing 
// sure more that 5 fuel cells are not loaded on the bot.

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