/*
  files.h
  
  Fuer diverse Defines, nur wichtig fuer die Masterfunktionen
*/

#define DEBUG(x,y) if (find_player("creative")) tell_object(find_player("creative"), "|**"+x+"**|"+y+"\n")
#define PATH "/d/ebene/creative/feldlager/std"
#define CAP capitalize
