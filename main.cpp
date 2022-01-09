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

        float stepSize();
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

float Person::Foot::stepSize()
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
}

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

    Tape originalTape;
};

void StereoSystem::playMusic(std::string album, int track)
{
    std::cout << "Now Playing: " << album << ", Track " << track; 
}

void StereoSystem::boostBass(int bassBoostAmount)
{
    if(subOn) 
        bassBoostAmount += 5;

    if(bassLevel + bassBoostAmount > maxBassLevel) 
        bassLevel = maxBassLevel;
    else 
        bassLevel += bassBoostAmount;
}

StereoSystem::Tape StereoSystem::dubTapes(Tape tape1)
{
    tape1.quality *= 0.9f;
    tape1.tapeName += " dub";
    return tape1;
}

void StereoSystem::Tape::rewind(bool beginning, int lengthOfTime)
{
    if(beginning) 
        {
        positionInMinutes = 0;
        }
    else 
        {
        if(positionInMinutes - lengthOfTime <= 0) 
            positionInMinutes = 0;
        else 
            positionInMinutes -= lengthOfTime;
        }
}
        
void StereoSystem::Tape::fastForward(bool end, int lengthOfTime)
{
    if(end) 
    {
        positionInMinutes = minPerSide;
    }
    else 
    {
        if (positionInMinutes + lengthOfTime >= minPerSide) 
            positionInMinutes = minPerSide;
        else 
            positionInMinutes += lengthOfTime;
    }
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
        void constructShelter(int numberOfSoldiers, std::string weatherConditions = "cloudy");
        void skillsAndRank(std::string mainSkill, std::string rank);
    };

    float spendMoney (std::string Contract, float budget=10000000.57f);
    void defend (int numEnemySoldiers);
    bool invade (int numEnemySoldiers, int numEnemyBases);

    Soldier soldier1;
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
        
        if (callUpSoldiers > numReserveSoldiers) 
            callUpSoldiers = numReserveSoldiers;
        else 
            numReserveSoldiers -= callUpSoldiers; 

        numSoldiers += callUpSoldiers;
    }
}

bool Military::invade (int numEnemySoldiers, int numEnemyBases)
{
    if(numEnemyBases > numBases || numEnemySoldiers > numSoldiers) 
        return false;
    
    return true;
}

bool Military::Soldier::readyForCombat(float requiredWeight, int requiredExperience)
{
    if (weight > requiredWeight || yearsExperience < requiredExperience) 
        return false;
    
    return true;
}

void Military::Soldier::constructShelter(int numberOfSoldiers, std::string weatherConditions)
{
    std::cout << "Construct shelter for: " << numberOfSoldiers << " soldiers. Weather conditions: " << weatherConditions;
}

void Military::Soldier::skillsAndRank(std::string primarySkill, std::string currentRank)
{
    std::cout << "Rank: " << currentRank; 
    std::cout << "Skill: " << primarySkill;
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
    if(thermostatSetting < currentTemp) 
        heatingOn = true;
    
    heatingOn = false;
}

void House::houseCharacteristics()
{
    std::cout << "Roof type: " << typeOfRoof << ", AC Type: " << typeOfAC;
}

void House::processSewage(float gallonsOfSewage, bool septicTankFunctional)
{
    if(septicTankFunctional) 
        totalSewageProcessed += gallonsOfSewage;
}

struct Plane
{
    int numSeats = 240;
    std::string typeOfEngine = "turboprop";
    double cargoCapacity = 5000;
    double currentWeight = 0;
    float fuelLevel = 5000;
    
    bool transportCargo(double parcelWeight);
    float sellAlcohol(int totalDrinks, float drinkPrice);
    void fly(int flightTime, float engineThrust, bool clearRunway = true);
};

    bool Plane::transportCargo(double parcelWeight)
    {
        if(currentWeight + parcelWeight > cargoCapacity)
        {
            return false;
        }
        
        currentWeight += parcelWeight;
        return true;
        
    }

    float Plane::sellAlcohol(int totalDrinks, float drinkPrice)
    {
        return totalDrinks * drinkPrice;
    }

    void Plane::fly(int flightTime, float engineThrust, bool clearRunway)
    {
        if (clearRunway)
        {
            fuelLevel -= (flightTime * engineThrust);
        }
    }

struct Filter
{
    int filterSlope = -6;
    std::string activeFilterType = "low pass";
    float mainFreq = 75.0f;
    float currentQ = 1.52f;
    float currentGain = 0.0f;
    const float maxGain = 20.0f;
    
    void highPass(float lowRolloff = 70.0f, int slope = -6);
    void lowPass(float highRolloff = 15000.0f, int slope = 12);
    bool isClipping(float changeInGain = 6.5f);
};

