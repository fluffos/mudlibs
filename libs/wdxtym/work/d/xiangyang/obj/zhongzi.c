// Object: /d/xiangyang/obj/zhongzi.c  七心海棠种子
// Date: Feb. 2 2002 by Pound

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIR "花种" NOR, ({"zhongzi", "hua zhong", "zhong"}));
	set_weight(100);
	if (clonep())
	    set_default_object(__FILE__);
	else
	{
	    set("long", "一枚无法确定品种的花种。\n");
	    set("unit", "只");
	    set("value", 0);
	    set("no_give", 1);
	    set("no_steal", 1);
	    set("no_drop", 1);
	    set("food_remaining", 1);
	    set("food_supply", 10);
	}
}

void init()
{
	add_action("do_zhonghua", "zhonghua");
}

int do_zhonghua()
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if (me->query("yaowang/seeded"))
	{
	    tell_object(me, HIR "你的种子已经播种下，现在应该浇花培育了。"NOR"\n");
	    return 1;
	}
	message_vision("$N在窗前一个花盆里挖了挖，把花种种了进去。\n", me);
	tell_object(me, HIR "你的种子已经播种下，现在应该浇花培育了。"NOR"\n");
	me->set("yaowang/seeded", 1);
	destruct(ob);
	me->add("jing", -50);
	return 1;
}
