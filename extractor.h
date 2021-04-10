#ifndef _EXTRACTOR_H
#define _EXTRACTOR_H

//includes
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

namespace MHLPET015{


//A CLASS DECLARATION,
class FrameSequence{
    private:
    
    int width;
    int height;
    
     
    

    public:
        std::vector<unsigned char **> wholeImage;
        std::vector<unsigned char **> imageSequence;
        //unsigned char **
        // stores each extracted frame image
        // as a dynamically allocated unsigned
         // char array,
        FrameSequence(void);//contsructor
        ~FrameSequence();//destructor

        

        //Setter
        void setFrameSize(int w,int h);

        //Getters
        int getWidth();
        int getHeight();
        int numberOfFrames;//stores the number of frames in the vector.

        
        
};
FrameSequence ReadImagesFile(std::string filenm,FrameSequence theSequence);






}
#endif // matches the #ifndef