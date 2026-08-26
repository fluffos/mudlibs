#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "a shady spot.");
 	set_outside("zone", "2");
  set("long", @ENDLONG
You have come apon a nice little shady spot in the woods.
A great big oak tree grows out of the ground, casting a
lovely shadow apon the shoreline.
ENDLONG
   );
  set("item_desc", ([
  "shoreline" : "The shoreline is lush and green.\n",
  "oak" : "You see carved in the trunk of the tree, 'Gendor was here!'\n",
		"tree" : "You see carved in the trunk of the tree, 'Gendor was here!'\n",
		"shadow" : "The shadow of the immense oak invites you to sit and rest a spell.\n",
   ]) );
  set("exits", ([
				"south" : ROOMS(lake3),
  ]) );
set("objects", ([
    MON(fishmunch) : 1,
  ]) );

  ::create();

}