void Filter::highPass(float lowRolloff, int slope)
{
    filterSlope = slope;
    activeFilterType = "highPass";
    mainFreq = lowRolloff;
}

void Filter::lowPass(float highRolloff, int slope)
{
    filterSlope = slope;
    activeFilterType = "lowPass";
    mainFreq = highRolloff;
}

bool Filter::isClipping(float changeInGain)
{
    if (currentGain + changeInGain > maxGain) 
        return true;
    
    return false;    
}

struct Effects
{
    float satLevel = 50.0f;
    std::string currentEffect = "delay";
    float reverbDecay = 3.7f;
    int bitsCrushed = 7;
    float wet = 50.0f;

    void distort(float gain = 5.0f);
    void bitCrush(int bits = 5);
    void delay(int delayRepeats = 7);
};

void Effects::distort(float gain)
{
    currentEffect = "distort";
    satLevel = gain * 10.0f;
    wet = 100.0f;
}

void Effects::bitCrush(int bits)
{
    currentEffect = "bitCrush";
    satLevel = 0.0f;
    wet = 75.0f;
    bitsCrushed = bits;
}

void Effects::delay(int delayRepeats)
{
    for(int i = 0; i < delayRepeats; ++i)
    {
        // increase saturation during repeats
        satLevel = i/delayRepeats;
    }
}

struct Oscillator
{
    float frequency = 500.0f;
    float amplitude = 0.75f;
    std::string waveShape = "sine";
    std::string typeOfOscillator = "digital";
    int numOscillators = 3;

    std::string noteName(int midiNote);
    void modWheel(float modAmount = 0.75f);
    void volumePedal(float volumePedalPostion = 0.5f);
};

std::string Oscillator::noteName(int midiNote)
{
    auto val = midiNote % 12;
    switch (val)
    {
        case 0: return "C";
        case 1: return "C#";
        case 2: return "D";
        case 3: return "D#";
        case 4: return "E";
        case 5: return "F";
        case 6: return "F#";
        case 7: return "G";
        case 8: return "G#";
        case 9: return "A";
        case 10: return "A#";
        case 11: return "B";
        default: return "C"; // this got rid of a warning
    }
}

void Oscillator::modWheel(float modAmount)
{
    frequency *= (modAmount * 12);
}

void Oscillator::volumePedal(float volumePedalPosition)
{
    amplitude = volumePedalPosition;
}

struct Envelope
{
    float envAttack = 1.2f;
    float envSustain = 5.0f;
    float envDecay = .4f;
    float envRelease = 2.3f;
    float envHold = 4.5f;

    void adjustAttack(float attack);
    void adjustSustain(float sustain);
    void adjustRelease(float release);
};

void Envelope::adjustAttack(float attack)
{
    envAttack = attack;
    std::cout << "Attack = " << attack;
}

void Envelope::adjustSustain(float sustain)
{
    envSustain = sustain;
    std::cout << "sustain = " << sustain;
}

void Envelope::adjustRelease(float release)
{
    envRelease = release;
    std::cout << "release = " << release;
}

struct IO
{
    int numInputs = 2;
    int numOutputs = 2;
    std::string typeOfMidiConnection = "USB";
    int currentMidiInStream = 50;
    bool firmwareUpToDate = true;

    bool getStatus();
    void inputStatus(int numActiveInputs = 2);
    int processMidi(int transposeAmount = 12);
};

bool IO::getStatus()
{
    if (firmwareUpToDate) 
        return true;
    
    return false;
}

void IO::inputStatus(int numActiveInputs)
{
    if (numActiveInputs == 1) 
        std::cout << "1 active input, mono";
    else if (numActiveInputs == 2) 
        std::cout << "2 active inputs, stereo";
     
    std::cout << "Inputs inactive";
}

int IO::processMidi(int transposeAmount)
{
    return (currentMidiInStream + transposeAmount) % 127;
}

struct Synth
{
    Filter filter1;
    Effects effect1;
    Oscillator oscillator1;
    Envelope envelope1;
    IO io1;

    bool makeSound(Oscillator osc2, IO io2);
    void pitchBend(Oscillator osc3, int numIntervals);
    void processMidi(IO io3, int midiNoteNumber);
};

bool Synth::makeSound(Oscillator osc2, IO io2)
{
    if (osc2.amplitude > 0 && io2.getStatus()) 
        return true;
    
    return false;
}

void Synth::pitchBend(Oscillator osc3, int numIntervals)
{
    osc3.frequency += (numIntervals * 3);
}

void Synth::processMidi(IO io3, int midiNoteNumber)
{
    if (io3.typeOfMidiConnection == "USB") 
        io3.currentMidiInStream = midiNoteNumber;
}

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
