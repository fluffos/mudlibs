// Room: /d/fengtian/quest3.c

inherit ROOM;

private int ok;

void create()
{
	set("short", "土山洞");
	set("long", @LONG
这是一个黑漆漆的小土洞，洞壁上插着一只火把。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"quest2",
  "north" : __DIR__"quest4",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north")
	{
		if(!ok)
			return notify_fail("突然洞壁上飞出几把飞刀擦身而过，阻住了你的去路。\n");
	}

	call_out("do_refresh",1);
	return ::valid_leave(me,dir);
}

private void do_refresh()
{
	ok = 0;
	set("exits/out",__DIR__"quest2");
}

void do_check()
{
	call_out("do_count",1);
}

private void do_count()
{
	object *obs;

	obs = all_inventory(this_object());
	foreach(object ob in obs)
		if(ob->is_rain_quest())
			return;

	ok = 1;
}
