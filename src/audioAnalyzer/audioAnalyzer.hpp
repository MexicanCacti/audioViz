#pragma once

#ifndef AUDIOANALYZER_H
#define AUDIOANALYZER_H

#define _USE_MATH_DEFINES

#include <fftw3.h>
#include <vector>
#include <cmath>
#include <math.h>

class audioAnalyzer{
    private:
        
        std::vector<float> normalizedAudioData; // Normalize Between -1 to 1 for OpenGL
           

    public:
        audioAnalyzer(const std::vector<float>& audioData);

        std::vector<float> getNormalizedAudioData(){return normalizedAudioData;}
};

#endif