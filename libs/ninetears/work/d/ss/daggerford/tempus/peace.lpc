inherit"/std/room";
#include "path.h"
 
void setup()
   {set_short("Room of Peace");
    set_long("Hundreds of lit candles fill the periphery of the room, "+
             "their flickering flames echoing off the brass plated walls "+
             "behind them.  A gentle fragrant smoke rises from an "+  
             "earthen crucible surrounded by several padded, meditation "+
             "carpets.  A sense of peace washes over your mind while you "+
             "sit here.\n");
    add_item(({"walls", "wall", "plated walls"}), "The walls are highly "+
             "polished pitted plates of brass.  They reflect the "+ 
             "candlelight, helping create the subdued atmosphere present "+
             "here.\n");
    add_item(({"crucible", "earthen crucible", "tripod"}), "The crucible "+
             "is a thickly walled bowl of fired clay, supported by a "+
             "wooden tripod.  Within the crucible, you see several glowing "+
             "embers, cubical in nature, from which the smoke rises.\n");
    add_item(({"smoke", "ember", "embers"}), "You step forward towards "+
             "the crucible and examine the embers within.  The smoke rises "+
             "in to your nostrils, filling you with an even greater sense "+
             "of peace.  The smoke smells vaguely of jasmine.\n");
    add_item(({"carpet", "carpets"}), "The meditation carpets form a wide "+
             "circle around the crucible, permitting many to find comfort, "+
             "solace, and silence within this room.  Though similar in "+
             "size, each carrys its own unique pattern involving the "+
             "religious symbols of Tempus.\n");
    
    set_light(60);
    
    add_exit("west", ROOM+"temaltar", "door");
    
    modify_exit("east", ({"message", 
             "N$N rises, smiles, and quietly leaves the room.\n"}));
 
   }
 
void init ()
   {::init();
    add_action("nocasting", "cast");
    add_action("nocasting", "ambush");
    add_action("nocasting", "steal");
    add_action("nocasting", "backstab");
    add_action("nocasting", "kill");
    add_action("nocasting", "shout");
    add_action("nocasting", "attack");
   add_property("noguild",1);
   add_property("nocast",1);
  } 
  
int nocasting(string str)
  {write("Strange . . . it is as if some force inside your mind prevents "+
         "you from disturbing the peace of this room.\n");
   return 1;
  }
