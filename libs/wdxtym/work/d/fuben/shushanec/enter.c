// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "蜀宫");
	set("long", @LONG
这里是蜀山的尽头！蜀山传说中其上有惊险的剑灵，自上次擅入者已是百多年前不见其出。非掌门之人不可擅自入内。
LONG
	);
	set("no_fly",1);
	set("exits", ([
		"north" : __DIR__"room0",
		
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	string fb_id;
	object player;
	object *obs = all_inventory();
	if (userp(me) && dir == "out") {
		me->delete_temp("zxt_again");
		if (fb_id = me->query_temp("fuben_path"))
			FUBEN_D->des_fuben(fb_id, 1);
	}

	return ::valid_leave(me, dir);
}

