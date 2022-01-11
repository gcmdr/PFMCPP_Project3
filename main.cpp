/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; // in-class initialization
    UDT() : a(0) { } // 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



struct StereoSystem
{
    StereoSystem();

    int numSpeakers = 2;
    float wattsOfPower = 60.0f;
    int numAnalogInputs = 2;
    int numDigitalInputs = 2;
    int numEQBands = 5;
    bool subOn = false;
    int maxBassLevel = 10;
    int bassLevel = 0;

    struct Tape
    {
        Tape();
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

StereoSystem::StereoSystem()
{
    std::cout << "StereoSystem " << std::endl;
}

StereoSystem::Tape::Tape()
{
    std::cout << "StereoSystem::Tape " << std::endl;
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
    std::string branchOfMilitary = "Navy";
    int numBases = 127;
    int numSoldiers = 5000;
    float budget = 10000000.0f;
    int numReserveSoldiers = 1000;

    struct Soldier
    {
        Soldier();
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

Military::Military()
{
    std::cout << "Military " << std::endl;
}

Military::Soldier::Soldier()
{
    std::cout << "Military::Soldier " << std::endl;
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
    int numBedrooms = 2;
    std::string typeOfAC = "central";
    std::string typeOfRoof = "tile";
    int currentTemp = 75;
    bool heatingOn = false;
    float totalSewageProcessed = 0.0f;

    void heatInterior(int thermostatSetting = 75);
    void houseCharacteristics();
    void processSewage(float gallonsOfSewage = 14.5f, bool septicTankFunctional = true);
};

House::House()
{
    std::cout << "House " << std::endl;
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
    int numSeats = 240;
    std::string typeOfEngine = "turboprop";
    double cargoCapacity = 5000;
    double currentWeight = 0;
    float fuelLevel = 5000;
    
    bool transportCargo(double parcelWeight);
    float sellAlcohol(int totalDrinks, float drinkPrice);
    void fly(int flightTime, float engineThrust, bool clearRunway = true);
};

Plane::Plane()
{
    std::cout << "Plane " << std::endl;
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
    int filterSlope = -6;
    std::string activeFilterType = "low pass";
    float mainFreq = 75.0f;
    float currentQ = 1.52f;
    float currentGain = 0.0f;
    float maxGain = 20.0f;
    
    void highPass(float lowRolloff = 70.0f, int slope = -6);
    void lowPass(float highRolloff = 15000.0f, int slope = 12);
    bool isClipping(float changeInGain = 6.5f);
};

Filter::Filter()
{
    std::cout << "Filter " << std::endl;
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
    float satLevel = 50.0f;
    std::string currentEffect = "delay";
    float reverbDecay = 3.7f;
    int bitsCrushed = 7;
    float wet = 50.0f;

    void distort(float gain = 5.0f);
    void bitCrush(int bits = 5);
    void delay(int delayRepeats = 7);
};

Effects::Effects()
{
    std::cout << "Effects" << std::endl;
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
    float frequency = 500.0f;
    float amplitude = 0.75f;
    std::string waveShape = "sine";
    std::string typeOfOscillator = "digital";
    int numOscillators = 3;

    std::string noteName(int midiNote);
    void modWheel(float modAmount = 0.75f);
    void volumePedal(float volumePedalPostion = 0.5f);
};

Oscillator::Oscillator()
{
    std::cout << "Oscillator" << std::endl;
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
    float envAttack = 1.2f;
    float envSustain = 5.0f;
    float envDecay = 0.4f;
    float envRelease = 2.3f;
    float envHold = 4.5f;

    void adjustAttack(float attack);
    void adjustSustain(float sustain);
    void adjustRelease(float release);
};

Envelope::Envelope()
{
    std::cout << "Envelope" << std::endl;
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
    int numInputs = 2;
    int numOutputs = 2;
    std::string typeOfMidiConnection = "USB";
    int currentMidiInStream = 50;
    bool firmwareUpToDate = true;

    bool getStatus();
    void inputStatus(int numActiveInputs = 2);
    int processMidi(int transposeAmount = 12);
};

IO::IO()
{
    std::cout << "IO" << std::endl;
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
    std::cout << "Synth" << std::endl;
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
