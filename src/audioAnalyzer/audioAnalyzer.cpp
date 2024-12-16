#include "audioAnalyzer.hpp"

audioAnalyzer::audioAnalyzer(const std::vector<float>& audioData){

    std::vector<float> normalizedData;
    for (int i = 0; i < audioData.size(); ++i) {
        float x = (i / float(audioData.size())) * 2.0f - 1.0f;  // Scale X to [-1, 1]
        float y = audioData[i];  // Amplitude, which should already be in a normalized range (-1 to 1)
        
        if(y > 1.0f){
            y = 1.0f;
        }
        if(y < -1.0f){
            y = -1.0f;
        }
        
        normalizedData.push_back(x);
        normalizedData.push_back(y / 4);  // Store X and Y coordinates
    }

    this->normalizedAudioData = normalizedData;
}


