#include "extractor.h"

namespace MHLPET015{

    //define the destructor for FrameSequence
    FrameSequence::~FrameSequence(){
        

        for(int n = 0; n < numberOfFrames; n++)
		{
			for(int r = 0; r < height; r++)
			{
				delete wholeImage[n][r]; //delete pointer to each row of raw file
			}
			delete wholeImage[n]; //delete pointer to each raw file
		}
	}
    

    //define the constructor method for FrameSequence
    FrameSequence::FrameSequence(void){
        width=0;
        height=0;
        numberOfFrames=0;
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
    
    //method to read in images and save image sequences to vector.
    FrameSequence ReadImagesFile(std::string filenm,FrameSequence theSequence){
        std::string filename;//stores filename
        filename=filenm;
        int numberOfFrameImages=1;
        int numberOfFrames=1;
  

        //declare data array to store data read in
        char* data=new char[theSequence.getHeight()*theSequence.getWidth()];
        int rows=theSequence.getHeight();
        int columns=theSequence.getWidth();

      



        //read in the file
        std::ifstream in;
        in.open(filename,std::ios::in|std::ios::out|std::ios::binary);//open file as binary file
    
        if(in.is_open()){
        
            in.seekg(0,std::ios::beg);//Move pointer to beginning of file.
            //skip 4 lines
            for(int i=0;i<4;i++){
                in.ignore(1000,'\n');
            }
            in.read(data,rows*columns);//Read in
            //std::cout<<data<<std::endl;
        
            //close reading
            in.close();
        }
        else{
		    std::cout << "Unable to open the file\n" ;
	    }
        //read in image to vector.

     
        //Read from file to data array
        //initialise a pointer to data array
        int dataPointer=0;

        //for each frame
        for(int i=0;i<numberOfFrameImages;i++){

            int read_pixels=0; //stores how many pixels have been stored in each frame
        

            //initialise 2D pointer to store the 2D frame image points
            unsigned char **frameImage=new unsigned char*[rows];

     
            //check if the frame image points to a nullptr
            if(frameImage!=nullptr){
            
                //for each row
                for(int j=0;j<rows;j++){

                    //initialise a pointer to that row
                    frameImage[j]=new unsigned char[columns];

                    //for each column in that row
                    for(int k=0;k<columns;k++){
                        //populate each column of that row with input data
                        frameImage[j][k]=data[dataPointer];

                        //increase pointer value
                        dataPointer++;

                        //printout elements of frameImage.
                        //std::cout<<frameImage[j][k]<<" ";

                        //increase pixel count
                        read_pixels++;

                    }
                    //std::cout<<std::endl;

            }
                //save pointer array to vector in which stores the Sequence.
                theSequence.wholeImage.push_back(frameImage);
         
            }

    }return theSequence;
    }


    
}






