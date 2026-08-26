#include "../defs.h"
inherit PUB;

void create()
{
    ::create();
  set("short", "Scar's Delight");
    set("light", 1);
set("long", @ENDLONG
Scar's Delight serves as the town pub.  The smell of slow roasted coffee and
hearty ales fills your lungs.  The walls are lined with drawing of warriors.
Each table is unique of its own design.  The dwarves here seem friendly,
but the Ogre bartender is another matter entirely.  After being in the room a
few minutes, it looks like this pub is a meeting place for a fighters' guild.
To the west is the main road leading north-south in Rithik.
ENDLONG);
     set("item_desc", ([
    "bartender" : "Scar is about eleven feet tall and weighs over six hundred
pounds, he is an ogre of world reknown for his brewing abillities.\n",
    "table" : "Tables vary in size and shape.\n",
    "walls" : "The walls serve as a memorial to fallen warriors of Keldros.\n",
   "drawings" : "Each drawing has been made with black chalk, with a name
inscribed under it.\n",

]) );
  set("objects", ([ MON(raider) : 1, ]));
  set("smell", ([
    "default" : "The smell of slow roasted coffee and
hearty ales fill your lungs.\n", ]) );

set("exits", ([ "west" : ROOMS(inter2), ]) );

    set_items(
      ([
      "ale" :
      ({
      "Average Beer",
      "Whew, you don't know if you want to do that again!",
       3, 3, 3, 30, 0
    }),
      "ale" :
      ({
      "Imported Ale",
      "The imported ale creates a warm fuzzy feeling in the back of your skull.",
     15, 15, 4, 150, 0
    }),
      "spritzer" :
      ({
      "Rithik Spritzer",
      "You feel refreshed after drinking the spritzer.",
      5, 5, -2, 75, 0
    }),
      "coffee" :
      ({
      "Beldra's Coffee",
      "Boy, that Beldra can sure make coffee!",
       10, 10, -8, 300, 0
    }),
    "lager" :
    ({ "Stout Lager",
     "The lager nearly burns a hole in your throat in its way down.",
      25, 25, 15, 525, 0
   }) ,
      "delight" :
      ({
      "Spirits Delight",
      "Your spine tingles as energy courses through you.",
      0, 20, 0, 150, 0
    }),
    "soul" :
      ({ "Liquid Soul",
     "You have an intense feeling of being energized.",
      0, 40, 0, 320, 0
  }) ,

    ]));
    set_non_item_msg(
      "Scar says: Order a real drink, will ya?");
}
