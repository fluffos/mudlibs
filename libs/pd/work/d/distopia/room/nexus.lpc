#include <std.h>
#include <hermes.h>
inherit ROOM;
object ob;
void create()
{
	::create();
	set_properties
	(
	        ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 3,
                    "night light" : 3,
                    "no steal"    : 1 ]) 
	);
	set_short("The Nexus.");
	set_smell("default", "There is nothing in the air.");
    set_listen("default", "It is silent.");
	set_long
	(
	   "The stone steps appear out of nowhere and strech upwards, "     
		"seemingly endlessly. A long hike upwards to the top is "
		"undertaken and eventually the end is reached. A spherical "
		"dias and a breaktaking view of the surrounding area greets "
		"the few who make it.  A town seems to be just North, while "
		"another forest opens up to the East.  The West looks like another "
		"mountain and the prospect of having to climb once more isn't very "
		"comforting. But where is this? Who made this marble dias? "
		"It hangs in the air but nothing is supporting it... "
	);
	
	set_items
	(
	        ([
	                "forest" : "The forest is tapering off.",
	                "path" : "You feel you're almost there",
	                "light" : "Try as you might, you can't tell where it's coming from.",
	        		"humming" : "Buzzzzz. It rattles your teeth and makes you very uncomfortable."
	        ])
	);
	set_exits
	(([
		
		"southwest" : ROOMS"path5",
    "north" : "/d/distopia/castle/room/castle/npath1",
		"northeast" : ROOMS"lforest1"
	]));
	ob = new(BBOARD);
    ob->set_name("Distopia");
    ob->set_location("/d/distopia/room/nexus");
    ob->set_id( ({ "board", "distopia board" }) );
    ob->set_board_id("Distopia_board");
    ob->set_max_posts(99);
    ob->set_short("Distopia Board");
    ob->set_long("This board just seems to have sprung up out of nowhere. How odd.");
	
}
