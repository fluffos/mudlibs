#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("货物",({"huo wu","huowu"}));
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit","箱");
		set("long","这是一箱必须运送到指定地点的货物。\n到达目的地后请使用交货(jiaohuo)指令，以便完成交货。\n");
	}
	setup();
}

void init()
{
	add_action("do_jiaohuo","jiaohuo");
}

int do_jiaohuo()
{
	object room;
	object me;
	me=this_player();
	if(!living(me))	return 0;
	if( environment()!=me)	return 0;
	if(undefinedp(me->query("oldsix_quest")))
		return notify_fail("你并没有领取任何任务。\n");
	if(me->query("oldsix_quest/type")!=3)
		return notify_fail("你并没有领取送货的任务。\n");
	if(! (int)query("start"))
		return notify_fail("你身上带的这个货物已经失效！\n");
	if(me->query("oldsix_quest/start")!=query("start"))
		return notify_fail("你这次送的不是这箱货物！\n");
	room=environment(me);
	if(base_name(room)==me->query("oldsix_quest/id")
	&& room->query("short")==me->query("oldsix_quest/name"))       {
		me->set("oldsix_quest/over",1);
		write("你的送货任务已经完成，快回去交差吧。\n");
		destruct(this_object());
		return 1;
	}
	else	{
		return notify_fail("这箱货物不是送到这儿来的！\n");
	}
}

	
	

