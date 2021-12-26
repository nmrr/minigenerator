# minigenerator
A signal generator (sinus, square, triangle, sawtooth) written in C++

Build the example : 
```
g++ -Wall -pipe -Ofast main.cpp minigenerator.cpp -o minigenerator
```


Run the example :
```
./minigenerator > out
```

Use audacity (or other audio software) and import output data as **Raw Data** using the following parameters :
- Signed 16-bit PCM
- Little-endian
- 1 Channel (Mono)
- Sample rate : 44100

Each signal function are used sequentially at the same frequency (440 Hz) but at different volume level.

# How to use this class ?

Create an object and define sample rate : 
```
minigenerator generator = minigenerator(SAMPLE_RATE);
```

Call a function (sinus, square, triangle, sawtooth) and indicate the **frequency** (double), the **volume** (double, between 0 & 1) and **duration** (integer, number of samples)
```
generator.sinus(FREQUENCY, VOLUME, DURATION);
```
