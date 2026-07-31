// Room: /u/qingyun/jyzj/banshanya.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "半山悬崖");
	set("long", @LONG
你向西爬行，这边的山势十分凶险，直爬了半个时辰也无任何去路了。
LONG	);
	set("no_clean_up", 0);
/*	set("exits",([
	]));*/
	set("outdoors", "kunlun");
	setup();
}

void init()
{
	add_action("do_climb", ({"climb", "pa"}));
}

int do_climb(string arg)
{
	object me = this_player();

	if (arg == "east") {
		message_vision("$N向东面的松树爬去。\n", me);
		me->move(__DIR__"songshu");
		message("vision", me->name() + "从半山悬崖爬了过来，小心翼翼地爬上了松树。\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}