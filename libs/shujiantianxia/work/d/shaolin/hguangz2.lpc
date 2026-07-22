//hguangz2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "后殿广场");
	set("long", @LONG
这里是后殿广场，由大青石板拼成的地面上有几处凹凸的踏痕，似是以
前有高手施展内功所遗留的印记。南面通往大悲殿。
LONG
	);
    set("outdoors", "少林");
    set("no_fight", 1);
	set("exits", ([
		      "east" : __DIR__ "hguangz3",
                      "west" : __DIR__ "hguangz1",
                      "south" : __DIR__ "dabeidia",
        ]));
        set("objects",([
		CLASS_D("shaolin") + "/dao-jue" : 1,
	]));
	set("coor/x",50);
  set("coor/y",330);
   set("coor/z",120);
   setup();
}
