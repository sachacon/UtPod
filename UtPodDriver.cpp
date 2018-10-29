// final driver for UtPod that will be turned in 
#include <iostream>
#include "song.h"
#include "UtPod.h"
using namespace std;

int main(){
    // Song class creation is working 
    // get instance variable methods are working
    // set instance variable methods are working 
    // == class operator is working 
    UtPod tPod(200);
    cout << "Total Memory - " << tPod.getTotalMemory() << endl;
    cout << "Remaining Memory - " << tPod.getRemainingMemory() << endl;
		
    Song s10("Adele", "Skyfall", 10);	
    Song s11("Alicia Keys", "Girl on Fire", 15);
    Song s12("Eminem", "Not Afraid", 20);
    tPod.addSong(s10);
    tPod.addSong(s11);
    tPod.addSong(s12);
    tPod.showSongList(); 
    cout << "Remaining Memory - " << tPod.getRemainingMemory() << endl << endl; 
    
	/*
    // Test song class implementation
    Song s1("Queen", "Bohemian Rhapsody", 22);
    cout << s1.getArtist() << "  " << s1.getTitle() << "  " << s1.getSize() << endl;

    Song s2("ACDC", "Back In Black", 44);
    cout << s2.getArtist() << "  " << s2.getTitle() << "  " << s2.getSize() << endl;

    // Test song class operators
    if(s1 < s2){
	cout << "s1 is less than s2" << endl;
    }else{
	cout << "s1 is not less than s2" << endl;
    }
	*/	
}

