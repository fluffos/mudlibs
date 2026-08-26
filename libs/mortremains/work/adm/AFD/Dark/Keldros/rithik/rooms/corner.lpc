

#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
  set_outside();
  set("author", "Waxer");  

  set("light", 1);


  set("short", "The road turns to the east.");
  
set("long", @ENDLONG
Here, the main road begins to turn to the east, continuing
through the busy portion of Rithik.  Dwarves of all sizes
and appearance hustle from one building to the next.  To
the west you see a two story red brick building with a bell
in a housing on the roof.  To the east the road becomes cobblestone
and the buildings become smaller.  A small lane allows continued
notrthbound travel.
ENDLONG
);

  set("item_desc", ([
    
    "road" : "This road is well trodden, suggesting regular use.\n",
    "building" : "It appears to be a school house, and judging from the fact that
you see no children, you assume that school is in session.\n",
     "bell" : "This bell looks like it would ring quite loudly to call children to school.\n",
     "dwarves" : "These dwarves appear quite content and just plain happy.\n",
     "housing" : "The housing on the top of the schoolhouse looks has a sharp pointed roof
with a wind direction indicator on the tip of it.\n",
     "cobblestone" : "Thick, rounded stones cover the path to the east.\n",
     "lane" : "The lane is quite narrow and is flanked by small homes on both sides.\n"
]) );
   
  

  
  set("exits", ([
    "north" : ROOMS(nlane.c),
    "school" : ROOMS(school.c),
    "south" : ROOMS(inter2.c),
    
    "east" : ROOMS(street.c),
    
  ]) );
  ::create();  
}
