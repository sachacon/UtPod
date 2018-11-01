// final driver for UtPod that will be turned in 
#include <iostream>
#include <fstream>
#include <string>
#include "song.h"
#include "UtPod.h"
using namespace std;

int main(int argc, char *argv[]){
    if(argc != 2){
	cout << "Incorrect amount of inputs" << endl;
	return(0);
    }
    string fileName;
    fileName = argv[1];

    cout << endl << "Testing UtPod constructors and getTotalMemory() ... " << endl;
    UtPod tPod1; 
    UtPod tPod2(-1);
    UtPod tPod3(0);
    UtPod tPod4(1000);
    UtPod tPod5(400);
    cout << "UtPod tPod1 - size = " << tPod1.getTotalMemory() << " MB" << endl
	 << "UtPod tPod2(-1) - size = " << tPod2.getTotalMemory() << " MB" << endl
	 << "UtPod tPod3(0) - size = " << tPod3.getTotalMemory() << " MB" << endl
	 << "UtPod tPod4(1000) - size = " << tPod4.getTotalMemory() << " MB" << endl
	 << "UtPod tPod5(400) - size = " << tPod5.getTotalMemory() << " MB" << endl << endl;     

    UtPod tPod;
    ifstream inFile;
    inFile.open(fileName.c_str());
    
    int result = 0, i = 0;
    string artist;
    string title;
    int size;    

    cout << "Testing addSong() , adding 10 songs, printing result ... " << endl;
    inFile >> artist;
    Song s;
    while (inFile) {
	inFile >> title;
 	inFile >> size;
	s.setArtist(artist);
        s.setTitle(title);
	s.setSize(size);
	result = tPod.addSong(s);
	cout << "result = " << result << endl;
	inFile >> artist;	
    }   
    inFile.close(); 
    inFile.clear();
    cout << endl << "Testing getRemaining Memory ... " << endl << "Remaining Memory - " << tPod.getRemainingMemory()
	 << " MB" << endl << endl;
    Song s2("too large", "too large", 500);
    result = tPod.addSong(s2);
    cout << "Adding a song with size greater than remaining memory ..." << endl << "result = " 
	 << result << endl; 

    cout << endl << "Testing showSongList() " << endl;   
    tPod.showSongList();
    // sort list and show list again
    tPod.sortSongList();
    cout << endl << "Testing sortSongList() ... " << endl;
    tPod.showSongList();
    cout << endl << "Testing shuffle() ... " << endl;
    tPod.shuffle();
    tPod.showSongList();
    cout << endl << "Testing shuffle() again ... " << endl;
    tPod.shuffle();
    tPod.showSongList();
    Song s3("Not In UtPod", "Not In UtPod", 10);
    result = tPod.removeSong(s3);
    cout << endl << "Testing removeSong(), removing song not in UtPod ... " << endl << "result = " << result << endl;
    cout << endl << "Testing removeSong(), removing all 10 songs, printing results ... " << endl;
     
    inFile.open(fileName.c_str()); 
    inFile >> artist;
    Song s4;
    while(inFile){
	inFile >> title;
	inFile >> size;
	s4.setArtist(artist);
        s4.setTitle(title);
	s4.setSize(size);
	result = tPod.removeSong(s4);
	cout << "result = " << result << endl;
	inFile >> artist;
    }  
    cout << endl << "Testing getRemainingMemory() - size = " << tPod.getRemainingMemory() << endl;   
    result = tPod.removeSong(s3);
    cout << endl << "Trying to remove song from empty UtPod, printing result ..." << endl
	 << "result = " << result << endl;
 



  
}

