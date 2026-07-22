// Room: /d/tianshan/jiashan.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "假山");
	set("long", @LONG
这里是断水桥尽头的假山，四周的野花野草在寒风中依旧长得生气勃勃，
散发着阵阵的独特的味道。你看着看着，越觉得这地方的古怪。但什么原因你
又说不上来。
LONG);
	 set("exits", ([
                "west" : __DIR__"dsqiao",
        ]));       
	set("outdoors", "天山");
	setup();
}

void init()
{
	add_action("do_push", ({"push", "tui"}));             
}

int do_push(string arg)
{
        int str;
        object me;
        str = this_player()->query_str();
        me = this_player();

	if( !arg ) return 0;
	if (arg == "jiashan" ) {
		if(me->query("tonglao/ok")) {
			message_vision("$N蹲下身子，用吃奶的力气把假山挪开,只见下面露出一个大洞。\n", me);
			message_vision("假山下突然露出一个大洞，$N一没留神滚了进去，假山突然又回到了原来的样子。\n", me);
			me->add("neili", -100);
			me->add("jingli", -50);
			me->move(__DIR__"shiku");
			return 1;
		}
		if (str < 21 )
			return notify_fail("你使出了吃奶的力气，可就是推不动假山。\n");
		if (str > 20){  
			message_vision("$N使出全身力气推向假山，可假山好像生了根似的，丝毫不动。\n", me);
			me->add("neili", -300);
			me->add("jingli", -200);
			return 1;
		}       
	}
	return 1;        
}
