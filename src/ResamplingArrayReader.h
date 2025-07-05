#ifndef TEENSYAUDIOLIBRARY_RESAMPLINGARRAYREADER_H
#define TEENSYAUDIOLIBRARY_RESAMPLINGARRAYREADER_H

#include <Arduino.h>
#include "SD.h"
#include <cstdint>
#include "loop_type.h"
#include "interpolation.h"
#include "ResamplingReader.h"

namespace newdigate {

class ResamplingArrayReader : public ResamplingReader<int16_t, File> {
public:
    ResamplingArrayReader() :
        ResamplingReader() {
    }    
    
    virtual ~ResamplingArrayReader() {
    }

    int16_t getSourceBufferValue(long index) override {
        return _sourceBuffer[index];
    }

    int available(void) {
        return _playing;
    }

    int16_t* createSourceBuffer() override {
        return _sourceBuffer;
    }

    void close(void) override {
        if (_playing) {
            stop();
        }
    }

    File open(char *filename) override {
        return File();
    }

    uint32_t positionMillis(void) {
    if (_file_size == 0) return 0;
//    if (!_useDualPlaybackHead) {
            return (uint32_t) (( (double)_bufferPosition1 * lengthMillis() ) / (double)(_file_size/2));
//        } else {
//            if (_crossfade < 0.5)
//                return (uint32_t) (( (double)_bufferPosition1 * lengthMillis() ) / (double)(_file_size/2));
//            else
//                // this one causes the playhead to be reported at the start or end of the loop, no movement at all
//                return (uint32_t) (( (double)_bufferPosition2 * lengthMillis() ) / (double)(_file_size/2));
//        }
//    }
    
protected:
};

}

#endif //TEENSYAUDIOLIBRARY_RESAMPLINGARRAYREADER_H
