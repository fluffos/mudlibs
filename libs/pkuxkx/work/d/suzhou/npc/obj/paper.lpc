//情报
//created by zine 30 SEP 2010

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"情报"NOR, ({ "qing bao", "qingbao", "info" }));
	set_weight(14000);
	if( clonep() )
                set_default_object(__FILE__);
    else
		{
			set("long", "这是一叠情报，你可以翻看查阅(fan)。\n");
			set("material", "paper");
			set("unit", "叠");
			set("value", 1);
		}
	setup();
}

void init()
{
	add_action("do_read", ({ "fan", "read"}));
	add_action("do_drop",({ "drop"}));
	call_out("dest",120);
}

int dest()
{
	tell_object(environment(),WHT"这叠情报上的字迹越来越淡，最后所有字迹竟完全消失。\n"NOR);
	destruct(this_object());
	return 1;
}

int do_read()
{
	object me = this_player();
	if(!present("qing bao", me))
	{
		return notify_fail("你要撕什么东西？\n");
	}
    else 
	{
		tell_object(me,HIW"你开始阅读各路反清人马的兵力分布，眼睛不由亮了起来。\n"NOR);
		tell_object(me,HIW"也许把它卖给清廷，会得到一大笔奖赏。\n"NOR);
		tell_object(me,HIW"即使你不直接把它送给清廷。。。\n"NOR);
		set("value", 1000000+random(500000));
		me->set_temp("zhusan/toukui",1);
	}
   return 1; 
}

int do_drop(string arg)
{
	if (!arg)
	{
		return 1;
	}
	if (arg=="xin wu"||arg=="xiao dao")
	{
		tell_object(environment(),"此等宝物，丢弃岂不可惜？\n");
		return 1;
	}
}


