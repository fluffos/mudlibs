
#include "../defs.h"
inherit ROOM; 
object lion;
void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In an Animal's cage.");
  
set("long", @ENDLONG
This room is completely barren.  The floor is covered in green feces.
Whatever creature lives here, either doesn't consume anything, or completely
devours whatever meal it gets.
ENDLONG
);

  set("item_desc", ([
    "corpses" : "Tearing wounds can be seen on the corpses.\n",
    "maggots" : "The white insects could feast on these bodies their entire lives 
and have plenty left over for the generations to come .\n",
 ]) );
  set("smell", ([ "default" : "Your stomach rolls from the intense stench that
pervades the entire cage.\n",
]) );

  set("exits", ([
   "out" : ROOMS(cage4),
]) );
  ::create();  
}
void reset(){
  if(!lion){
    lion=clone_object(MON(blion));
    lion->move(TO);
   }
::reset();
}