// final driver for UtPod that will be turned in 
#include <iostream>
#include "song.h"
#include "UtPod.h"
using namespace std;

int main(){
    UtPod tPod(200);
    Song s1("A", "T", 12);
    Song s2("A", "T", 14);
    Song s3("A", "T", 7);
    Song s4("A", "T", 9);
    Song s5("A", "T", 5);
    tPod.addSong(s1);
    tPod.addSong(s2);
    tPod.addSong(s3);
    tPod.addSong(s4);
    tPod.addSong(s5);
    tPod.showSongList();
    tPod.sortSongList();
    cout << endl;
    tPod.showSongList();
   	
}

