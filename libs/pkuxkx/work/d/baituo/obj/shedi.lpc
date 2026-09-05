#include <ansi.h>

inherit ITEM;
void create()
{
        set_name( HIG"蛇笛"NOR, ({ "she di", "shedi", "di" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个用青竹削制而成的短小笛子。\n");
                set("value", 0);
                set("material", "iron");
              }
}

void init()
{
	add_action( "do_blow", "blow" );
}

int do_blow(string arg)
{
	object ob, me = this_player();
	int pflv;
	if (!id(arg))
		return notify_fail("你要吹什么？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢，腾不出手来掏蛇笛。\n");
	if (me->query("family/family_name") != "白驼山")
		return notify_fail("你不是白驼山弟子，笛子吹得再响也没有什么用。\n");
	
	pflv = (int)me->query("purefamily/level");
	if ( pflv <=0 || me->query("purefamily/family_name") != "白驼山" ) 
		return notify_fail("你从怀里取出蛇笛，但是吹了半天也没什么反应。\n");

	
	if (ob = present("she zhen", environment(me)) && ob->query("baituo_shezhen"))
	{
		if (ob->query("owner") == me)
			return notify_fail("你已经召来蛇阵了，还要吹什么？\n");
		message_vision(CYN"$N从怀里取出一个碧绿色的蛇笛，放在嘴边吹了起来。\n"NOR, me);
		if (ob->query("exp") > me->query_skill("zhaosheshu", 1))
		{
			tell_object(me, HIY"你吹了半天，见蛇阵毫无动静，只好无奈地放弃了。\n"NOR);
			me->start_busy(1);
		}
		else
		{
			ob->set("owner", me);
			ob->set("exp", me->query_skill("zhaosheshu",1));
			ob->set_temp("seeme", me->query("id"));
			if ((int)ob->query("times")<3)
				ob->set("times", 0);
			else
				ob->add("times", -1-random(3));
			message_vision(HIG"远处传来蛇奴的木笛竹鞭回应，蛇群齐齐地顿了一下，接着四处穿插游走，变换了阵势。\n"NOR, me);
		}
	}
	else
	{
		if (time()-(int)me->query_temp("last_shedi")<180)
			return notify_fail("你才刚召唤过蛇阵不久，还是过一会儿再试吧。\n");
		ob = new(__DIR__"shezhen");
		if (ob)
		{
			if (environment(me)->query("outdoors"))
				message_vision(CYN"$N从怀里取出一个碧绿色的蛇笛，放在嘴边吹了起来。\n"
					+HIM"远处传来蛇奴的木笛竹鞭回应声，紧接着四周嗤嗤嘘嘘之声大盛，漫山遍野的毒蛇如潮水般蜂拥而至。\n"NOR, me);
			else
				message_vision(CYN"$N从怀里取出一个碧绿色的蛇笛，放在嘴边吹了起来。\n"
					+HIM"远处传来蛇奴的木笛竹鞭回应声，紧接着四周嗤嗤嘘嘘之声大盛，毒蛇纷纷自屋角缝隙里钻了进来，潮水般蜂拥而至。\n"NOR, me);
			ob->set("owner", me);
			ob->set("exp", me->query_skill("zhaosheshu",1));
			ob->set_temp("seeme", me->query("id"));
			ob->move(environment(me));	
			ob->show_effect();
			ob->check_user();
		}
	}
	me->set_temp("last_shedi", time());
	return 1;
}

