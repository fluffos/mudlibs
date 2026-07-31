// qiao.c

#include <ansi.h>


inherit ITEM;

private int have_sword;

void create()
{
	set_name(RED "惊鸿剑鞘" NOR, ({ "jian qiao" }) );
	set_weight(10000);
	set_max_encumbrance(15000);
	set("valid_number",1);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "这是一把宽大厚重的剑鞘，通体泛着乌
光，上面刻着密密麻麻的小字，仔细看
好象都是梵文。\n");

		set("value", 200);
		set("material", "blacksteel");
        }

        setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_ba","ba");
	add_action("do_shou","sh");
	add_action("do_put","put");
	add_action("do_get","get");
}

int do_ba(string arg)
{
	object weapon,me = this_player();

	if(!arg || arg == "" )
		return notify_fail("你要拔什么？\n");

	if(!arg || arg == "")
		return notify_fail("你要拔什么？");

	if(!have_sword)
		return notify_fail("剑鞘里没有剑。\n");

	weapon = present(arg, this_object());
	if(!weapon)
		return notify_fail("你要拔什么？\n");

	weapon->move(me);

	have_sword = 0;
	message_vision("$N从剑鞘里拔出了"+weapon->name()+"\n",me);

	if(me->is_fighting())
		me->start_busy(1);
	return 1;
}

int do_shou(string arg)
{
	object me,target,weapon;

	me = this_player();

	if(me->is_busy())
		return notify_fail("你正在忙");

	if(!arg || arg == "")
		return notify_fail("你要收谁手里拿的宝剑？\n");

	if(have_sword)
		return notify_fail("剑鞘里已经有宝剑了。\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("你要收谁手里拿的宝剑？\n");

	if(!target->is_character() || target->is_corpse())
		return notify_fail("你要收谁手里拿的宝剑？\n");

	if( target == me )
		return notify_fail("你不能收自己的兵器。\n");

	weapon = target->query_temp("weapon");
	if(!weapon || (string)weapon->query("skill_type") != "sword")
		return notify_fail("对方的手没有拿宝剑。\n");
/*
	if((int)me->query("str") < (int)target->query("str"))
		return notify_fail("你的臂力不够。\n");
*/
	message_vision(sprintf(HIY"\n$N拿玄铁剑鞘向$n一晃，\n$n只觉得手一松，%s脱手而出飞向$N，“喀嚓”一声插进了玄铁剑鞘。\n\n" NOR,
		weapon->name()),me,target);

	weapon->move(this_object());
	have_sword = 1;
	me->start_busy(2);
	target->kill_ob(me);
	me->fight_ob(target);
	return 1;
}

int do_get(string arg)
{
	string what;

	if(!arg)
		return 0;

	if(sscanf(arg, "%s from %s", arg, what)==2)
	{
		if(id(what))
		{
			write("那不是容器。\n");
			return 1;
		}
		return 0;
	}
	return 0;
}

int do_put(string arg)
{
	string what;

	if(!arg) return 0;

	if(sscanf(arg, "%s in %s", arg, what)==2)
	{
		if(id(what))
		{
			write("那不是容器。\n");
			return 1;
		}
		return 0;
	}
	return 0;
}
