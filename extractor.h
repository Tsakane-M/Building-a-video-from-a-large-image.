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

        
        void writeWholeImage(FrameSequence Sequence,std::string dim);
        void WriteFrames(FrameSequence mySeq,std::string pN);
  
        
        
};

FrameSequence ReadImagesFile(std::string filenm,FrameSequence theSequence,std::string dimensions);
std::string getImageDimensions(std::string filename);
void WriteImage(FrameSequence mySeq,std::string dim);
FrameSequence extractFrames(FrameSequence oldSeq,int x0,int y0,int x3,int y3);







}
#endif // matches the if