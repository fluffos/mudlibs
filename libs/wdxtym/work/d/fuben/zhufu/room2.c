// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIC"西堂"NOR"");
	set("long", @LONG
这里是朱府的西堂。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"room4",
		"southeast" : __DIR__"room0",
	]));
	set("room_hide", 1);
	set("objects", ([

		__DIR__"npc/huyuan": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("hu wei", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "northeast") ||oba && (dir == "southeast")) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"对你大吼道：找死！兄弟们，并肩子上。\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
#include "/d/fuben/room_fb.h"