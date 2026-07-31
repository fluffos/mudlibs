// Room: /u/xiaozhen/linlu1.c

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
这里是一片寂静的小树林，一阵微风吹来，树叶沙沙的做响。
脚下是一条黄土小路，路边的地上布满了落叶，看样子这条小路
是经常有人走。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"linlu2",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	if(!arg) return 0;
	if( arg!="后墙" && arg!="door") return 0;
	message_vision("$N用手攀上后墙，一个转身翻了过去。\n", this_player());
	this_player()->move(__DIR__"caizhu3");
	message("vision", this_player()->name() + "从后墙的另一头爬了过来。\n",environment(this_player()), this_player());
	return 1;
}