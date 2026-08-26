#include "../defs.h"
object ledge;
void init(){
add_action("search", "search");
}
inherit ROOM; 
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The Mayors office.");
  
set("long", @ENDLONG
This is a huge office in that it is perhaps fifteen feet wide by twelve 
feet long.  Strangely the room is quite empty other than a large, black oak 
desk and a red leather chair.  The desk is complete devoid of detail other 
than the  nameplate that resides there.
ENDLONG
);

  set("item_desc", ([ 
      "nameplate" : @EndText
It reads:
         Keldrin Arteerie, Lord High Mayor of Rithik
EndText,
       "desk" : "This desk has been kept very clean and has nothing resting on the
top of it.\n",
]) );
set("objects", ([ MON(kel) : 1, ]));
set("smell", ([
    "default" : "The smoke smells like a very rare tobacco.\n", 
  ]) );
  set("exits", ([
     "south" :  ROOMS(hallway),
    ]) );
  ::create();  
}


int search(string what)
{
        
        if(what != "desk" && what != "room") return 0;
        if(present("mayor", TO))
        {
          write("The Mayor doesn't let you near the desk.\n");
          return 1;
        }
        write("It appears you have found an important ledger in the desk\n");
        ledge = clone_object(OBJ(ledge));
        ledge->move(TP);
        return 1;
}

