/*
############################################################
#   ClassTemplate_FromCaleb.h                              #
#   This file contains useful information in how to deal   #
#   with syntax in C++ and even C.                         #
#                                                          #
#   For more help, contact Caleb at calebpfirst@gmail.com  #
############################################################
*/

/* This is called a "Pre-processor Macro", I will often just call it "Pound-Define".
   Essentially, these aren't executed with code, they are defined and processed as you write them.
*/
#define CALEBS_CODE 1 // COMMENT THIS LINE OUT TO COMMENT THIS ENTIRE FILE OUT!!!!!
// #ifdef is an 'if' statement that is checking if whatever after it is defined or not.
#ifdef CALEBS_CODE

/* This is where you include the stuff you want to use */
#include <iostream>

/* Think of namespaces as a containing folder. */
namespace CALEB
{
    /* structs are like classes that aren't going to have functions. */
    struct Tire
    {
        /* MARTIN -- This is a default constructor */
        Tire()
        {
            PSI = 0;
            Size = 0;
        }
        /* structs can also use constructors ( a lot of people don't know that ) */
        Tire(int psi, int size)
        {
            PSI = psi;
            Size = size;
        }
        /* this is a constructor that sets a variable equal to another variable of 
        the same type.. */
        Tire(const Tire &tire)
        {
            PSI = tire.PSI;
            Size = tire.Size;
        }
        int PSI;
        int Size;
    };
    struct Engine
    {
        /* you can also initialize your variables with a constructor like this...this is the
           same as the constructor in tires. */
        Engine(int horsepower, int torque): Horsepower(horsepower), Torque(torque) {}
        int Horsepower;
        int Torque;
    };
    /* >An enum is much like using constant int values but as a 'type' 
       sort of like with classes and structs.
       >NOTE: enum values will automatically count from 0, but you can 
       define a value to count from.
    */
    enum GEARS
    {
        NEUTRAL = 0,
        FIRST,
        SECOND,
        THIRD,
        FOURTH,
        FIFTH,
        SIXTH
    };
    class Transmission
    {
        // Everything that is public can be seen from code that defines a type of 'vehicle'
        public:
        Transmission()
        {
            // we don't want to start the car in gear...start in NEUTRAL.
            Gear = NEUTRAL;
        }
        // this is a destructor..
        ~Transmission()
        {
            Gear = NEUTRAL;
        }
        void GearUp()
        {
            // this is how you convert a type to another type, 'static_cast<NewType>(Value)'
            int gear = static_cast<int>(Gear);
            // we can't gear up if we are maxed out...
            if (gear < SIXTH)
            {
                // add '1' to the gear
                gear++;
                // convert back to our enumerated list..
                Gear = static_cast<GEARS>(gear);
            }
        }
        void GearDown()
        {
            // this is how you convert a type to another type, 'static_cast<NewType>(Value)'
            int gear = static_cast<int>(Gear);
            // we can't gear down if we are in neutral...
            if (gear > NEUTRAL)
            {
                // subtract '1' from the gear
                gear--;
                // convert back to our enumerated list..
                Gear = static_cast<GEARS>(gear);
            }
        }
        // this is called a 'getter' so we don't have to expose the gear to other code..
        GEARS GetGear()
        {
            return Gear;
        }
        // also provide an option to get an 'int' instead of a type that we defined above (GEARS).
        int GetIntGear()
        {
            return static_cast<int>(GetGear());
        }
        // if we label something as 'private', we are saying that only this class can change or 
        // read Gear without a 'getter' or 'setter' as mentioned above.
        private:
        GEARS Gear;
    };
    class Vehicle
    {
        public:
        Vehicle(int numOfTires)
        {
            tireCount = numOfTires;
            speed = 0;
            isRunning = false;
            // initialize the tires like an array of tires...
            // creating this array makes all of the values use the default constructor mentioned
            // in the definition of 'Tire' above.
            tires = new Tire*[numOfTires];
            // we want to intialize each tire with this value...
            Tire newTire(35, 18);
            for (int i = 0; i < tireCount; i++)
            {
                tires[i] = new Tire(newTire);
            }
            transmission = new Transmission();
        }
        // classes that we want to inherit from should have a 'virtual' destructor
        virtual ~Vehicle()
        {
            // here is where we have to kill all of our pointers to free
            // up memory...
            delete transmission;
            // since we have an array of pointers, we have to delete each one
            // before we delete the array.
            for (int i = 0; i < tireCount; i++)
            {
                delete tires[i];
            }
            // when deleting arrays, you have to use '[]', so like this...
            delete [] tires;
        }
        void Start()
        {
            isRunning = true;
        }
        void ShutOff()
        {
            isRunning = false;
            ChangeSpeed(0);
        }
        void ChangeSpeed(int speedMPH)
        {
            if (speed > speedMPH)
            {
                // slowing down...
                transmission->GearDown();
                // subtract 15
                engine.Horsepower -= 15;
                engine.Torque -= 10;
            }
            else if (speed < speedMPH)
            {
                // speeding up...
                transmission->GearUp();
                // add 15
                engine.Horsepower += 15;
                engine.Torque += 10;
            }
            speed = speedMPH;
            if (speed == 0)
            {
                // we need to get down to neutral..
                while(transmission->GetIntGear() > 0)
                {
                    transmission->GearDown();
                }
                engine.Horsepower = 0;
                engine.Torque = 0;
            }
        }
        private:
        // We are defining C++ class object as pointers..
        Transmission *transmission;
        // This is defining an array of pointers, it will look kind of funny as a double pointer
        Tire         **tires;
        // we can just use the struct types the C way..
        Engine engine = { 0, 0 };
        // basic variables
        int speed;
        int tireCount;
        bool isRunning;
    };
    // This is how inheritance works...the car is a type of vehicle...
    class car : Vehicle
    {
        public:
        // the car has 4 tires and that doesn't change...
        const int TIRE_COUNT = 4;
        car():Vehicle(TIRE_COUNT)
        {

        }
        ~car(){}
        // these are function prototypes..it is promising to the compiler that we defined the
        // function somewhere else. In this case, these functions are defined in the
        // inherited base class.
        void Start();
        void ShutOff();
        void ChangeSpeed(int);
    };
    // This is a function that shows how everything will work...
    int Main()
    {
        car *honda_civic = new car();
        honda_civic->Start();
        for (int i = 0; i < 10; i++)
        {
            honda_civic->ChangeSpeed(10 * i);
        }
        honda_civic->ShutOff();
        delete honda_civic;

    }
};


#endif