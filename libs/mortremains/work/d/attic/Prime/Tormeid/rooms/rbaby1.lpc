// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The royal nursery.");
  set("long", @ENDLONG
You stand in the royal nursery, where the King's newborn son resides.
A large golden cradle lies in the center of the room.  Several plush
toys lie strewn about the room haphazardly.  Soft, relaxing music 
can be heard from somewhere up above you, and the walls are covered with
enchanting colors that swirl around playfully, entrancing and entertaining
you.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "south" : ROOMS(rliving1),
  ]) );
  create_door("south", "north", "An ornate gold door.", "closed", "royal_key",
   24 ) ;
  set("item_desc", ([
   "walls" : "Without a doubt some of the best illusions you have ever seen.\nThey feel like normal walls, but the colors are entrancing.\n",
  "cradle" : "It's a large plush cradle, perfect for a baby.\n",
  "toys" : "Nothing that would interest a grown-up like you.\n",
  ]) ) ;
  set("listen", ([
  "default" : "You hear soft, relaxing music coming from.. somewhere in the room.\n",
  "music" : "You decide it must be part of the room's magical enchantments.\n",
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  MON(liw) : 2,
  "baby" : MON(rbaby),
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
