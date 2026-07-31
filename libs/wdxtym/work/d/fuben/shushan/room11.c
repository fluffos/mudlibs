// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIY"大殿"NOR);
	set("long", @LONG
这里是蜀山大殿。
LONG
	);
	set("exits", ([
		"north" : __DIR__"room10",
	]));
	set("objects", ([
		__DIR__"npc/a6": 4,
	    __DIR__"npc/a8": 10,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *obs = all_inventory();
	
	oba = present("a6"||"a8",environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && dir == "north") {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"故尝无欲，以观奇妙！\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
