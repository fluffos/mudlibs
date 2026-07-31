// Room: /d/heifeng/houshan.c

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里是黑风山的后山，右面是陡峭的山壁，向左面看去是万
丈悬崖，加上强劲的山风，让人觉得摇摇欲坠，看样子还是赶紧
离开这里为好。
LONG
	);

	set("outdoors","heifeng");

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xiaolu4",
]));

	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player();

	if(!arg || arg != "up")
		return 0;

	if(me->query_skill("dodge") < 150)
		return notify_fail("你顺着山壁奋力向上爬了几下，看看实在无处着手，又跳了下来。\n");

	write("你攀着山壁奋力向山爬去。\n");
	me->start_busy(2);
	call_out("do_up",2,me);
	return 1;
}

void do_up(object me)
{
	tell_object(me,"你总算爬了上来。\n");
	me->receive_damage("qi",60);
	me->move(__DIR__"shanding");
}
