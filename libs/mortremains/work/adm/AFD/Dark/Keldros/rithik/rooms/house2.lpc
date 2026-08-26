

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "The home of a hunter.");
  
set("long", @ENDLONG
Obviously the home of a hunter, this house has trophies that line each wall.
A fireplace burns, filling the house with warmth.  A pot of coffee sits,
warming on the stove.
ENDLONG
);
  set("item_desc", ([
       "trophies" : "These are the heads of different aggressive an non-aggressive
wild animals.\n",
       "fireplace" : "The fireplace is made of brick and clay, it is filled with an
expertly built fire.\n",
        "wood" : "This wood is burning slowly, but radiaiting a good amount of heat.\n",
        "pot" : "This is a steaming pot of coffee, by it's heat you would imagine
that the pot has been sitting for quite some time.\n",
         "coffee" : "This is a steaming pot of coffee, by it's heat you would imagine
that the pot has been sitting for quite some time.\n",
        "walls" : "The walls are adorned with the heads of countless monsters and large
animals",
]) );
  set("smell", ([ 
         "fireplace" : "It smells like burning cedarwood.\n",
         "trophies" : "You can make out the slight odor of embalming fluid.\n",
         "coffee" : "The coffee smells quite old.\n",

]) );
                         

   set("objects", ([
    MON(hunter) : 1,
]) );
  
  set("exits", ([
    "north" : ROOMS(street.c),
   
 

 ]) );
  ::create();  
}
