// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里便是沥泉山上崎岖不平的山路。山路到此已无法前行，一片杂乱的脚印
将你的目光引向不远处一个半人高的洞口(hole)，你试着探头看了看，里面黑乎
乎的一片，什么也看不清。如果山上有土匪，那么这多半就是土匪窝了。
LONG);
	set("outdoors", "沥泉山");
	set("item_desc", ([
		"hole": "你试着探头看了看，里面黑乎乎的一片，什么也看不清。\n"
	]) );
	set("exits", ([
		"southdown" : __DIR__"shanlu9",
	]));

	setup();
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();

	if( arg!="hole" )
		return 0;
	if( !me->query_temp("liquan/ask_wang") )
		return notify_fail("这里面黑乎乎的一片，没事还是不要涉险的好。\n");

	message_vision("$N一弯腰往洞里走了进去。\n", me);
	me->move(__DIR__"dong21");
	message("vision", me->name() + "从洞外走了进来。\n", environment(me), ({me}) );
	return 1;
}