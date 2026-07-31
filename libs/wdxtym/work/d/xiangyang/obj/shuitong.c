// Object: /d/xiangyang/obj/shuitong.c  药王庄水桶
// Date: Feb. 3 2002 by Pound

#include <ansi.h>

inherit ITEM;
string long_desc();

void create()
{
	int water_level;
	set_name("水桶", ({"shui tong", "tong", "bucket"}));
	set_weight(1000);
	if (clonep())
	    set_default_object(__FILE__);
	else 
	{
	    set("water_level", 3);
	    set("long", (: long_desc :));
	    set("unit", "副");
	    set("material", "wood");
	    set("value", 5000);
	    set("no_sell", 1);
	    set("no_get", 1);
	    set("yaowang", 1);
	}
}

string long_desc()
{
	string descrp;
	object ob;
	ob = this_object();
	descrp = HIY "这是一副特制的水桶。" NOR;

	if (ob->query("water_level") == 0)
	    descrp += HIC "桶里面一滴水都没有。"NOR"\n";
	else if (ob->query("water_level") <= 1)
		descrp += HIC "里面有一点点水。"NOR"\n";
	else if (ob->query("water_level") <= 3)
		descrp += HIC "里面有半桶水。"NOR"\n";
	else if (ob->query("water_level") <= 4)
		descrp += HIC "里面的水快满了。"NOR"\n";
	else
	    descrp += HIC "里面装满了水。"NOR"\n";
	return descrp;
}

int init()
{
	add_action("do_tiao", "carry");
	add_action("do_tiao", "tiao");
	add_action("do_fang", "putdown");
	add_action("do_fang", "fang");
}

int do_tiao(string arg)
{
	object me, ob;
	me = this_player();
	ob = present("shui tong", environment(me));

	if (! arg || (arg != "shui tong" && arg != "tong" && arg != "bucket"))
	    return notify_fail("你要挑什么？\n");
	if (! ob)
	    return notify_fail("这里附近没有这样东西。\n");
	if (me->is_busy())
	    return notify_fail("你正忙着呢！\n");
	if (! wizardp(me) && me->query("family/family_name") != "关外胡家")
	    return notify_fail("药王传人家里的水桶还是少碰为好。\n");

	message_vision(HIR "$N" HIR "气聚丹田，弯下腰双臂用力，将水桶提了起来。"NOR"\n", me);
	me->receive_damage("jing", 33 + random(5));
	ob->move(me);
	me->start_busy(1 + random(2));
	return 1;
}

int do_fang(string arg)
{
	object me, ob;
	me = this_player();
	ob = present("shui tong", me);

	if (! arg || (arg != "shui tong" && arg != "tong" && arg != "bucket"))   
	    return notify_fail("你要放下什么？\n");
	if (! ob)
	    return notify_fail("你并没有挑着任何东西。\n");
	if (me->is_busy())
	    return notify_fail("你正忙着呢! \n");

	message_vision(HIB "$N" HIB "把水桶轻轻放在了地上。"NOR"\n", me);
	me->receive_damage("qi", (20 + random(10)));
	ob->move(environment(me));
	me->start_busy(1);
	return 1;
}