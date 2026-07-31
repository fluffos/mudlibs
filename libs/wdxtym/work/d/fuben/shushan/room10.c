// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIW"蜀山"HIY"之巅"NOR);
	set("long", @LONG
这里是蜀山之巅。
LONG
	);
	set("exits", ([
		"up" : __DIR__"room20",
	]));
	set("objects", ([
		__DIR__"npc/a1": 4,
	    __DIR__"npc/a2": 4,	
		__DIR__"npc/a3": 4,
		__DIR__"npc/a4": 4,
		__DIR__"npc/a5": 4,
	    __DIR__"npc/a6": 4,
	    __DIR__"npc/a7": 4,
		__DIR__"npc/a8": 4,
		]));
	setup();
}
int valid_leave(object me, string dir)
{
	object oba, obb, obc;
	object player;
	object *team = me->query_team();
	object *obs = all_inventory();
	
	oba = present("a1"||"a2"||"a3"||"a4"||"a5"||"a6"||"a7"||"a8",environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba && dir == "up") {
				oba->kill_ob(player);
				player->kill_ob(oba);
				return notify_fail(oba->name()+"故尝无欲，以观奇妙！\n");
			}
		}
	}
	return ::valid_leave(me, dir);
}
