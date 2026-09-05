// Zine dec 7 2010 ,长江黄河偶然事件

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_active", "active");
}

void create()
{
	set_name("狂欢卡", ({ "kuanghuan ka","card","ka"}));
	set_weight(500);
	set("value",1);
	set("period",1800);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一张狂欢卡，开启(active)后可进入"+chinese_number(query("period"))+"秒的双倍奖励阶段。\n");
			set("unit", "张");
		}
}

int do_active()
{	
	object me = this_player();
    object ob = this_object();
	if (time()<me->query("double_reward"))
	{
		tell_object(me,"你现在已经开启了双倍奖励条件。\n");
		return 1;
	}
	if (time()-me->query("doublereward")<3600)
	{
		tell_object(me,"你距离上次开启双倍奖励时间太近，无法连续开启。\n");
		return 1;
	}
	me->set("doublereward",time());
	me->set("double_reward",time()+ob->query("period"));
	message_vision(HIW+"$N使用$n，开启了双倍奖励！\n"+NOR,me,ob);
	destruct(ob);
	return 1;
}

