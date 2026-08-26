#include "../defs.h"
inherit DOORS;
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "the mages room.");
  set("long", @ENDLONG
When you walk in, you chuckle to yourself.  This room
is packed full of useless junk!  Jars of things you have
never seen are lying about.  Parchments have been strewn 
about the room.  A nice bed is near the door.
ENDLONG
   );
  set("item_desc", ([
"junk" : "This really is junk!  Beakers, flasks, hoses, and all kinds of stupid equipment is here.\n",
"jars" : "They are packed full of things like blackroot, guano, caterpillar fuzz, and other monstrosities.\n",
"parchments" : "Bah!  they must be worthless....you can't even read them!\n",
"bed" : "It seems to have a matress filled with water!  How queer!\n",
   ]) );
  set("exits", ([
				"east" : ROOMS(boathouse),
  ]) );
set("objects", ([
    MON(mmage) : 1,
  ]) );
create_door("east", "west", "It is a plain wooden door.",
    "locked", "magekey", 25);

  ::create();

}
