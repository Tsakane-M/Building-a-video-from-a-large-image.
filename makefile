extractor.exe: extractor_functions.o extractor.o
	g++ extractor_functions.o extractor.o -o extractor.exe -std=c++2a
extractor_functions.o: extractor_functions.cpp
	g++ -c extractor_functions.cpp -o extractor_functions.o -std=c++2a
extractor.o: extractor.cpp
	g++ -c extractor.cpp -o extractor.o -std=c++2a
	mkdir Frames_Dir
	
	
clean:
	rm *.o extractor.exe 
	rm -r Frames_Dir
	
	

run:
	./extractor.exe ../sloan_image.pgm -t 100 300 300 600 -s 640 480 1968 -w none Sequence
