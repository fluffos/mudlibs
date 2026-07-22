// Room: yanbi.c 岩壁

inherit ROOM;

void create()
{
	set("short", "岩壁");
	set("long", @LONG
你的身子紧紧的贴在岩壁上，丝毫不敢离开半分，谷中的寒风不断
侵袭而来，你不禁打了个哆嗦。
LONG);
/*
        set("objects", ([ 
	    __DIR__"obj/shizi" : 1,
        ]));
*/
	set("outdoors", "嵩山");
	setup();
}

void init()
{
	add_action("do_down","pa");
	add_action("do_down","climb");
}

int do_down(string arg)
{
	object me = this_player();
	
	if (!present("song sheng",me))
		return 0;
	if (!arg && arg != "down")
		return notify_fail("你要往哪里爬？\n");
	message_vision("$N顺着绳子继续向下爬去。\n",me);
    me->move(__DIR__"gudi");
	return 1;
}
