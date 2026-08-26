#include "../defs.h"

inherit ROOM;   
int ring;
void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "The School's Bell Tower.");
  
set("long", @ENDLONG
This is the schools bell tower.  Around you, the region unfolds.  You see
the forest merging with the town, and as the forest gets thicker, it seems
to grow darker, and more ominous.  A large bell hanges from the center of the roof
apparently unused for quite some time.
ENDLONG
);

  set("item_desc", ([
      "region" : "To the northwest you see the forest carpeting a small chain of mountains.
To the north and east, the forest clings to the town of rithik and other clearings.",
      "forest" : "It's a deep, rich forest of cedar and pine, also some coldfern grows
here.\n",
      "bell" : "This is a school bell, used to summon and dismiss the children of this town.\n Perhaps you should ring it.\n",
]));
   
  set("smell", ([
    "default" : "You smell cedarwood burning from a nearby fireplace.\n", ]) );

  
  set("exits", ([
    "down" :  ROOMS(office),
      ]) );
  ::create();  
}
void init() {
        add_action ("ring", "ring") ;
}

int ring(string str) {
        if (!str=="bell"|| !str ) {
                notify_fail ("Ring what?\n") ;
                return 0 ;
        }
 
  write("You ring the decaying bell and the citizens of the town look up at
you in wonder!\n");
  return 1;
   }

