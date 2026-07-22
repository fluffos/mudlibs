// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代人材辈出。其
中有不少高僧遗著留存，汇集至今，终成名震天下的少林七十二绝艺。少林精
华，尽集于此。二楼四面开窗，确保通风。中间排列着五排大书架。四周则陈
列矮几，以供阅读。几位老僧手执经卷，正在闭目凝思。
LONG
	);

	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		__DIR__"obj/wuji1" : 1,
		__DIR__"obj/wuji2" : 1,
		__DIR__"obj/wuji3" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if ((ob = present("huizhen zunzhe", this_object())) && living(ob))
		if (dir == "down" ) {
			foreach(ob in deep_inventory(me))
				if (ob->id("shaolin wuji"))
					return notify_fail("慧真说道：武功秘籍只许在藏经阁内研习，不得携带外出！\n");
		}
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
	add_action("do_tui", ({ "tui", "push" }));
} 

int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "chuang" ) return 0;
	if ( !arg ) return 0;
	if (!me->query_temp("marks/推"))
		return notify_fail("你要做什么？\n");

	if (me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");
	if( (int)me->query_skill("dodge",1) < 100 ) {
		message_vision(HIR"$N推开窗户，纵身跃起直奔窗外，无奈轻功不够，摔了下来！\n"NOR, me);
		me->unconcious();
		return 1;     
	}
	message_vision("$N推开窗户，纵身跃出窗户，一眨眼就不见了 。\n", me);
	me->move(__DIR__"xiaojin1");
	tell_room(environment(me), me->name() + "从藏经阁飞身跃了过来。\n", ({ me }));
	me->delete_temp("marks/推");
	return 1;
}

int do_tui(string arg)
{
	object me = this_player();

	if( !arg || arg !=  "chuang") return 0;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	write("你轻轻的将藏经阁的窗户推开。\n");
	me->set_temp("marks/推", 1);
	return 1;
}
