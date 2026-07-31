// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", "黑风寨");
	set("long", @LONG
这里是一处隐藏得极好山寨，你无意之间闯了进来。
LONG
	);
	set("exits", ([
		"north" : __DIR__"room1",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	string fb_id;
	
	if (userp(me) && dir == "out") {
		if (fb_id = me->query_temp("fuben_path"))
			FUBEN_D->des_fuben(fb_id, 1);
                  //return 0;
	}
	return ::valid_leave(me, dir);
}

