#include "path.h"
inherit "/std/room";

object table;

void setup() {
   set_light(50);
   set_short("Gambling house");
   set_long("You are in a small gambling house.  It sure is a shabby place, "+
      "but it's the only one they've got in Daggerford. The smell of old "+
      "beer and spirits is overwhelming. A large table dominates the room.\n");
   add_exit("north", ROOM+"river1", "door");
   add_exit("west", ROOM+"feed", "door");
   add_item(({"stain","stains", "beer", "spirits"}),
      "Like the description says it really smells bad.\n"+
      "The smell seems to come from stains all around the house.\n");
}

 void init()
 {
  ::init();
  add_action("steal","steal");
  }
void reset() 
{
   if (!table) 
      {
      table = clone_object("/d/ss/daggerford/table");
      table->set_read_mess("The scholar was here.  A big thanx to Kilroy for "+
         "putting me on this idea.\n");
      table->move(this_object());
   }
}

void dest_me() {
   if (table && environment(table) == find_object("/room/void"))
      table->dest_me();
   ::dest_me();
}
int steal()
{
write("You cannot steal from people in the gambling house...They would\n"+
	"cut your hands off if they knew what you were doing.\n");
 say((string)this_player()->query_cap_name()+" just tried to steal something\n"+
   "or did steal something from someone in this room.\n");
 return 0;
 }
