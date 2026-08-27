#include "path.h"
inherit "/std/outside";
 
#define XCORD 1
#define YCORD 2
 
void init()
   {::init();
    call_out("first_approach", 0, this_player());
   }
 
void setup()
   {set_short("Somewhere In A Field");
    set_long("A light breeze tickles the scratchy tendrils of golden wheat "+
             "that rise up from the tilled, moist earth beneath your feet, "+
             "giving the false impression of a rolling ocean of amber.  "+
             "Your whereabouts are uncertain, the ripe whips of grain "+
             "masking your position within this massive field.\n\n");
    set_dark_long("It is very unnerving to find yourself standing in "+
             "near total darkness, surrounded on all sides by rustling "+
             "shafts of wheat.  You frequently find yourself spooked "+
             "when a curious tendril, persuaded by the wind, brushes "+
             "against the unprotected back of your neck");
    add_item(({"grain", "wheat", "whips", "tendrils"}), "The wheat climbs "+
             "several inches above your head, making it difficult to see "+
             "much beyond your present location.  Golden colored, and "+
             "topped with a heavy head of chaff, it appears to be almost "+
             "time for harvesting.\n");
    add_item(({"ground", "earth"}), "The ground beneath your earth is "+
             "soft and moist, still broken into weathered clods from the "+
             "plowing at the begining of this season.\n");
 
    set_light(OUTDOOR);
    set_zone("field");
    
    add_exit("north", FIELD+LOCX[XCORD]+LOCY[YCORD-1], "path"); 
    add_exit("south", FIELD+LOCX[XCORD]+LOCY[YCORD+1], "path"); 
    add_exit("east", FIELD+LOCX[XCORD+1]+LOCY[YCORD], "path");
    add_exit("west", FIELD+LOCX[XCORD-1]+LOCY[YCORD], "path");
    
    modify_exit("north", ({"message", 
                "N$N disappears north into the wheat.\n"}));
    modify_exit("south", ({"message", 
                "N$N disappears south into the wheat.\n"}));
    modify_exit("east", ({"message",            
                "N$N disappears east into the wheat.\n"}));
    modify_exit("out", ({"message",
                "N$N disappears west into the wheat.\n"}));   
   }
 
void first_approach(object ob)
   {if(this_object()->query_property("disturbed"))
      tell_object(ob, "It appears that someone has been here recently as "+
            "the wheat is somewhat bruised and droopy.\n\n");
    this_object()->add_timed_property("disturbed", 1, 100);
    return;
   }
