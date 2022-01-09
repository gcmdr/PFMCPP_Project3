 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    float distanceTraveled = 0;

    struct Foot
    {
        int totalSteps = 0;
        std::string footSide;
        float sizeOfStep;

        int stepSize();
        void stepForward();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(float howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward()
{
    totalSteps++;
}

int Person::Foot::stepSize()
{
    return sizeOfStep;
}

void Person::run(float howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    
    distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * (howFast/4);
    /*
        Not sure what to do with howFast here. I'm multiplying by the combined step size, 
        thinking step size was determined at a rate of 4mph, if you run faster your
        step size increases. I don't think step size linearly increases with speed, 
        but I know my step size is bigger when I run than when I walk... so that's my attempt.
    */
};

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


struct StereoSystem
{
    int numSpeakers = 2;
    float wattsOfPower = 60.0f;
    int numAnalogInputs = 2;
    int numDigitalInputs = 2;
    int numEQBands = 5;
    bool subOn = false;
    const int maxBassLevel = 10;
    int bassLevel = 0;

    struct Tape
    {
        std::string tapeName = "mix";
        std::string type = "chrome bias";
        float quality = 1.0f;
        int minPerSide = 30;
        int positionInMinutes = 0;

        void rewind(bool beginning, int lengthOfTime);
        void fastForward(bool end, int lengthOfTime);
        std::string getTitle();
    };

    void playMusic(std::string album, int track);
    void boostBass(int bassBoostAmount = 5);
    Tape dubTapes(Tape tape1);
};

void StereoSystem::playMusic(std::string album, int track)
{
    std::cout << "Now Playing: " << album << ", Track " << track;
}

void StereoSystem::boostBass(int bassBoostAmount)
{
    if(subOn) bassBoostAmount += 5;
    if(bassLevel + bassBoostAmount > maxBassLevel) bassLevel = maxBassLevel;
    else bassLevel += bassBoostAmount;
}

StereoSystem::Tape StereoSystem::dubTapes(Tape tape1)
{
    tape1.quality *= 0.9f;
    tape1.tapeName += " dub";
}

void StereoSystem::Tape::rewind(bool beginning, int lengthOfTime)
{
    if(beginning) positionInMinutes = 0;
    else 
        if(positionInMinutes - lengthOfTime <= 0) positionInMinutes = 0;
        else positionInMinutes -= lengthOfTime;
}
        
void StereoSystem::Tape::fastForward(bool end, int lengthOfTime)
{
    if(end) positionInMinutes = minPerSide;
    else 
        if (positionInMinutes + lengthOfTime >= minPerSide) positionInMinutes = minPerSide;
        else positionInMinutes += lengthOfTime;
}

std::string StereoSystem::Tape::getTitle()
{
 return tapeName;
}

struct Military
{
    std::string branchOfMilitary = "Navy";
    int numBases = 127;
    int numSoldiers = 5000;
    float budget = 10000000.0f;
    int numReserveSoldiers = 1000;

    struct Soldier
    {
        float height = 60.2f;
        float weight = 185.0f;
        std::string mainSkill = "munitions";
        int yearsExperience = 5;
        std::string rank = "corporal";

        bool readyForCombat(float requiredWeight, int requiredExperience);
        void constructShelter(int numSoldiers, std::string weatherConditions = "cloudy");
        void skillsAndRank(std::string mainSkill, std::string rank);
    };

    float spendMoney (std::string Contract, float budget=10000000.57f);
    void defend (int numEnemySoldiers);
    bool invade (int numEnemySoldiers, int numEnemyBases);
};

float Military::spendMoney (std::string Contract, float expense)
{
    if(expense > budget) {
        std::cout << "Not enough money to fulfill contract.";
        return budget;
    }
    else
    {
        std::cout << "Contract " << Contract << " approved.";
        return budget - expense;
    }
}
    
void Military::defend (int numEnemySoldiers)
{
    if(numEnemySoldiers > numSoldiers)
    {
        int callUpSoldiers = (numEnemySoldiers - numSoldiers) + 100;
        if (callUpSoldiers > numReserveSoldiers) callUpSoldiers = numReserveSoldiers;
        else numReserveSoldiers -= callUpSoldiers; 
        numSoldiers += callUpSoldiers;
    }
    return;
}
bool Military::invade (int numEnemySoldiers, int numEnemyBases)
{
    if(numEnemyBases > numBases || numEnemySoldiers > numSoldiers) return false;
    else return true;
}

bool Military::Soldier::readyForCombat(float requiredWeight, int requiredExperience)
{
    if (weight > requiredWeight || yearsExperience < requiredExperience) return false;
    else return true;
}

void Military::Soldier::constructShelter(int numSoldiers, std::string weatherConditions)
{
    std::cout << "Construct shelter for: " << numSoldiers << " soldiers. Weather conditions: " << weatherConditions;
}

void Military::Soldier::skillsAndRank(std::string mainSkill, std::string rank)
{
    std::cout << "Rank: " << rank; 
    std::cout << "Skill: " << mainSkill;
}

struct House
{
    int numBedrooms = 2;
    std::string typeOfAC = "central";
    std::string typeOfRoof = "tile";
    int currentTemp = 75;
    bool heatingOn = false;
    float totalSewageProcessed = 0.0f;

    void heatInterior(int thermostatSetting = 75);
    void houseCharacteristics();
    void processSewage(float gallonsOfSewage = 14.5, bool septicTankFunctional = true);
};

void House::heatInterior(int thermostatSetting)
{
    if(thermostatSetting < currentTemp) heatingOn = true;
    else heatingOn = false;
    return;
}

void House::houseCharacteristics()
{
    std::cout << "Roof type: " << typeOfRoof << ", AC Type: " << typeOfAC;
    return;
}

void House::processSewage(float gallonsOfSewage, bool septicTankFunctional)
{
    if(septicTankFunctional) totalSewageProcessed += gallonsOfSewage;
    return;
}
    

struct Plane
{
    int numSeats = 240;
    std::string typeOfEngine = "turboprop";
    int numWindows = 100;
    double cargoCapacity = 5000;
    float fuelCapacity = 300;

    void fly(float engineThrust, bool clearRunway = true);
    void transportCustomers(int totalPassengers, int totalCrew);
    void transportCargo(int numParcels, float totalWeight);
};

struct Filter
{
    int filterSlope = -6;
    std::string filterType = "low pass";
    std::string filterDesign = "chebyshev";
    double rolloff = 75;
    float q = 1.52f;

    void highPass(float lowRolloff = 70.0f, int slope = -6);
    void lowPass(float highRolloff = 15000.0f, int slope = 12);
    void bandPass(float centerFrequency = 1000.f, float q = 1.25f, float gain = 6.5f);
};

struct Effects
{
    float satLevel = 50.0f;
    int delayRepeats = 7;
    float reverbDecay = 3.7f;
    int bitsCrushed = 7;
    float wet = 50.0f;

    void distort(float gain);
    void bitCrush(float sampleRate, int bits = 5);
    void modulate(float depth, int voices);
};

struct Oscillator
{
    float frequency = 500.0f;
    float amplitude = 0.75f;
    std::string waveShape = "sine";
    std::string typeOfOscillator = "digitl";
    int numOscillators = 3;

    float createPitch(int midiNote);
    void changeTone(float filterRolloff);
    void controlParam(std::string controlSource, std::string controlDestination, float amount = 0.75f);
};

struct Envelope
{
    float attack = 1.2f;
    float sustain = 5.0f;
    float decay = .4f;
    float release = 2.3f;
    float hold = 4.5f;

    void adjustAttack(float attack);
    void adjustSustain(float sustain);
    void adjustRelease(float release);
};

struct IO
{
    int numInputs = 2;
    int numOutputs = 2;
    std::string typeOfMidiConnection = "USB";
    std::string typeOfCV = "gate";
    std::string typeOfUSB = "type A";

    bool getStatus(float startupComplete = 1.0f);
    void output(float sampleRate, int bufferSize);
    int processMidi(int transposeAmount = 12);
};

struct Synth
{
    Filter filter1;
    Effects effect1;
    Oscillator oscillator1;
    Envelope envelope1;
    IO io1;

    void makeSound(Oscillator osc2, IO io2);
    void pitchBend(Oscillator osc3, int numIntervals);
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
