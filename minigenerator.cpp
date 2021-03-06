#include "minigenerator.h"

/*
The MIT License (MIT)
Copyright (c) 2021 https://github.com/nmrr
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

void minigenerator::int16ToChar(int16_t input, char &a, char &b)
{
    union
    {
        int16_t value;
        char array[2];
    };

    value = input;
    a = array[0];
    b = array[1];
}

minigenerator::minigenerator(uint32_t sampleRate)
{
    this->sampleRate = sampleRate;
}


void minigenerator::sinus(double freq, double intensity, uint32_t sampleNumber)
{
    double value = 0;
    const double sample = ((M_PI*2)/double(sampleRate))*freq;
    char a,b;

    for (uint32_t i=0; i<sampleNumber; i++)
    {
        value += sample;
        if (value > 2*M_PI) value -= 2*M_PI;

        int16ToChar(32767*intensity*sin(value), a, b);
        std::cout << a << b;
    }
}

void minigenerator::square(double freq, double intensity, uint32_t sampleNumber)
{
    double position = 0;
    const double sample = double(sampleRate) / freq / 2;
    int output = -1;
    char a,b;

    for (uint32_t i=0; i<sampleNumber; i++)
    {
        if (position >= sample)
        {
            position = (position-sample) + 1;
            if (output == 1) output = -1;
            else output = 1;
        }
        else position++;

        int16ToChar((output == 1 ? intensity*32767 : intensity*-32767), a, b);
        std::cout << a << b;
    }
}

void minigenerator::triangle(double freq, double intensity, uint32_t sampleNumber)
{
    double position = 0;
    const double sample = double(sampleRate) / freq / 2;
    double output = -1;
    double outputValue = 1;
    char a,b;

    for (uint32_t i=0; i<sampleNumber; i++)
    {
        if (position >= sample)
        {
            position = (position-sample) + 1;
            if (output == 1)
            {
                output = -1;
                outputValue = 1;
            }
            else
            {
                output = 1;
                outputValue = -1;
            }
        }
        else position++;

        if (output == 1)
        {
            outputValue += 2/sample;
            if (outputValue > 1) outputValue = 1;
        }
        else
        {
            outputValue -= 2/sample;
            if (outputValue < -1) outputValue = -1;
        }

        int16ToChar(intensity*32767*outputValue, a, b);
        std::cout << a << b;
    }
}

void minigenerator::sawtooth(double freq, double intensity, uint32_t sampleNumber)
{
    double position = 0;
    const double sample = double(sampleRate) / freq;
    double output = -1;

    for (uint32_t i=0; i<sampleNumber; i++)
    {
        if (position >= sample)
        {
            output = -1;
            position = (position-sample) + 1;
        }
        else
        {
            output += 2/sample;
            position++;
        }

        char a,b;
        int16ToChar(intensity*32767*output, a, b);
        std::cout << a << b;
    }
}
