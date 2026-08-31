#include <discastle.h>
inherit VAULT;
void create()
{
        ::create();
        set_properties
        (
                (["light" : 2, "night light" : 2, "inside" : 1])
        );
        set_short("Mad Cow Tavern.");
        set_day_long
        (
                "A rich, plush, blue rug makes up the entrance to the room. Sunlight shines through "
                "windows and stretches across the floor.  The door closes softly with a click and "
                "the way to the bedroom is laid bare."
        );
	    set_night_long
	    (
	    	"A single, solitary candle flickers upon being disturbed by the air that flows through "
	    	"the open door, casting shadows through out the room.  A rug can barely be made out and "
	    	"the way to the bedroom is faintly visable"
	    );
	    if (query_night())
	    {
	    	set_listen("default", "Light snoring can be heard");
	    }
	    else
	    {
	    	set_listen("default", "Birds chirping can be faintly heard");
	    }
	    set_items
        (
                ([
                        "rug" : "It's to heavy to take, but it looks nice",
                        "windows" : "It's a window alright",
                        "door" : "Good quailty oak",
                        "bedroom" : "The place to go once a room has been rented"
                ])
        );
        set_exits
        (([
                "out" : ROOMS"innforfl2",
        		"bedroom" : ROOMS"bedforflwa"
        ]));
set_door("door", ROOMS"innforfl2", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innforfl2"->set_open("door", 0);
//ROOMS"innforfl2"->set_locked("door", 1);
}
