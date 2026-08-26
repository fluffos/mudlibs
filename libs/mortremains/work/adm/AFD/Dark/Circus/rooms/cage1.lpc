#include <mudlib.h>
#include "../defs.h"
int done;
inherit ROOM; 
void init()
{
add_action("open", "open"); 
}
void create() {
  seteuid(getuid());   
 set_outside();
  set("author", "Waxer");  
  set("light", 1);
  set("short", "Near some large cages.");
set("long", @ENDLONG
A large cage stands before you.  The smell of wet animal fur turns your 
stomach.
ENDLONG
);
set("item_desc", ([
    "cage" : "The curtains on the cage have been locked down, preventing you
from seeing inside.\n",
    "hay" : "Hay has been used to thicken the mud for easier passage, and to feed
some of the horses.\n",
    "feces" : "This is the excrement of a strange animal.\n",
]) );
set("exits", ([  
    "west" : ROOMS(an_1), 
]) );
set("objects", ([ OBJ(cage) : 1, ]) ); 

::create();


}

int open(string what)
{
        
        if(what != "cage" && what != "door") return 0;
        if(done)
        {
          write("Someone has already done that for you.\n");
          return 1;
        }
        done = 1;
        write("You open the cage door.\n");
        say(TPN+ " opens the cage door.\n");
        add_exit("enter", ROOMS(c_1.c));
         return 1;
}
