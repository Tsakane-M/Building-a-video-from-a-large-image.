#ifndef _EXTRACTOR_H
#define _EXTRACTOR_H

//includes
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

namespace MHLPET015{


//A CLASS DECLARATION,
class FrameSequence{
    private:
    int width;
    int height;
    
    

    public:
        std::vector<unsigned char **> imageSequence;// stores each extracted frame image
                                                // as a dynamically allocated unsigned
                                                 // char array,
        FrameSequence(void);
        ~FrameSequence();
        void setFrameSize(int width,int height);
};




}
#endif // matches the #ifndef