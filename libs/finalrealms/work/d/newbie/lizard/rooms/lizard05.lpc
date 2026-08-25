
//Edited by Goodfoot 21-04-95
#include "path.h" 
inherit ROOM+"baseroom"; 

void setup()  { my_setup(); 
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60); 
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     A bit further on the path, and you still have "
	"this feeling of dejavu. The air is a bit dark here, and the "
	"smell of the swamp stings your nostrels. The trees are still "
	"very sparce, but are coming up more frequently now than "
	"before. Some of these strange vines are hanging here.\n");
add_property("no_undead",1);
add_item("path","The path you realize you are actually following "
	"is still a bit hard to see, but it gets better.\n");
add_item("vine","It's just another one of those huge vines seemingly "
	"groving around this parts. It's even a bit larger then the "
	"last one you saw.\n");  
add_exit("southwest",SWAMP +"lizard09","room"); 
add_exit("northwest",SWAMP +"lizard01","room"); 
} 
