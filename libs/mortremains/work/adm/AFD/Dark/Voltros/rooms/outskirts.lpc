
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Gendor");  

  set("light", 1);


  set("short", "Outskirts of town.");
  
set("long", @ENDLONG
This is the begining of a city.  The buildings of the city are smaller than 
normal, they seem to be built for people about 2 feet high.  Sounds of
celebration can be heard from the north; and a chanting of some
type can be heard to the northwest. 
ENDLONG
   );
  
  set("smell", ([
    "default" : "You smell a pungent odor in the air.\n",
    "odor"  : "It reminds you of a barbeque, with a meat you aren't famliar with.\n",
    
  ]) );
  set("listen", ([
   "default" : "You hear the sounds of a party coming from the north.\n",
    "party" : "It sounds like a garden variety PaRtY !\n",
    "chanting" : "It sounds like some kind of religous ceremony.\n",
    
  ]) );
  
  set("exits", ([
    
    "north" : ROOMS(tsquare),
    "south" : ROOMS(path),
    "west" : ROOMS(wroad),   
  ]) );
  ::create();  
}
