/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





struct StereoSystem
{
    StereoSystem();

    int numSpeakers;
    float wattsOfPower;
    int numAnalogInputs;
    int numDigitalInputs;
    int numEQBands;
    bool subOn;
    int maxBassLevel;
    int bassLevel;

    struct Tape
    {
        Tape();
        std::string tapeName;
        std::string type;
        float quality;
        int minPerSide;
        int positionInMinutes;

        void rewind(bool beginning, int lengthOfTime);
        void fastForward(bool end, int lengthOfTime);
        std::string getTitle();
    };

    void playMusic(std::string album, int track);
    void boostBass(int bassBoostAmount = 5);
    Tape dubTapes(Tape tape1);

    Tape originalTape;
};

StereoSystem::StereoSystem()
{
    std::cout << "StereoSystem::StereoSystem() " << std::endl;
    numSpeakers = 2;
    wattsOfPower = 60.0f;
    numAnalogInputs = 2;
    numDigitalInputs = 2;
    numEQBands = 5;
    subOn = false;
    maxBassLevel = 10;
    bassLevel = 0;
}

StereoSystem::Tape::Tape()
{
    std::cout << "StereoSystem::Tape::Tape() " << std::endl;
    tapeName = "mix";
    type = "chrome bias";
    quality = 1.0f;
    minPerSide = 30;
    positionInMinutes = 0;
}

void StereoSystem::playMusic(std::string album, int track)
{
    std::cout << "Now Playing: " << album << ", Track " << track << std::endl; 
}

void StereoSystem::boostBass(int bassBoostAmount)
{
    if(subOn) 
        bassBoostAmount += 5;

    if(bassLevel + bassBoostAmount > maxBassLevel) 
        bassLevel = maxBassLevel;
    else 
        bassLevel += bassBoostAmount;

    std::cout << "StereoSystem::boostBass  basslevel = " << bassLevel << std::endl; 
}

StereoSystem::Tape StereoSystem::dubTapes(Tape tape1)
{
    tape1.quality *= 0.9f;
    tape1.tapeName += " dub";
    std::cout << "StereoSystem::Tape  tapeQuality = " << tape1.quality << std::endl; 
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
    std::cout << "StereoSystem::Tape::FastForward  positionInMinutes = " << positionInMinutes << std::endl; 
}

std::string StereoSystem::Tape::getTitle()
{
    return tapeName;
}

struct Military
{
    Military();
    std::string branchOfMilitary;
    int numBases;
    int numSoldiers;
    float budget;
    int numReserveSoldiers;

    struct Soldier
    {
        Soldier();
        float height;
        float weight;
        std::string mainSkill;
        int yearsExperience;
        std::string rank;

        bool readyForCombat(float requiredWeight, int requiredExperience);
        void constructShelter(int numberOfSoldiers, std::string weatherConditions = "cloudy");
        void skillsAndRank(std::string mainSkill, std::string rank);
    };

    float spendMoney (std::string Contract, float budget=10000000.57f);
    void defend (int numEnemySoldiers);
    bool invade (int numEnemySoldiers, int numEnemyBases);

    Soldier soldier1;
};

Military::Military()
{
    std::cout << "Military::Military() " << std::endl;
    branchOfMilitary = "Navy";
    numBases = 127;
    numSoldiers = 5000;
    budget = 10000000.0f;
    numReserveSoldiers = 1000;
}

Military::Soldier::Soldier()
{
    std::cout << "Military::Soldier::Soldier() " << std::endl;
    height = 60.2f;
    weight = 185.0f;
    mainSkill = "munitions";
    yearsExperience = 5;
    rank = "corporal";
}

