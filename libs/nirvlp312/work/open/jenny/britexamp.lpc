inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the buzzing of traffic."+NORM+"\n");
     set_smell(""+BOLD+"You gag at the smell of exhaust fumes."+NORM+"\n");
short_desc=("A mean Chicago street.");
long_desc=
"You are on a busy street in Chicago.  Traffic is starting to\n"+
"get heavier to the east.  There must be something of interest\n"+
"out that way.  Cars are driving recklessly all around you.\n"+
"This is Chicago traffic at its worst.\n";
items = ({
"cars","All of these cars are nicer than Al Bundy's dodge",
"street","A busy, pothole infested Chicago street",
});
dest_dir = ({
"/players/jenny/bundy/rooms/4e","west",
 "/players/jenny/bundy/rooms/6e","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
exit() { if(this_player())
this_player()->clear_fight_area(); }
