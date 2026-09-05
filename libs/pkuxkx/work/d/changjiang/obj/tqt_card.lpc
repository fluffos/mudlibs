// Zine dec 7 2010 ,长江黄河偶然事件

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_active", "active");
}

void create()
{
	set_name("铜雀台双倍积分卡", ({ "tongque ka","card","ka"}));
	set_weight(500);
	set("times",2);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一张铜雀台双倍积分卡，开启(active)后完成铜雀台任务将有"+chinese_number(query("times"))+"次的双倍积分。\n");
			set("unit", "张");
		}
}

int do_active()
{	
	object me = this_player();
    object ob = this_object();
	if (me->query("tqt/double_credit"))
	{
		tell_object(me,"你现在已经开启了铜雀台双倍积分。\n");
		return 1;
	}
	me->set("tqt/double_credit",ob->query("times"));
	message_vision(HIW+"$N使用$n，开启了铜雀台双倍积分！\n"+NOR,me,ob);
	destruct(ob);
	return 1;
}

