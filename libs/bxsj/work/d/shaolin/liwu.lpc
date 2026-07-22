//liwu

#include <ansi.h>
 
inherit ROOM;

void create()
{
	set("short", HIW"里屋"NOR);
	set("long",@LONG
里屋的陈设就更加简单，一把拂尘，一张坐垫，别无它物。一名老僧正在
闭目入定。
LONG
    );
	set("exits",([
		"out"  :    __DIR__"houyuan",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		CLASS_D("shaolin") + "/wumingseng" : 1,
	]));
	set("valid_startroom", 1);
	setup();
}

void init()
{
	add_action("do_sangong", "sangong");
}

int do_sangong()
{
	object me = this_player();
	int i, rmd, ryb;
	
	i = me->query("max_neili");
	rmd = me->query_skill("ranmu-daofa", 1);
	ryb = me->query_skill("riyue-bian", 1);

	if (!me->query_temp("sangong")) return 0;
	
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	
	if ( ! present("wuming laoseng", environment(me)))
		return notify_fail("你师傅不在你身边，独自散功，可能有危险。\n");

	message_vision(HIW"\n无名老僧在$N头顶轻轻的拍了几下，但见$N头顶冒出一股白气，缓缓上升。\n"NOR, me);
	
	switch (me->query_temp("sangong")){
		case "pass_xin":
			me->delete("pass_xin");
			me->set_skill("weituo-chu", rmd);
			me->delete_skill("ranmu-daofa");
			break;
		case "passdu" :
			me->delete("passdu");
			me->set_skill("weituo-chu", ryb);
			me->delete_skill("riyue-bian");
			break;
		default : return notify_fail("噫？有问题，请报告wiz！\n");
	}
	me->add("max_neili", -i/2);
	me->set_skill("buddhism", 180);
	me->set("sl_wtc", 1);
	me->set("no_recover", 1);
	me->delele_temp("sangong");
	message_vision(HIR"\n$N大汗淋漓，脸色极其痛苦，仿佛在经历很大的磨难……\n\n"NOR, me);
	me->unconcious();
	return 1;
}

int valid_leave(object me, string dir)
{
	me->delete_temp("sangong");
	return ::valid_leave(me, dir);
}
