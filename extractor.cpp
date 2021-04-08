#include "extractor.h"


int main(int argc, char* argv[] )
{
    std::string filename;//stores filename

    //check argument inputs
    if(argc == 1){
		filename = "sloan_image.pgm";
	}
	else{	
		filename = argv[1];
	}
     //initialise FramseSequence class to store vector.
    MHLPET015::FrameSequence theSequence;
    theSequence.setFrameSize(4130,1968);//4130,1968
    int numberOfFrameImages=1;

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
            in.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        in.read(data,rows*columns);//Read in
        std::cout<<data<<std::endl;
        
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
            theSequence.imageSequence.push_back(frameImage);
         
            }

    }
    
    //write to the file


    //Creating an output stream
    std::ofstream out;

    //Calling the open function to write an object to a file
    out.open("Sequence000.pgm", std::ios::out);

    //for
        unsigned char** printArray=theSequence.imageSequence[0];
        char ** charArray;
        //std::cout<<"variable: "<<printArray[0] <<std::endl;
        //out.write("P5",sizeof("P5"));
        //out.write("200 200",sizeof("200 200"));

        int **intImage=new int*[rows];
        //for each row
            for(int j=0;j<rows;j++){

                //initialise a pointer to that row
                intImage[j]=new int[columns];
                }

        // Convert the unsigned characters to integers
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                (intImage)[i][j]=(int)printArray[i][j];
            }
        }



        out<<"P5"<<std::endl;
        out<<"4130 1968"<<std::endl;
        out<<"255"<<std::endl;
        

        for(int i=0;i<rows;i++){
                 out.write((char*)(printArray[i]) , columns);
                 //std::cout<<printArray[i]<<std::endl;
                 //out.write((char*)data , sizeof(data));

            
        
        }
      
        out.close();


    return 0;
}



