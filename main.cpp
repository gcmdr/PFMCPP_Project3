/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


/*
Thing 1) Stereo system
5 properties:
    1) number of speakers (int)
    2) watts of power (float)
    3) number of analog inputs (int)
    4) number of digital inputs (int)
    5) number of eq bands to adjust (int) 
3 things it can do:
    1) play music
    2) boost bass
    3) dub tapes
 */

struct stereoSystem
{
    // number of speakers
    int numSpeakers = 2;
    // watts of power
    float wattsOfPower = 60.0f;
    // number of analog inputs
    int numAnalogInputs = 2;
    // number of digital inputs
    int numDigitalInputs = 2;
    // number of eq bands to adjust
    int numEQBands = 5;

    struct Tape
    {
        std::string tapeType = "chrome bias";
        int minPerSide = 30;
        float percentPlayed = 0.5f;
        std::string color = "black";
        bool plasticCase = false; // if not plastic, paper slipcase

        // rewind
        void rewind(float lengthOfTime, bool untilBeginning);
        // ff
        void fastForward(float lengthOfTime, bool untilEnd);
        // stop
        std::string getTitle();
    };

    // play music
    void playMusic(std::string album, int track);
    // boost bass
    void boostBass(int bassBoostAmount, bool subOn);
    // dub tapes
    Tape dubTapes(Tape tape1);
};

/*
Thing 2) military
5 properties:
    1) branch (std::string)
    2) number of bases (int)
    3) number of warships (int)
    4) number of planes (int)
    5) type of weapon (std::string)
3 things it can do:
    1) Spend Money
    2) Defend territory
    3) Invade 
 */

struct Military
{
    // branch (std::string)
    std::string branchOfMilitary = "Navy";
    // number of bases (int)
    int numBases = 127;
    // number of warships (int)
    int numWarships = 27;
    // number of planes (int)
    int numPlanes = 542;
    // type of weapon (std::string)
    std::string typeOfWeapon = "gun";

    struct Soldier
    {
        // soldier height
        float height = 60.2f;
        // soldier weight
        float weight = 185.0f;
        // main skill
        std::string mainSkill = "munitions";
        // years experience
        int yearsExperience = 5;
        // rank
        std::string rank = "corporal";

        // strike
        void strike(std::string weapon);
        // construct shelter
        void constructShelter(int numSoldiers, std::string weatherConditions = "cloudy");
        // ready for combat
        bool readyForCombat(bool trainingComplete);
        
    };

    // Spend Money
    float spendMoney (std::string Contract, float budget=10000000.57f);
    // Defend territory
    void defend (float enemyLatitude = 53.4f, float enemyLongitude = 38.2f);
    // Invade 
    void invade (Soldier soldier2, int soldiersAvailable = 100, int weaponsAvailable = 300);
};

/*
Thing 3) house
5 properties:
    1) number of bedrooms (int) 
    2) type of a/c  (std::string)
    3) number of bathrooms (int)
    4) type of roof (std::string)
    5) number of carports (int)
3 things it can do:
    1) provide shelter
    2) warm interior
    3) process sewage
 */

struct House
{
    // number of bedrooms
    int numBedrooms = 2;
    // type of a/c
    std::string typeOfAC = "central";
    // number of bathrooms
    int numBathrooms = 1;
    // type of roof
    std::string typeOfRoof = "tile";
    // number of carports
    int numCarports = 2;

    // provide shelter
    bool provideShelter(bool roofIntact, bool foundationSolid);
    // warm interior
    void heatInterior(int thermostatSetting = 75);
    // process sewage
    void processSewage(float gallonsOfSewage = 14.5, bool septicTankFunctional = true);
};

/*
Thing 4) plane
5 properties:
    1) number of seats (int)
    2) type of engine (std::string)
    3) number of windows (int)
    4) cargo capacity (double)
    5) fuel capacity (float)
3 things it can do:
    1) fly
    2) transport customers
    3) transport cargo
 */

struct Plane
{
    // number of seats
    int numSeats = 240;
    // type of engine
    std::string typeOfEngine = "turboprop";
    // number of windows
    int numWindows = 100;
    // cargo capacity
    double cargoCapacity = 5000;
    // fuel capacity
    float fuelCapacity = 300;

    // fly
    void fly(float engineThrust, bool clearRunway = true);
    // transport customers
    void transportCustomers(int totalPassengers, int totalCrew);
    // transport cargo
    void transportCargo(int numParcels, float totalWeight);
};

/*
Thing 5) Filter
5 properties:
    1) slope of filter (int)
    2) type of filter (std::string)
    3) filter design (std::string)
    4) rolloff (double)
    5) Q (float)
3 things it can do:
    1) high pass
    2) low pass
    3) band pass
 */

