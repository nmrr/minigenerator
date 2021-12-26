#include "minigenerator.h"

#define SAMPLE_RATE 44100

int main(int argc, char** argv)
{
    minigenerator generator = minigenerator(SAMPLE_RATE);
    generator.sinus(440, 1, SAMPLE_RATE*1);
    generator.square(440, 0.2, SAMPLE_RATE*1);
    generator.triangle(440, 0.8, SAMPLE_RATE*1);
    generator.sawtooth(440, 0.4, SAMPLE_RATE*1);

    return 0;
}