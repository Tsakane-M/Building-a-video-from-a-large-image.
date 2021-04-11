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
    if(argc == 1){
		filename = "sloan_image.pgm";
	}
	

    if(argc>1){
        filename = argv[1];
        std::string argumenta(argv[2]);
        std::string argumentb(argv[7]);
        std::string argumentc(argv[5]);
        std::string argumentd(argv[11]);


        if(argumenta=="-t"){
            x1=std::stoi(argv[3]);
            y1=std::stoi(argv[4]);
            x2=std::stoi(argv[5]);
            y2=std::stoi(argv[6]);

        }
        if(argumenta=="-s"){
            width=std::stoi(argv[3]);
            height=std::stoi(argv[4]);
        }
        if(argumentb=="-s"){
            width=std::stoi(argv[8]);
            height=std::stoi(argv[9]);
        }
        if(argumentc=="-t"){
            x1=std::stoi(argv[6]);
            y1=std::stoi(argv[7]);
            x2=std::stoi(argv[8]);
            y2=std::stoi(argv[9]);

        }
        if(argumentd=="-w"){
            instruction=argv[12];
            prefixName=(argv[13]) ;


        }

    }
    std::cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<width<<" "<<height<<" "<<instruction<<" "<<prefixName<<"end"<<std::endl;

    



     //initialise FramseSequence class to store vector.s
    MHLPET015::FrameSequence theSequence;
    theSequence.setFrameSize(width,height);

    std::string dimensions=MHLPET015::getImageDimensions(filename);

    theSequence=MHLPET015::ReadImagesFile(filename,theSequence,dimensions);
    //MHLPET015::WriteImage(theSequence,dimensions);
    theSequence=MHLPET015::extractFrames(theSequence,x1,y1,x2,y2);
    //theSequence.WriteFrames(theSequence,prefixName);
    //theSequence.WriteFrames(MHLPET015::sequenceInverter(theSequence),prefixName);
    theSequence.WriteFrames(MHLPET015::sequenceReverse(theSequence),prefixName);
    
    


   






 
    
    


    return 0;
}



