#include "extractor.h"

namespace MHLPET015{

    //define the destructor for FrameSequence
    FrameSequence::~FrameSequence(){
        int numberOfFrames=imageSequence.size();

        for(int n = 0; n < numberOfFrames; n++)
		{
			for(int r = 0; r < height; r++)
			{
				delete imageSequence[n][r]; //delete pointer to each row of raw file
			}
			delete imageSequence[n]; //delete pointer to each raw file
		}
	}
    

    //define the constructor method for FrameSequence
    FrameSequence::FrameSequence(void){
        width=0;
        height=0;
    }

    void FrameSequence::setFrameSize(int w,int h){
            width=w;
            height=h;
        }

    int FrameSequence::getWidth(){
        return width;
    }

    int FrameSequence::getHeight(){
        return height;
    }
}
  






