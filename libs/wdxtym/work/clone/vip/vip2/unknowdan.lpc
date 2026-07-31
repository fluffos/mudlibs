// unknow.c 火红仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "火红仙丹" NOR, ({ "huohong xiandan", "dan", "xiandan" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗圆圆的火红仙丹，据说"ZJURL("cmds:eat huohong xiandan")ZJSIZE(20)"吃"NOR"了能增加先天身法。\n");
		set("spectxt", "80%的几率增加1点先天身法。\n");
		set("value", 500000);
		set("yuanbao", 100);
            set("no_shop",1);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            set("no_get",1);
            //set("no_put",1);
		set("unit", "颗");
		set("only_do_effect", 1);
		set("suit_point",300);
	}
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
		       "。\n", me);
	if (me->query("gift/unknowdan") >= 5)
	{
		message_vision("$N摇摇晃晃的，突然“啪嗒”一下子摔了个跟头。\n", me);
		tell_object(me, "你觉得吃完以后头重脚轻的。\n");
	} else
	if (random(10) >3 && !me->query("special_skill/lucky"))
	{
		tell_object(me, "不过你觉得好像没什么作用。\n");
	      //me->add("gift/unknowdan_fail", 1);
	} else
	{
		tell_object(me, HIM "霎时间你觉得腿骨欲裂，一时疼痛难忍，晕了过去。"NOR"\n");
		me->add("dex", 1);
	      me->add("gift/unknowdan", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用火红仙丹成功，《先天身法》增加了！！！"NOR"\n");
		me->unconcious();
	}

	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }