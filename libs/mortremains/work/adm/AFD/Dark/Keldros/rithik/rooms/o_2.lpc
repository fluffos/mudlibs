#include "../defs.h"
inherit ROOM; 
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The Treasurer's Office.");
  
set("long", @ENDLONG
You have entered a small office.  Before you stands a small desk, old
but well made.  The desk is quite cluttered and seemingly without
organization.  A nameplate sits on the desk. 
ENDLONG
);

  set("item_desc", ([ 
      "nameplate" : @EndText
It reads:
         Volskar Vaneusen, Town Treasurer
EndText,
       "desk" : "This desk has suffered many years of use and abuse.\n",
]) );  
set("smell", ([
    "default" : "The smoke smells like a very rare tobacco.\n", 
  ]) );
set("objects", ([ MON(tres) : 1, ]));
  set("exits", ([
     "north" :  ROOMS(hallway),
    ]) );
  ::create();  
}
