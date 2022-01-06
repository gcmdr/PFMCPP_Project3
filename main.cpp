/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/







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
