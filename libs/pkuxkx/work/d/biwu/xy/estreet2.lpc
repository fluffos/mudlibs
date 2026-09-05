// Room: /clone/misc/estreet2.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 26 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "参天古树");
	set("long", @LONG
这里是襄阳城东的一棵老树，你可以攀(pan)上去一探究竟。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"eaststreet",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_pan", ({ "pan", "pa" }));
	::init();
}

int do_pan(string arg)
{
	object me;
	me = this_player();
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
	message_vision("$N手脚并用，向树上爬去。\n", me);
	me->move(__DIR__"tree");
	me->add_busy(random(3));
    tell_room(environment(me), me->name() + "从树下爬了上来。\n", ({ me }));
	return 1;
}