
 
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Waxer");  

  set("light", 1);


  set("short", "A branch off the main cave.");
  
set("long", @ENDLONG
In this branch off the main cave you notice a great decrease in temperature.  
At first you assume the loss in temperature is attributed to the high ceilings,
but perhaps there is something more.  The walls appear to be very rough 
compared to the other walls in the cave. Stalagtites fall from the ceiling 
and you can make out what appears holes burrowed in the walls. 
Your skin crawls at the thought of what kind of creature made them.  It looks 
like the only way out of here is the same way you came in.
ENDLONG
   );

  set("item_desc", ([
  "walls" : "The walls have been very ruftly craft, it appears as though it 
perhaps was made by nature.\n",
    "hole" : "You can see that these holes were obviously made by a 
cylindrical shaped creature.\n",
    "stalagtites" : "These rocks that are formed in an cylindrical grip the ceiling
appear very unstable.\n" 
   
   ]) );
   set("search_desc", ([
     "walls" : "You find nothing other than the holes.\n",
     "holes" : "You find the hole is coated with a thick, white film, you quickly wipe
your hands to rid them of the disgusting substance.\n",
      "stalagtites" : "They are too high for you to do an effective search.\n",

   ]) );
  set("smell", ([
    "default" : "You smell a metallic tint in the air, coupled with the ever- 
present sweet smell that appears to be diminishing here.\n",
    "wall"  : "Your stomach convulses as you smell what appears to be decaying flesh.\n",
    "holes"  : "You vommit at the disgusting odor of whatever lies in the holes.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear movement coming from the walls around you.\n",
    
    
    
  ]) );
  set("objects", ([
    MON(worm) : 3
  ]) );

  set("exits", ([
    "west" : ROOMS(entrance),
    
  ]) );
  ::create();
}
