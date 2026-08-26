
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Gendor");  

  set("light", 1);


  set("short", "Near the temple.");
  
set("long", @ENDLONG
Before you stands an enormous temple.   The temple is immense in size and is 
very foreboding.  To the north, a white gravel walkway leads up to a house.
The house has 2 stories, and is quite ornate.  
ENDLONG
   );

  set("item_desc", ([
		"house" : "A large house with a white gravel walkway is to the north.\n",
		"temple" : "The temple is made of large granite blocks.\n",
    "smoke" : "Thick, white smoke is billowing out of a vent on the roof of the temple.\n",
   ]) );
  
  set("smell", ([
    "default" : "A obscene smell assaults your nostrils; it seems to come from the temple.\n",
    "temple"  : "It smells like rotten meat and barbeque.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear nothing but the sounds of joy and laughter coming from town.\n",
    
  ]) );
  
  set("exits", ([
    "north" : ROOMS(mayors),
    "east" : ROOMS(tsquare),
    "west" : ROOMS(temple),
    
    
  ]) );
  ::create();  
}
