#pragma once

#ifndef AUDIOLOADER_H
#define AUDIOLOADER_H

#include <sndfile.h>
#include <vector>
#include <string>
#include <stdexcept>

class audioLoader{
    private:
        SF_INFO audioInfo;
        SNDFILE* audioFile;
        std::vector<float> audioData;
        int sampleRate;
        int numFrames;
        int numChannels;
        std::string audioFilePath;

    public:
        audioLoader(const std::string& audioFilePath);

        ~audioLoader();

        SF_INFO getAudioInfo() const {return this->audioInfo;}

        std::vector<float> getAudioData() const {return this->audioData;}

        int getSampleRate() const {return this->sampleRate;}

        int getNumFrames() const {return this->numFrames;}

        int getNumChannels() const {return this->numChannels;}

        std::string getAudioFilePath() const {return this->audioFilePath;}

};

#endif