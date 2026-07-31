// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIG"走廊"NOR"");
	set("long", @LONG
这里就是朱府的走廊。
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"room1",
		"northwest" : __DIR__"room2",
		"south" : __DIR__"enter",
	]));
	set("objects", ([
		__DIR__"npc/zhuangding": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("jia ding", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "northeast")||oba && (dir == "northwest")) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"对你大喝道：哪来的乞丐？这里岂是你能随便进出？\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
#include "/d/fuben/room_fb.h"