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

    //read in the file or printout error message.
    std::ifstream in(filename);
	if(!in)
	{
		std::cout << "Couldn't open file " <<  filename << std::endl;
		return 1;
	}else{
        std::cout << "File: " <<  filename <<" Read Sucessfully!  "<<std::endl;
    }

    




    return 0;
}


