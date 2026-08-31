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
			"Alright! Roman style! Marble pillars strech up to support the beams that "
			"hold this room together.  Paintings painted in Romanisc style show scenes "
			"that can only be described in the imagination"
        );
	    set_night_long
	    (
	    	"A single, solitary candle flickers upon being disturbed by the air that flows through "
	    	"the open door, casting shadows through out the room. Outlines of paintings and pillars can be seen on the wall "
	    	"although it's to dark to make any of them out.  The strange curves of this room are unsettling to say the least."
	    );
	    if (query_night())
	    {
	    	set_listen("default", "Light snoring can be heard");
	    	set_items
	        (
	                ([
	                        "windows" : "It's a window alright",
	                        "door" : "Good quailty oak",
	                        "bedroom" : "The place to go once a room has been rented",
	                   	    "paintings" : "What are they? It's to dark to see",
				    ])
			);
	    }
	    else
	    {
	    	set_listen("default", "Birds chirping can be faintly heard");
	    	set_items
	        (
	                ([
	                        "windows" : "It's a window alright",
	                        "door" : "Good quailty oak",
	                        "bedroom" : "The place to go once a room has been rented",
	                   	    "paintings" : "It seems to be a Roman cow standing on her head... or is that a yak?",
				    ])
			);
	    }
	    
        set_exits
        (([
                "out" : ROOMS"innforfl3",
                "bedroom" : ROOMS"bedforflea"
        ]));
set_door("door", ROOMS"innforfl3", "out", "keyring");
}
void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
//ROOMS"innforfl3"->set_open("door", 0);
//ROOMS"innforfl3"->set_locked("door", 1);
}
