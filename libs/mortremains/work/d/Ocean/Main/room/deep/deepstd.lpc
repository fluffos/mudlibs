#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    seteuid( getuid() );
    set("author" , "herself");
    set("underwater" , 1);
    set("listen" , "You hear the ocean rumbling around you. \n");
    set("short", "Deep under the sea.");
    set("long" , wrap(
	"You are swimming deep under the sea. Sunlight "+
	"filters down from far above you. It "+
	"dances around through the water making it seem "+
	"like everything is moving. "+
	"South of you is a giant multi-colored coral reef. "+
	"It seems to writhe with life as fish and other "+
	"sea creatures move about it. "
      ) );

    set("light", 1);
    set("item_desc", ([
      "sea#ocean" : "The water is crystal clear and pleasantly warm. \n",
      "water" : "The water is crystal clear and surrounds your body. \n",
      "fish" : "Small fish are swimming around.\n",
      "small fish" : "Small fish are swimming around.\n",
      "coral" : "A huge coral reef.\n",
      "coral reef#reef" : "It is beautiful, and full of life. \n",
      "sea creatures" : "Tiny creatures which inhabit the reef. \n",
    ]));
}

void init() 
{
    add_action("smell", "smell");
    add_action("dive", "dive");
    add_action("swim", "swim");
    add_action("search", "search");
}

/*ACTIONS*/

int smell(string arg) {
    write("You inhale deeply....\nYou convulse in agony as your lungs begin to fill with sea water!\nYou might not want to do that again.\n");
    this_player()->receive_damage((this_player()->query("hit_points") - 1), "poison");
    return 1;
}

int swim(string arg) {
    write("You swim around under the sea.\n");
    return 1;
}

int dive(string arg) {
    /*
    if((int)this_player()->query_level() < 20) {
	    write("You don't want to dive any further at your level.\n");
    } else { if((int)this_player()->query_security_level() <= 19);
	    this_player()->move_player("#/players/gasman/ocean/evil");
    }
    */
    write("You can't dive any deeper.\n");
    return 1;
}

int search(string arg) {
    if(!arg) {
	write("search what?\n");
	return 0;
    }
    if(arg == "coral") {
	write("You cut your hand on the sharp coral!\n");
	this_player()->receive_damage(4,"poison");
    }
    if(arg == "fish") 
	write("The fish squirms out of your hand.\n");
    return 1;
}
string query_min(string dir) {
    if(!dir || dir=="") dir = "somewhere";

    dir = TPN+" swims in from the "+dir+".";
    return dir;
}
string query_mout(string dir) {
    if(dir == "" || dir == 0) dir = "somewhere";
    dir = TPN+" swims "+dir+".";
    return dir;
}
