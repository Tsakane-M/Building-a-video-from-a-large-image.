#include "extractor.h"


int main(int argc, char* argv[] )
{
    std::string filename;//stores filename
    int width;//width of frames;
    int height;//height of frames;

    float x1; //begin x of pixels
    float y1; //begin y of pixels
    float x2; //end x of pixels
    float y2; //end y of pixels

    std::string instruction;
    std::string prefixName;

    std::string numberOfSequences;




    //check argument inputs

    int a=2; //we use this variable to check arguments.
    filename = argv[1]; //save filename found at arg value [2]


    while(a<argc-1){

        if((std::string(argv[a]))=="-t"){
            x1=std::stoi(argv[a+1]);
            y1=std::stoi(argv[a+2]);
            x2=std::stoi(argv[a+3]);
            y2=std::stoi(argv[a+4]);
            a+=4;

        }

        else if((std::string(argv[a]))=="-s"){
            width=std::stoi(argv[a+1]);
            height=std::stoi(argv[a+2]);
            a+=2;
        }

        else if((std::string(argv[a]))=="-s"){
            width=std::stoi(argv[a+1]);
            height=std::stoi(argv[a+2]);
            a+=2;
        }
        else if((std::string(argv[a]))=="-t"){
            x1=std::stoi(argv[a+1]);
            y1=std::stoi(argv[a+2]);
            x2=std::stoi(argv[a+3]);
            y2=std::stoi(argv[a+4]);
            a+=4;

        }
        else if((std::string(argv[a]))=="-w"){
            instruction=std::string(argv[a+1]);
            prefixName=std::string(argv[a+2]) ;
            a+=2;

        }
        a++;
        

    }



   // std::cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<width<<" "<<height<<" "<<instruction<<" "<<prefixName<<" end"<<std::endl;

    



    //initialise FramseSequence class to store vector.s
    MHLPET015::FrameSequence theSequence;

    //set width and height of Frames to be printed out.
    theSequence.setFrameSize(width,height);

    //get dimensions of Original Image.
    std::string dimensions=MHLPET015::getImageDimensions(filename);

    //read whole image to FrameSequence class
    theSequence=MHLPET015::ReadImagesFile(filename,theSequence,dimensions);

    //extract Frames from whole image.
    theSequence=MHLPET015::extractFrames(theSequence,x1,y1,x2,y2);

    //check instructions:
    if(instruction=="none"){//if instruction is "none"
        //printout unedited image sequence.
        theSequence.WriteFrames(theSequence,prefixName);
    }

    else if(instruction=="invert"){
        //printout inverted image sequence.
        theSequence.WriteFrames(MHLPET015::sequenceInverter(theSequence),prefixName);

    }
    else if(instruction=="reinvert"){
        //printout reversed and inverted image sequence.
        theSequence.WriteFrames(MHLPET015::reInverse(theSequence),prefixName);


    }


    return 0;
}