struct Filter
{
    // slope of filter
    int filterSlope = -6;
    // type of filter
    std::string filterType = "low pass";
    // filter design
    std::string filterDesign = "chebyshev";
    // rolloff
    double rolloff = 75;
    // Q
    float q = 1.52f;

    // high pass
    void highPass(float lowRolloff = 70.0f, int slope = 6);
    // low pass
    void lowPass(float highRolloff = 15000.0f, int slope = 12);
    // band pass
    void bandPass(float centerFrequency = 1000.f, float q = 1.25f, float gain = 6.5f);
};

/*
Thing 6) Effects
5 properties:
    1) saturation level (float)
    2) delay repeats (int)
    3) reverb decay (float)
    4) bits crushed (int)
    5) wet/dry (float)
3 things it can do:
    1) distort
    2) bit crush
    3) modulate
*/

struct Effects
{
    // saturation level
    float satLevel = 50.0f;
    // delay repeats
    int delayRepeats = 7;
    // reverb decay
    float reverbDecay = 3.7f;
    // bits crushed
    int bitsCrushed = 7;
    // wet/dry
    float wet = 50.0f;

    // distort
    void distort(float gain);
    // bit crush
    void bitCrush(float sampleRate, int bits = 5);
    // modulate
    void modulate(float depth, int voices);
};

/*
Thing 7) Oscillators
5 properties:
    1) Frequency (float)
    2) Amplitude (float)
    3) Waveshape (std::string)
    4) Type of oscillator (str::string)
    5) Number of oscillators (int)
3 things it can do:
    1) Create pitches
    2) Change tone of pitches
    3) Control other parameters
*/

struct Oscillator
{
    // Frequency 
    float frequency = 500.0f;
    // Amplitude 
    float amplitude = 0.75f;
    // Waveshape 
    std::string waveShape = "sine";
    // Type of oscillator 
    std::string typeOfOscillator = "digitl";
    // Number of oscillators 
    int numOscillators = 3;

    // Create pitches
    float createPitch(int midiNote);
    // Change tone of pitches
    void changeTone(float filterRolloff);
    // Control other parameters
    void controlParam(std::string controlSource, std::string controlDestination, float amount = 0.75f);
};

/*
Thing 8) Envelope
5 properties:
    1) Attack (float)
    2) Sustain (float)
    3) Decay (float)
    4) Release (float)
    5) Hold (float)
3 things it can do:
    1) Adjust attack time
    2) Adjust sustain level
    3) Adjust release time
 */

struct Envelope
{
    // Attack
    float attack = 1.2f;
    // Sustain 
    float sustain = 5.0f;
    // Decay
    float decay = .4f;
    // Release
    float release = 2.3f;
    // Hold 
    float hold = 4.5f;

    // Adjust attack time
    void adjustAttack(float attack);
    // Adjust sustain level
    void adjustSustain(float sustain);
    // Adjust release time
    void adjustRelease(float release);
};

/*
Thing 9) I/O
5 properties:
    1) number of inputs (int)
    2) number of outputs (int)
    3) type of midi connection (std::string)
    4) type of CV (std::string)
    5) type of USB connection (std::string)
3 things it can do:
    1) accept audio
    2) output audio
    3) process midi
 */

struct IO
{
    // number of inputs (int)
    int numInputs = 2;
    // number of outputs (int)
    int numOutputs = 2;
    // type of midi connection (std::string)
    std::string typeOfMidiConnection = "USB";
    // type of CV (std::string)
    std::string typeOfCV = "gate";
    // type of USB connection (std::string)
    std::string typeOfUSB = "type A";

    // accept audio
    bool getStatus(float startupComplete = 1.0f);
    // output audio
    void output(float sampleRate, int bufferSize);
    // process midi
    int processMidi(int transposeAmount = 12);
};

/*
Thing 10) Synthesizer
5 properties:
    1) Filters
    2) Effects
    3) Oscillators
    4) Envelope
    5) IO
3 things it can do:
    1) Create sound
    2) Pitch bend
    3) Process midi
 */

struct Synth
{
    // Filters
    Filter filter1;
    // Effects
    Effects effect1;
    // Oscillators
    Oscillator oscillator1;
    // Envelope
    Envelope envelope1;
    // IO
    IO io1;

    // Create sound
    void makeSound(Oscillator osc2, IO io2);
    // Pitch bend
    void pitchBend(Oscillator osc3, int numIntervals);
    // Process midi
    void processMidi(IO io3, int midiNoteNumber);
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
