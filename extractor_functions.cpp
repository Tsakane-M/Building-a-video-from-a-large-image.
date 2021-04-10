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
    

    std::string getImageDimensions(std::string file){
         //read in the file
        std::ifstream in;
        std::string line;
        in.open(file);//open file 
        std::string dimensions;
    
        if(in.is_open()){
        
            //in.seekg(0,std::ios::beg);//Move pointer to beginning of file.
            //skip 4 lines
            for(int i=0;i<2;i++){
                getline(in, line);
                
            }
            
            getline(in, dimensions);
            //std::cout<<dimensions<<std::endl;
            //std::cout<<data<<std::endl;
        
            //close reading
            in.close();
            
        }
        else{
		    std::cout << "Error exctracting Dimensions(Unable to Open File)\n" ;
	    }
       return dimensions;


    }

    //method to read in images and save image sequences to vector.
    FrameSequence ReadImagesFile(std::string filenm,FrameSequence theSequence,std::string dim){
        std::string filename;//stores filename
        filename=filenm;
        int numberOfFrameImages=1; //we storing the whole image without framing it so its 1 in this case
        std::string dimensions=dim; //variable to store image dimensions

        //extracting image dimensions
        std::stringstream ss; 
        ss<<dimensions;
        std::string temp = "";
        ss >> temp; // exctract width
        int column=std::stoi(temp); // convert to int

        ss>>temp;//extract height
        int row=std::stoi(temp); // convert to int

        //declare data array to store data read in
        char* data=new char[column*row];

        //read in the file
        std::ifstream in;
        in.open(filename,std::ios::in|std::ios::out|std::ios::binary);//open file as binary file
    
        if(in.is_open()){
        
            in.seekg(0,std::ios::beg);//Move pointer to beginning of file.
            //skip 4 lines
            for(int i=0;i<4;i++){
                in.ignore(1000,'\n');
            }
            in.read(data,row*column);//Read in
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
            unsigned char **frameImage=new unsigned char*[row];

     
            //check if the frame image points to a nullptr
            if(frameImage!=nullptr){
            
                //for each row
                for(int j=0;j<row;j++){

                    //initialise a pointer to that row
                    frameImage[j]=new unsigned char[column];

                    //for each column in that row
                    for(int k=0;k<column;k++){
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
            /*for(int n = 0; n < numberOfFrameImages; n++)
		{
                for(int r = 0; r < row; r++)
                {
                    delete frameImage[n]; //delete pointer to each row of raw file
                }
			delete frameImage; //delete pointer to each raw file
		}*/

    }
    
    
    return theSequence;
    }
    
      //method to extract frames and save them to vector.
    void FrameSequence::extractFrames(FrameSequence theSequence,int x0,int y0,int x3,int y3,int framec){

        //take in co-ordinates
        int x1=x0; //begin x of pixels
        int y1=y0; //begin y of pixels
        int x2=x3; //end x of pixels
        int y2=y3; //end y of pixels

        int frameCount=framec;

        float gradient=((y2-y1)/(x2-x1));
        std::cout<<gradient<<std::endl;

        int rows=theSequence.getHeight();
        int columns=theSequence.getWidth();
        int numberOfFrameImages=2;

        for(int i=0;i<numberOfFrameImages;i++){
            //initialise 2D pointer to store the 2D frame image points
            unsigned char **thisSequence=new unsigned char*[rows];

            if(thisSequence!=nullptr){
                
                //for each row
                int r=0;
                for(int j=y1;j<y1+rows;j++){
                    //initialise a pointer to that row
                    thisSequence[r]=new unsigned char[columns];

                    //for each column in that row
                    for(int k=x1;k<x1+columns;k++){
                        int c=0;
                        thisSequence[r][c]=theSequence.wholeImage[0][j][k];
                        std::cout<<thisSequence[r][c]<<std::endl;
                        std::cout<<theSequence.wholeImage[0][r][c]<<std::endl;
                        c++;
                    }r++;
                }
        }
        theSequence.imageSequence.push_back(thisSequence);
      
    }


    
    }
}






