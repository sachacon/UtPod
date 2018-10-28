// final driver for UtPod that will be turned in 
#include <iostream>
#include "song.h"
// #include "UtPod.h"
using namespace std;

int main(){
    cout << "Hello World" << endl;

    // Test song class implementation
    Song s1("Queen", "Bohemian Rhapsody", 24);
    cout << s1.getArtist() << endl << s1.getTitle() << endl << s1.getSize() << endl;

    Song s2("ACDC", "Back in Black", 20);
    cout << s2.getArtist() << endl << s2.getTitle() << endl << s2.getSize() << endl;

    s1.setArtist("Not Queen");
    s1.setTitle("Not Bohemian Rhapsody");
    s1.setSize(104);
    cout << s1.getArtist() << endl << s1.getTitle() << endl << s1.getSize() << endl;

    // Test song class operators
    if(s1 == s2){
	cout << "s1 is equal to s2" << endl;
    }else{
	cout << "s1 is not equal to s2" < endl;
    }

    s1.setArtist("ACDC");
    s1.setTitle("Back in Black");
    s1.setSize(20);
    if(s1 == s2){
	cout << "s1 is equal to s2" << endl;
    }

}

