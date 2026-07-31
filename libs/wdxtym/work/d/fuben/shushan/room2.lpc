// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "山前小路");
	set("long", @LONG
这里就是蜀山道的山前小路，十几位蜀山弟子在这里巡逻。
LONG
	);
	set("exits", ([
		"north" : __DIR__"room3",
		"south" : __DIR__"room1",
	]));
	set("room_hide", 1);
	set("objects", ([
		__DIR__"npc/a1": 10,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba;
	object player;
	object *obs = all_inventory();
	
	oba = present("a1", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && (dir == "north")) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"喝到：“何足恋也。“\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
