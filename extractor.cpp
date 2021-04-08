#include "extractor.h"


int main(int argc, char* argv[] )
{
    std::string filename;//stores filename
    int width;//width of frames;
    int height;//height of frames;

    int x1; //begin x of pixels
    int y1; //begin y of pixels
    int x2; //end x of pixels
    int y2; //end y of pixels

    std::string instruction;
    std::string filestart;




    //check argument inputs
    if(argc == 1){
		filename = "sloan_image.pgm";
	}
	

    if(argc>1){
        filename = argv[1];
        std::string argumenta(argv[2]);
        std::string argumentb(argv[7]);
        std::string argumentc(argv[5]);
        std::string argumentd(argv[10]);


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
            instruction=argv[11];
            filestart=argv[12];


        }

    }
    std::cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<width<<" "<<height<<" "<<instruction<<" "<<filestart<<"end"<<std::endl;

    



     //initialise FramseSequence class to store vector.
    MHLPET015::FrameSequence theSequence;
    theSequence=MHLPET015::ReadImagesFile(filename,theSequence);
    
    
    int rows=theSequence.getHeight();
    int columns=theSequence.getWidth();
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



