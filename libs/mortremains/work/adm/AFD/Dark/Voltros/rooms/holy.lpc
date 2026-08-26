#include <mudlib.h>

#include "../defs.h"

inherit ROOM;
int punish_me(object ob);
void create() {
  seteuid(getuid());

  set("author", "Gendor");
  set("light", 1);
  set("short", "A bright white room");

set("long", @ENDLONG
This room is VERY bright.  Pure white walls reflect a seemingly
holy light all over the room.  The room is made of white marble,
and it is empty.  There are exits to the north and the south.
ENDLONG
);
  set("item_desc", ([
   "light" : "BRIGHT WHITE LIGHT!\n",
		"marble" : "It's just white marble.\n"
   ]) );
  set("exits", ([
    "south" : ROOMS(ntemple2),
    "north" : ROOMS(out),
  ]) );
  set("healed", ({ }));

  ::create();
}

void init(){ punish_me(TP); }
void reset()
  {
     set("healed", ({ }));
   ::reset();
   }  

int punish_me(object ob)
 {
 if(member_array(TPn, query("healed")) == -1)
 {
 add("healed", ({ TPn }));
 if((int)ob->query_alignment() > 0)
 {
 write("The light seeps into you, warming your soul.\n");
 ob->receive_healing(random(10)+10);
 return 1;
 }
 write("The light seeps into you like needles!\n");
 ob->receive_damage(random(10)+10);
  return 1;
 }
}
