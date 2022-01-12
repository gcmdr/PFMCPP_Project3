/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct StereoSystem
{
    StereoSystem();

    int numSpeakers = 2;
    float wattsOfPower = 60.0f;
    int numAnalogInputs = 2;
    int numDigitalInputs = 2;
    int numEQBands;
    bool subOn;
    int maxBassLevel;
    int bassLevel;

    struct Tape
    {
        Tape();
        std::string tapeName = "mix";
        std::string type = "chrome bias";
        float quality;
        int minPerSide;
        int positionInMinutes;

        void rewind(bool beginning, int lengthOfTime);
        void fastForward(bool end, int lengthOfTime);
        std::string getTitle();
        void splice(int lengthOfSplice);
    };

    void playMusic(std::string album, int track);
    void boostBass(int bassBoostAmount = 5);
    Tape dubTapes(Tape tape1);
    void destroyTheBass();

    Tape originalTape;
};

StereoSystem::StereoSystem() : 
numEQBands(5),
subOn(false),
maxBassLevel(10),
bassLevel(0)
{
    std::cout << "StereoSystem " << std::endl;
}

StereoSystem::Tape::Tape() : 
quality(1.0f),
minPerSide(30),
positionInMinutes(0)
{
    std::cout << "StereoSystem::Tape " << std::endl;
}

void StereoSystem::playMusic(std::string album, int track)
{
    std::cout << "Max bass level = " << maxBassLevel << std::endl;
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
    std::cout << "Watts of power = " << wattsOfPower << std::endl; 
    std::cout << "StereoSystem::boostBass  basslevel = " << bassLevel << std::endl; 
}

