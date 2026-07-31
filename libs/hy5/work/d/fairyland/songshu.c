// Room: /u/qingyun/jyzj/songshu.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "松树");
	set("long", @LONG
这是一株长于峭壁上的松树。向上而望，不能看见悬崖上之物，刚才从上
面跳下之时义无返顾，但回想起来你自不禁心悸，额头冷汗涔涔而下。再看四
下形势，向上攀援是绝不可能，而脚下也深不见底。如果跌到底下，十之八九
是没有命了的，唯有沿着山壁斜坡，慢慢的爬行出去。西边是雪山上的斜坡，
东面是半山悬崖。
LONG	);
/*	set("exits",([
	]));*/
	set("no_clean_up", 0);
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
		message("vision", me->name() + "向着太阳升起的地方爬去。\n", environment(me), ({me}));
		write("你向东面的雪山斜坡爬去。\n");
		me->move(__DIR__"xiepo1");
		message("vision", me->name() + "从松树那边爬了过来。\n", environment(me), ({me}));
		return 1;
	}
	if (arg == "west") {
		message("vision", me->name() + "向西边爬去。\n", environment(me), ({me}));
		write("你向西面的悬崖爬去。\n");
		me->move(__DIR__"banshanya");
		message("vision", me->name() + "从松树那边爬了过来。\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}