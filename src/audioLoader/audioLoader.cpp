#include "audioLoader.hpp"

audioLoader::audioLoader(const std::string& audioFilePath){
    this->audioFilePath = audioFilePath;

    audioFile = sf_open(audioFilePath.c_str(), SFM_READ, &audioInfo);

    if(!audioFile){
        throw std::runtime_error("Error opening audio file: " + audioFilePath);
    }

    sampleRate = audioInfo.samplerate;
    numFrames = audioInfo.frames;
    numChannels = audioInfo.channels;

    audioData.resize(numFrames * numChannels);
    // L1, R1, L2, R2, L3, R3 ... , LN, RN If 2 channels
    // S1, S2, S3, S4, ... , SN if 1 Channel
    // Interleaved

    sf_read_float(audioFile, audioData.data(), numFrames);

    sf_close;
}

audioLoader::~audioLoader(){
    if(audioFile){
        sf_close(audioFile);
    }
}