void StereoSystem::destroyTheBass()
{
    while(bassLevel > 0)
    {
        --bassLevel;
    }
    std::cout << "Bass has been destroyed, bass level is now: " << bassLevel << std::endl;
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
    std::cout << "Position in minutes = " << positionInMinutes << std::endl;
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

void StereoSystem::Tape::splice(int lengthOfSplice)
{
    int i = 0;
    while(i < lengthOfSplice)
    {
        ++minPerSide;
        ++i;
    }
    std::cout << "After splice,min per side = " << minPerSide << std::endl;
}

struct Military
{
    Military();
    std::string branchOfMilitary;
    int numBases;
    int numSoldiers = 5000;
    float budget = 10000000.0f;
    int numReserveSoldiers = 1000;

    struct Soldier
    {
        Soldier();
        float height = 60.2f;
        float weight;
        std::string mainSkill;
        int yearsExperience;
        std::string rank = "corporal";

        bool readyForCombat(float requiredWeight, int requiredExperience);
        void constructShelter(int numberOfSoldiers, std::string weatherConditions = "cloudy");
        void skillsAndRank(std::string mainSkill, std::string rank);
        float weightGainFromPushups(int numberOfPushups);
    };

    float spendMoney(std::string Contract, float budget=10000000.57f);
    void defend(int numEnemySoldiers);
    bool invade(int numEnemySoldiers, int numEnemyBases);
    int catch22(int numBombs);


    Soldier soldier1;
};

Military::Military() : 
branchOfMilitary("Navy"),
numBases(127)
{
    std::cout << "Military " << std::endl;
}

Military::Soldier::Soldier() :
weight(185.0f),
mainSkill("munitions"),
yearsExperience(5)
{
    std::cout << "Military::Soldier " << std::endl;
}

float Military::spendMoney (std::string Contract, float expense)
{
    std::cout << "Budget = " << budget << std::endl;
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
        std::cout << "numBases = " << numBases << std::endl; 
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

int Military::catch22(int bombs)
{
    int basesDestroyed = 0;
    while(bombs > 0)
    {
        ++basesDestroyed;
        --bombs;
    }
    std::cout << basesDestroyed << " bases have been destroyed" << std::endl;
    return basesDestroyed;
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
    std::cout << "Main Skill: " << mainSkill << std::endl;
}

float Military::Soldier::weightGainFromPushups(int numPushups)
{
    float weightGained = 0.0f;
    for (int i = 1; i < numPushups; i++)
    {
        if(i % 5 == 0)
        {
            weightGained += .01f;
        }
    }

    weight += weightGained; // add weightGained to total weight
    std::cout << weightGained << "lbs were gained!" << std::endl;
    return weightGained;
}

struct House
{
    House();
    int numBedrooms = 2;
    std::string typeOfAC = "central";
    std::string typeOfRoof = "tile";
    int currentTemp;
    bool heatingOn;
    float totalSewageProcessed;

    void heatInterior(int thermostatSetting = 75);
    void houseCharacteristics();
    void processSewage(float gallonsOfSewage = 14.5f, bool septicTankFunctional = true);
    void changeTemp(int lowTemp, int highTemp);
};

House::House() :
currentTemp(75),
heatingOn(false),
totalSewageProcessed(0.0f)
{
    std::cout << "House " << std::endl;
}
void House::heatInterior(int thermostatSetting)
{
    std::cout << "Current temp: " << currentTemp << std::endl;
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

void House::changeTemp(int lowTemp, int highTemp)
{
    if(heatingOn)
    {
        while(currentTemp < highTemp)
        {
            ++currentTemp;
        }
        std::cout << "House has warmed to " << currentTemp << " degrees" << std::endl;
    }
    else
    {
        while(currentTemp > lowTemp)
        {
            --currentTemp;
        }
        std::cout << "House has cooled to " << currentTemp << " degrees" << std::endl;
    }

}

struct Plane
{
    Plane();
    int numSeats;
    std::string typeOfEngine;
    double cargoCapacity = 5000;
    double currentWeight = 0;
    float fuelLevel = 5000;
    
    bool transportCargo(double parcelWeight);
    float sellAlcohol(int totalDrinks, float drinkPrice);
    void fly(int flightTime, float engineThrust, bool clearRunway = true);
    void cleanSeats(int numSeatsToClean);
};

Plane::Plane() :
numSeats(240),
typeOfEngine("turboprop")
{
    std::cout << "Plane " << std::endl;
}

bool Plane::transportCargo(double parcelWeight)
{
    std::cout << "Cargo capacity is: " << cargoCapacity << std::endl;
    if(currentWeight + parcelWeight > cargoCapacity)
         return false;
        
    currentWeight += parcelWeight;
    return true;
        
}

void Plane::cleanSeats(int numberOfSeats)
{
    int numCleanedSeats = 0;
    for(int i = 0; i < numberOfSeats; ++i)
    {
        ++numCleanedSeats;
    }
    std::cout << numCleanedSeats << " seats cleaned" << std::endl;

}

float Plane::sellAlcohol(int totalDrinks, float drinkPrice)
{
    float alcoholSales = totalDrinks * drinkPrice;
    std::cout << "Plane::sellAlcohol  alcoholSales = " << alcoholSales << std::endl; 
    return alcoholSales;
}

void Plane::fly(int flightTime, float engineThrust, bool clearRunway)
{
    std::cout << "Type of engine: " << typeOfEngine << std::endl; 
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
    float currentQ;
    float currentGain;
    float maxGain;
    
    void highPass(float lowRolloff = 70.0f, int slope = -6);
    void lowPass(float highRolloff = 15000.0f, int slope = 12);
    bool isClipping(float changeInGain = 6.5f);
    void envelopeFilter(float lowFreq, float highFreq);
};

Filter::Filter() :
currentQ(1.52f),
currentGain(0.0f),
maxGain(20.0f)
{
    std::cout << "Filter " << std::endl;
}

void Filter::envelopeFilter(float lowFreq, float highFreq)
{
    std::cout << "sweep from " << lowFreq << "hZ to " << highFreq << "hz" << std::endl;
    mainFreq = lowFreq;
    while(mainFreq < highFreq)
    {
        mainFreq += 0.01f;
    }

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
    std::cout << "Current gain = " << currentGain << std::endl; 
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
    std::string currentEffect;
    float reverbDecay;
    int bits;
    float wet = 50.0f;

    void distort(float gain = 5.0f);
    void bitCrush(int bits = 5);
    void delay(int delayRepeats = 7);
    void crushLess(int maxBits);
};

Effects::Effects() : 
currentEffect("delay"),
reverbDecay(3.7f),
bits(7)
{
    std::cout << "Effects" << std::endl;
}

void Effects::crushLess(int maxBits)
{
    std::cout << "bits before uncrushing: " << bits << std::endl;
    int bitsToUncrush = maxBits - bits;
    for(int i = 0; i < bitsToUncrush * 100; ++i)
    {
        if (i % 100)
        {
            ++bits;
        }
    }
    std::cout << "bits after uncrushed: " << bits << std::endl;
}

void Effects::distort(float gain)
{
    currentEffect = "distort";
    satLevel = gain * 10.0f;
    wet = 100.0f;
    std::cout << "Effects::distort  wet = " << wet << std::endl; 
}

void Effects::bitCrush(int newBits)
{
    currentEffect = "bitCrush";
    satLevel = 0.0f;
    wet = 75.0f;
    bits = newBits;
    std::cout << "Bits crushed = " << bits << std::endl; 
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
    std::string waveShape = "sine";
    std::string typeOfOscillator = "digital";
    int numOscillators = 3;

    std::string noteName(int midiNote);
    void modWheel(float modAmount = 0.75f);
    void volumePedal(float volumePedalPostion = 0.5f);
    void portamento(float nextNote);
};

Oscillator::Oscillator() : 
frequency(500.0f),
amplitude(0.75f)
{
    std::cout << "Oscillator" << std::endl;
}

void Oscillator::portamento(float nextNote)
{
    std::cout << "Initial freq: " << frequency << std::endl;
    
    if (frequency < nextNote)
    {
        while(frequency < nextNote)
        {
            frequency += 0.1f;
        }
    }
    else
    {
        while(frequency > nextNote)
        {
            frequency -= 0.1f;
        }
    }

    std::cout << "Final freq: " << frequency << std::endl;
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
    std::cout << "frequency before adjustment = " << frequency << std::endl;
    frequency *= (modAmount * 12);
}

void Oscillator::volumePedal(float volumePedalPosition)
{
    std::cout << "amplitude = " << amplitude << std::endl;
    amplitude = volumePedalPosition;
}

struct Envelope
{
    Envelope();
    float envAttack = 1.2f;
    float envSustain = 5.0f;
    float envDecay = 0.4f;
    float envRelease;
    float envHold;

    void adjustAttack(float attack);
    void adjustSustain(float sustain);
    void adjustRelease(float release);
    float extendAttack(float unitsOfTime);
};

Envelope::Envelope() : 
envRelease(2.3f),
envHold(4.5f)
{
    std::cout << "Envelope" << std::endl;
}

float Envelope::extendAttack(float unitsOfTime)
{
    for(float newTime = 0.0f; newTime < unitsOfTime; ++newTime)
    {
        ++envAttack;
    }
    std::cout << "new attack is " << envAttack << std::endl;
    return envAttack;
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
    std::string typeOfMidiConnection = "USB";
    int currentMidiInStream = 50;
    bool firmwareUpToDate = true;

    bool getStatus();
    void inputStatus(int numActiveInputs = 2);
    int processMidi(int transposeAmount = 12);
    void sweepUpAndDown();
};

IO::IO() : 
numInputs(2),
numOutputs(2)
{
    std::cout << "IO" << std::endl;
}

void IO::sweepUpAndDown()
{
    int ogNote = currentMidiInStream;
    while(currentMidiInStream < 127)
    {
        ++currentMidiInStream;
    }
    while(currentMidiInStream > ogNote)
    {
        --currentMidiInStream;
    }
    std::cout << "swept from " << ogNote << " to the top and back down" << std::endl;
}

bool IO::getStatus()
{
    std::cout << "typeOfMidiConnection: " << typeOfMidiConnection << std::endl; 
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

    std::cout << "NumActive inputs = " << numInputs << std::endl; 
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
    void fadeOut(Oscillator osc1);
};

Synth::Synth()
{
    std::cout << "Synth" << std::endl;
}

void Synth::fadeOut(Oscillator osc1)
{
    while(osc1.amplitude > 0)
    {
        osc1.amplitude -= 0.01f;
    }
    std::cout << "synth is silent" << std::endl;
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
    st1.destroyTheBass();

    // Tape
    tp1.rewind(false, 50);
    tp1.fastForward(true, 40);
    tp1.getTitle();
    tp1.splice(27);

    // Military
    mt.spendMoney ("Contract 007", 50000000.57f);
    mt.defend (7256);
    mt.invade (234676,7);
    mt.catch22(28);

    // Soldier
    soldier.readyForCombat(160.4f, 4);
    soldier.constructShelter(45, "sunny");
    soldier.skillsAndRank("hand to hand combat", "corporal");
    soldier.weightGainFromPushups(200);

    // House
    newHouse.heatInterior(80);
    newHouse.houseCharacteristics();
    newHouse.processSewage(20.0f, true);
    newHouse.changeTemp(20,90);

    // Plane
    pl1.transportCargo(175.3);
    pl1.sellAlcohol(8, 4.99f);
    pl1.fly(127, 5000.0f, true);
    pl1.cleanSeats(234);

    // Filter
    newFilter.highPass(80.0f, -12);
    newFilter.lowPass(14000.0f, -6);
    newFilter.isClipping(7.5f);
    newFilter.envelopeFilter(50.0f, 1750.0f);

    // Effects
    effectInstance.distort(6.0f);
    effectInstance.bitCrush(10);
    effectInstance.delay(9);
    effectInstance.crushLess(24);

    // Oscillater
    osc3.noteName(74);
    osc3.modWheel(0.8f);
    osc3.volumePedal(0.4f);  
    osc3.portamento(5000.0f);

    // Envelope
    envelope1.adjustAttack(3.5f);
    envelope1.adjustSustain(2.3f);
    envelope1.adjustRelease(64.0f);
    envelope1.extendAttack(1000.0f);

    // IO
    ioTest.getStatus();
    ioTest.inputStatus(1);
    ioTest.processMidi(10);
    ioTest.sweepUpAndDown();

    // Synth
    awesomeSynth.makeSound(osc3, ioTest);
    awesomeSynth.pitchBend(osc4, 4);
    awesomeSynth.processMidi(ioTest, 72);
    awesomeSynth.fadeOut(osc4);

    std::cout << "good to go!" << std::endl;
}
