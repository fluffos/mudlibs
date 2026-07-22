// Room: /u/qingyun/jyzj/shanbi.c
// Updated by jpei
// Modify By River@SJ
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", YEL"山壁"NOR);
	set("long", @LONG
陡峭的山壁，全为极为坚硬的岩石，滑不溜脚，稍微不小心就会滑倒。往
西而下是一片翠谷，往东而下是一山沟。
LONG	);
	set("exits", ([
		"westdown" : __DIR__"cuigu",
		"eastdown" : __DIR__"shangou",
	]));
	set("objects",([
              __DIR__"obj/rock1" : 1,
	]));

	set("outdoors", "昆仑翠谷");
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_bind", ({"bind", "baoza", "xugu", "bandage", "heal", "zhi", "yizhi", "zhiliao"}));
}

int do_bind(string arg)
{
	object monkey, plywood1, plywood2, yaocao, thread;
	object me = this_player();
	if (arg == "xiao hou" || arg == "hou" || arg == "monkey") {
            if(!(monkey = present("xiao hou", this_object())))
		return notify_fail("再仔细瞅瞅，这里没有猴子！\n");
            if(me->query_skill("medicine", 1) < 100 )
                return notify_fail("你感到自己医术不够精深，只能摇了摇头。\n");
	    if(!monkey->query("get_wound"))
		return notify_fail("它并没有受伤！\n");
	    if(!monkey->query("rock_moved"))
		return notify_fail("它被压在岩石下面哪！\n");
	    if(!(plywood1 = present("zhi tiao 1", me))
             ||!(plywood2 = present("zhi tiao 2", me)))
		return notify_fail("可惜你手头没有足够的固定断骨的工具。\n");
	    if(!(thread = present("xi si", me)))
		return notify_fail("可惜你手头没有捆扎用的线。\n");
	    if(!(yaocao = present("yao cao", me)))
		return notify_fail("可惜你手头没有草药。\n");
	    destruct(plywood1);
            destruct(plywood2);
	    thread->add_amount(-1);
	    yaocao->add_amount(-1);
	    monkey->delete("get_wound");
	    monkey->delete("rock_moved");
            monkey->set("get_save", 1);
	    me->set_temp("help_monkey", 1);
	    new(__DIR__"obj/xianguo")->move(me);
	    new(__DIR__"obj/xianguo")->move(me);
	    write(HIY"你用两根枝条作为夹板，替小猴子续上断骨，把草药嚼烂了给它敷在伤处。\n"NOR);
	    write(HIY"那猴儿居然也知感恩图报，给你摘了些鲜果来，然后就去寻别的猴子玩耍去了。\n"NOR);
            message_vision("$n给了$N一些鲜果。\n",me,monkey);
	    monkey->random_move();
            return 1;
	}
	return 0;
}
