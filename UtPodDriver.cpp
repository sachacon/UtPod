// final driver for UtPod that will be turned in 
#include <iostream>
#include "song.h"
// #include "UtPod.h"
using namespace std;

int main(){
    cout << "Hello World" << endl;
    // Song class creation is working 
    // get instance variable methods are working
    // set instance variable methods are working 
    // == class operator is working 

    // Test song class implementation
    Song s1("AAA", "Back In Black", 44);
    cout << s1.getArtist() << "  " << s1.getTitle() << "  " << s1.getSize() << endl;

    Song s2("ACDC", "Back In Black", 44);
    cout << s2.getArtist() << "  " << s2.getTitle() << "  " << s2.getSize() << endl;

    // Test song class operators
    if(s1 < s2){
	cout << "s1 is less than s2" << endl;
    }else{
	cout << "s1 is not less than s2" << endl;
    }

}

