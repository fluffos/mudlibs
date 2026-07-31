// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIC"青石小道"NOR);
	set("long", @LONG
一条幽静的青石道。
LONG
	);
	set("exits", ([
		"south" : __DIR__"room3",
		"north" : __DIR__"room11",
	]));
	set("objects", ([
		__DIR__"npc/a3" : 1,
		__DIR__"npc/a4": 4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *obs = all_inventory();
	
	oba = present("a3"||"a4", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && dir == "north"||oba&& dir == "south") {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"淡淡道：“故尝无欲，以观奇妙！”\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}

