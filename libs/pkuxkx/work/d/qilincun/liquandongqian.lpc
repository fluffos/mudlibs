// Rewrote by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
    set("short", "沥泉洞前");
    set("long", @LONG
只见半山中一缕流泉，旁边一块大石上边，镌着「沥泉奇品」四个大字，却
是苏东坡的笔迹。那泉上一个石洞(hole)，洞中却伸出一个斗大的蛇头，眼光四
射，口中流出涎来，点点滴滴，滴在水内。
LONG
	);
	set("exits", ([
		"westdown" : __DIR__"shanlu7",
	]));
	set("item_desc", ([
		"hole": "这应该是个自然形成的大溶洞，洞里烟雾缭绕。\n"
	]) );
        set("no_task",1);
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
	if( !me->query_temp("liquan/find_snake") )
		return notify_fail("你是怎么来的？请向巫师报告bug。\n");

	message_vision("$N一弯腰往洞里走了进去。\n", me);
	me->move(__DIR__"liquandong");
	message("vision", me->name() + "从洞外走了进来。\n", environment(me), ({me}) );
	return 1;
}