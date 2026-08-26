#include "../defs.h"
inherit ROOM; 
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The Treasurer's Office.");
  
set("long", @ENDLONG
This is a large office.  The walls are lined with potted plants that serve
to quelch most of the ever-present tobacco meandering in from the 
hallway to the east.  A large, dark, oakwood desk stands before you
with a nameplate fastened in the center.  Behind the desk is a green leather 
chair. 
ENDLONG
);

  set("item_desc", ([ 
      "nameplate" : @EndText
It reads:
         Cordius Melan, Councillor to The Mayor.
EndText,
       "desk" : "This desk is well kept and and shined.\n",
       "plants" : "These are common house plants.",
       "walls" : "There are many plants that reside in these walls, by mounted pots.\n",
       "chair" : "This chair has been well-kept and looks quite comfy.\n",
       "twitter" : "You can see small blossoms forming at the tips of it's delicate leaves.\n",
]) );  
set("smell", ([
    "default" : "You can smell a clash of blooming Twitter and burning tobacco.\n",
     "smoke" : "The smoke smells like a very rare tobacco.\n",
     "plants" : "Most of these plants produce no odor except for the Twitter that
is blooming.\n",
     "desk" : "It smells newly waxed.\n",
      "chair" : "It has been treated with leather oil, it smells quite good.\n",
  ]) );
set("objects", ([ MON(coun) : 1, ]));
  set("exits", ([
     "north" :  ROOMS(hallway),
    ]) );
  ::create();  
}
