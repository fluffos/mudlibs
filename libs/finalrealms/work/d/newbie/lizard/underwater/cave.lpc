inherit "/std/room";
#include "path.h"
void setup(){
    set_light(60);
    set_short("Realm of the Lizard:  Big Cave");
    set_long("\nRealm of the Lizard:  Big Cave\n\n"
      "     This is a cave that you have entered upon leaving the"
      " underwater tunnel.  This cave is rather spacious.  Outside"
      " the cave appears to be a swamp.  It looks like you might"
      " be right at home in a swamp.\n");
    add_exit("down", UWATER+"uw13", "path");
    add_exit("east", "/d/ss/new_swamp/village/swville1", "path");
    modify_exit("east", ({"function","go_east"}) );

}

int go_east()
{
    int i;
    if(this_player()->query_level() < 5)
    {
	notify_fail("Your not experienced enough to leave yet.\n");
	return 0;
    }
    else
    {
	object *it;
	write("As you head to the east you drop your Amulet of K'Laktaar"
	  " down in amongst a bunch of rocks.  There is no way to get"
	  " it back.\n");
	this_player()->add_property("LIZARD_DONE", 1);
	while( sizeof(it = find_match("amulet",this_player()))) it[0]->dest_me();
	  return 1;
      }
	return 1;
    }
