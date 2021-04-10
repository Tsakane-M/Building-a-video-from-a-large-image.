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

    



     //initialise FramseSequence class to store vector.s
    MHLPET015::FrameSequence theSequence;
    theSequence.setFrameSize(width,height);

  



    std::string dimensions=MHLPET015::getImageDimensions(filename);
    theSequence=MHLPET015::ReadImagesFile(filename,theSequence,dimensions);
    theSequence.extractFrames(theSequence,x1,y1,x2,y2,2);

    //compute number of frames
    theSequence.numberOfFrames=1;
    //double x=std::sqrt(4);
    //std::cout<<x<<std::endl;
    
    
    int rows=theSequence.getHeight();
    int columns=theSequence.getWidth();

    writeWholeImage(theSequence,dimensions);

    //write to the file
    //Creating an output stream
    std::ofstream out;

    //Calling the open function to write an object to a file
    out.open("Sequence000.pgm", std::ios::out);

    //for
        unsigned char** printArray=theSequence.wholeImage[0];
        //char ** charArray;
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



        
        
        //test 1
        //std::cout<<theSequence.wholeImage[0][0][20]<<std::endl;
        //std::cout<<theSequence.imageSequence[0][0]<<std::endl;


        

        for(int i=0;i<2;i++){
            for(int j=0;j<rows;j++){
                out.write((char*)(theSequence.wholeImage[i][j]) , columns);
            }


        }
      
        out.close();


    return 0;
}