float Military::spendMoney (std::string Contract, float expense)
{
    if(expense > budget) 
    {
        std::cout << "Not enough money to fulfill contract." << std::endl;
        return budget;
    }
    else
    {
        std::cout << "Contract " << Contract << " approved." << std::endl;
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
        std::cout << "Military::defend  numSoldiers = " << numSoldiers << std::endl; 
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
    std::cout << "Construct shelter for: " << numberOfSoldiers <<  " soldiers." << std::endl;
    std::cout << "Weather conditions: " << weatherConditions << std::endl;
}

void Military::Soldier::skillsAndRank(std::string primarySkill, std::string currentRank)
{
    std::cout << "Rank: " << currentRank << std::endl; 
    std::cout << "Skill: " << primarySkill << std::endl;
}

struct House
{
    House();
    int numBedrooms;
    std::string typeOfAC;
    std::string typeOfRoof;
    int currentTemp;
    bool heatingOn;
    float totalSewageProcessed;

    void heatInterior(int thermostatSetting = 75);
    void houseCharacteristics();
    void processSewage(float gallonsOfSewage = 14.5f, bool septicTankFunctional = true);
};

House::House()
{
    std::cout << "House::House() " << std::endl;
    numBedrooms = 2;
    typeOfAC = "central";
    typeOfRoof = "tile";
    currentTemp = 75;
    heatingOn = false;
    totalSewageProcessed = 0.0f;
}
void House::heatInterior(int thermostatSetting)
{
    if(thermostatSetting < currentTemp) 
        heatingOn = true;
    
    heatingOn = false;
}

void House::houseCharacteristics()
{
    std::cout << "Roof type: " << typeOfRoof << ", AC Type: " << typeOfAC << std::endl;
}

void House::processSewage(float gallonsOfSewage, bool septicTankFunctional)
{
    if(septicTankFunctional) 
        totalSewageProcessed += gallonsOfSewage;

    std::cout << "House::processSewage  totalSewageProcessed = " << totalSewageProcessed << std::endl; 
}

struct Plane
{
    Plane();
    int numSeats;
    std::string typeOfEngine;
    double cargoCapacity;
    double currentWeight;
    float fuelLevel;
    
    bool transportCargo(double parcelWeight);
    float sellAlcohol(int totalDrinks, float drinkPrice);
    void fly(int flightTime, float engineThrust, bool clearRunway = true);
};

Plane::Plane()
{
    std::cout << "Plane::Plane() " << std::endl;
    numSeats = 240;
    typeOfEngine = "turboprop";
    cargoCapacity = 5000;
    currentWeight = 0;
    fuelLevel = 5000;
}

bool Plane::transportCargo(double parcelWeight)
{
    if(currentWeight + parcelWeight > cargoCapacity)
         return false;
        
    currentWeight += parcelWeight;
    return true;
        
}

float Plane::sellAlcohol(int totalDrinks, float drinkPrice)
{
    float alcoholSales = totalDrinks * drinkPrice;
    std::cout << "Plane::sellAlcohol  alcoholSales = " << alcoholSales << std::endl; 
    return alcoholSales;
}

void Plane::fly(int flightTime, float engineThrust, bool clearRunway)
{
    if (clearRunway)
    {
        std::cout << "Plane::sellAlcohol  Runyway is Clear " << std::endl; 
        fuelLevel -= (flightTime * engineThrust);
    }
}

struct Filter
{
    Filter();
    int filterSlope;
    std::string activeFilterType;
    float mainFreq;
    float currentQ;
    float currentGain;
    float maxGain;
    
    void highPass(float lowRolloff = 70.0f, int slope = -6);
    void lowPass(float highRolloff = 15000.0f, int slope = 12);
    bool isClipping(float changeInGain = 6.5f);
};

Filter::Filter()
{
    std::cout << "Filter::Filter() " << std::endl;
    filterSlope = -6;
    activeFilterType = "low pass";
    mainFreq = 75.0f;
    currentQ = 1.52f;
    currentGain = 0.0f;
    maxGain = 20.0f;
}

void Filter::highPass(float lowRolloff, int slope)
{
    filterSlope = slope;
    activeFilterType = "highPass";
    mainFreq = lowRolloff;
    std::cout << "Filter::highPass  mainFreq = " << mainFreq << std::endl; 
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
    {
        std::cout << "Filter is clipping" << std::endl;  
        return true;
    }
    
    return false;    
}

struct Effects
{
    Effects();
    float satLevel;
    std::string currentEffect;
    float reverbDecay;
    int bitsCrushed;
    float wet;

    void distort(float gain = 5.0f);
    void bitCrush(int bits = 5);
    void delay(int delayRepeats = 7);
};

Effects::Effects()
{
    std::cout << "Effects::Effects()" << std::endl;
    satLevel = 50.0f;
    currentEffect = "delay";
    reverbDecay = 3.7f;
    bitsCrushed = 7;
    wet = 50.0f;
}

void Effects::distort(float gain)
{
    currentEffect = "distort";
    satLevel = gain * 10.0f;
    wet = 100.0f;
    std::cout << "Effects::distort  wet = " << wet << std::endl; 
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
    Oscillator();
    float frequency;
    float amplitude;
    std::string waveShape;
    std::string typeOfOscillator;
    int numOscillators = 3;

    std::string noteName(int midiNote);
    void modWheel(float modAmount = 0.75f);
    void volumePedal(float volumePedalPostion = 0.5f);
};

Oscillator::Oscillator()
{
    std::cout << "Oscillator::Oscillator()" << std::endl;
    frequency = 500.0f;
    amplitude = 0.75f;
    waveShape = "sine";
    typeOfOscillator = "digital";
    numOscillators = 3;
}

std::string Oscillator::noteName(int midiNote)
{
    auto val = midiNote % 12;
    std::cout << "Oscillator::noteName  currentMidiNote  val = " << val << std::endl; 
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
    Envelope();
    float envAttack;
    float envSustain;
    float envDecay;
    float envRelease;
    float envHold;

    void adjustAttack(float attack);
    void adjustSustain(float sustain);
    void adjustRelease(float release);
};

Envelope::Envelope()
{
    std::cout << "Envelope::Envelope()" << std::endl;
    envAttack = 1.2f;
    envSustain = 5.0f;
    envDecay = .4f;
    envRelease = 2.3f;
    envHold = 4.5f;
}

void Envelope::adjustAttack(float attack)
{
    envAttack = attack;
    std::cout << "Attack = " << attack << std::endl;
}

void Envelope::adjustSustain(float sustain)
{
    envSustain = sustain;
    std::cout << "sustain = " << sustain << std::endl;
}

void Envelope::adjustRelease(float release)
{
    envRelease = release;
    std::cout << "release = " << release << std::endl;
}

struct IO
{
    IO();
    int numInputs;
    int numOutputs;
    std::string typeOfMidiConnection;
    int currentMidiInStream;
    bool firmwareUpToDate;

    bool getStatus();
    void inputStatus(int numActiveInputs = 2);
    int processMidi(int transposeAmount = 12);
};

IO::IO()
{
    std::cout << "IO::IO()" << std::endl;
    numInputs = 2;
    numOutputs = 2;
    typeOfMidiConnection = "USB";
    currentMidiInStream = 50;
    firmwareUpToDate = true;
}

bool IO::getStatus()
{
    if (firmwareUpToDate) 
    {
        std::cout << "Firmware is up to date" << std::endl; 
        return true;
    }
    
    return false;
}

void IO::inputStatus(int numActiveInputs)
{
    if (numActiveInputs == 1) 
        std::cout << "1 active input, mono" << std::endl;
    else if (numActiveInputs == 2) 
        std::cout << "2 active inputs, stereo" << std::endl;
     
    std::cout << "Inputs inactive" << std::endl;
}

int IO::processMidi(int transposeAmount)
{
    return (currentMidiInStream + transposeAmount) % 127;
}

struct Synth
{
    Synth();
    Filter filter1;
    Effects effect1;
    Oscillator oscillator1;
    Envelope envelope1;
    IO io1;

    bool makeSound(Oscillator osc2, IO io2);
    void pitchBend(Oscillator osc3, int numIntervals);
    void processMidi(IO io3, int midiNoteNumber);
};

Synth::Synth()
{
    std::cout << "Synth::Synth()" << std::endl;
    filter1.filterSlope = -12;
}

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
    // Instantiations
    Example::main();
    StereoSystem st1;
    StereoSystem::Tape tp1;
    StereoSystem::Tape tp2;
    Military mt;
    Military::Soldier soldier;
    House newHouse;
    Plane pl1;
    Plane pl2;
    Filter newFilter;
    Effects effectInstance;
    Oscillator osc3;
    Oscillator osc4;
    Envelope envelope1;
    IO ioTest;
    Synth awesomeSynth;
    
    // StereoSystem
    st1.playMusic("Remedy Lane", 1);
    st1.boostBass(7);
    st1.dubTapes(tp2);

    // Tape
    tp1.rewind(false, 50);
    tp1.fastForward(true, 40);
    tp1.getTitle();

    // Military
    mt.spendMoney ("Contract 007", 50000000.57f);
    mt.defend (7256);
    mt.invade (234676,7);

    // Soldier
    soldier.readyForCombat(160.4f, 4);
    soldier.constructShelter(45, "sunny");
    soldier.skillsAndRank("hand to hand combat", "corporal");

    // House
    newHouse.heatInterior(80);
    newHouse.houseCharacteristics();
    newHouse.processSewage(20.0f, true);

    // Plane
    pl1.transportCargo(175.3);
    pl1.sellAlcohol(8, 4.99f);
    pl1.fly(127, 5000.0f, true);

    // Filter
    newFilter.highPass(80.0f, -12);
    newFilter.lowPass(14000.0f, -6);
    newFilter.isClipping(7.5f);

    // Effects
    effectInstance.distort(6.0f);
    effectInstance.bitCrush(10);
    effectInstance.delay(9);

    // Oscillater
    osc3.noteName(74);
    osc3.modWheel(0.8f);
    osc3.volumePedal(0.4f);  

    // Envelope
    envelope1.adjustAttack(3.5f);
    envelope1.adjustSustain(2.3f);
    envelope1.adjustRelease(64.0f);

    // IO
    ioTest.getStatus();
    ioTest.inputStatus(1);
    ioTest.processMidi(10);

    // Synth
    awesomeSynth.makeSound(osc3, ioTest);
    awesomeSynth.pitchBend(osc4, 4);
    awesomeSynth.processMidi(ioTest, 72);

    std::cout << "good to go!" << std::endl;
}
