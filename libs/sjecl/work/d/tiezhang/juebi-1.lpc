//juebi-1.c 绝壁

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "绝壁");
	set("long", @LONG
你走到这里，发现前面已经没有路了。你面前是一座立陡的山峰，高耸入
云，看不到尽头。石壁上生长着很多松树，疾风吹来，沙沙作响。看来想上峰
顶，只能爬上去了。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"shangu-2",
	]));

	set("no_clean_up", 0);
        set("outdoors", "铁掌山");
	setup();
}

void init()
{
	add_action("do_zhua","zhua");
        add_action("do_climb","climb");
}

int do_zhua(string arg)
{
        object me=this_player();
        if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

        if (arg =="松树"){
		write("你牢牢的抓住石壁上的松树。\n");
		me->set_temp("marks/抓1", 1);
		return 1;
	}
        return notify_fail("你要抓什么？\n");
}

int do_climb(string arg)
{
        object me=this_player();
        if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

        if ((int)me->query_skill("dodge", 1) < 30)
		return notify_fail("你的轻功不够，无法爬上去。\n");
	if (!arg || arg != "up")
		return notify_fail("你要往哪儿爬？\n");
        if (me->query("family/family_name") != "铁掌帮")
		return notify_fail("你非本帮弟子，不能上峰！\n");
        if (me->query_temp("marks/抓1") && arg =="up" ){
		write("你吸了口气，小心的向上爬去。\n");
		message("vision",me->name() + "向上一纵突然不见了。\n", environment(me), ({me}) );
		me->move(__DIR__"juebi-2");
		me->receive_damage("jingli",50);
		message("vision", me->name() + "爬了上来。\n",
		environment(me), ({me}) );
		me->delete_temp("marks/抓1");
		return 1;
	}
	return notify_fail("这里无处攀援，你无法爬上去。\n");
}
