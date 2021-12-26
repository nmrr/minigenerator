#ifndef MINIGENERATOR_H
#define MINIGENERATOR_H

#include <iostream>
#include <cmath>


class minigenerator
{
private:

    uint32_t sampleRate;
    void int16ToChar(int16_t input, char &a, char &b);

public:

    minigenerator(uint32_t sampleRate=44100);
    void sinus(double freq, double intensity, uint32_t sampleNumber);
    void square(double freq, double intensity, uint32_t sampleNumber);
    void triangle(double freq, double intensity, uint32_t sampleNumber);
    void sawtooth(double freq, double intensity, uint32_t sampleNumber);

};
#endif // MINIGENERATOR_H
