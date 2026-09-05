#include <ansi.h>

inherit ITEM;
void create()
{	
	set_name("丹丸", ({ "dan wan","wan","dan"}));
	set_weight(50);
	set("long", "这是一粒药丸。\n");
	set("material", "jade");
	set("unit", "粒");
	set("value", 0);
	setup();
}

void init()
{
	add_action("do_eat","eat");
}
int result(object me)
{
	if (!me)
	return 1;
	if (!living(me))
	return 1;
	switch (random(30))
	{
		case 0:
		{
			tell_room(environment(me),me->name()+"突然面如金纸，直挺挺地躺了下去。\n");
            me->receive_damage("qi", 0, "吞下丹丸后");
            me->die();
			break;
		}
		case 1:
		{
			tell_room(environment(me),me->name()+"口吐白沫，晕了过去。\n");
			me->unconcious();
			break;
		}
		case 2:
		{
			tell_object(me,"这丹丸似乎有些功效，你觉得自己的最大内力有所提升。\n");
			me->add("max_neili",1);
			break;
		}
		default:
		{
			tell_object(me,"这丹丸无甚特殊作用，服下却也无碍。\n");
			break;
		}
	}
	me->set_temp("songtasks/yuyao/1/finish",1);
	destruct(this_object());
	return 1;
}
int do_eat()
{
	object me=this_player();
	if (base_name(environment(me))!="/d/hangzhou/palace/yuyao")
	{
		tell_object(me,"你必须在御药房当着提举长官的面吃掉"+this_object()->query("name")+"。\n");
		return 1;
	}
	tell_room(environment(me),me->name()+"把"+this_object()->query("name")+"一口吞了下去。\n",({me}));
	tell_object(me,"你试着把"+this_object()->query("name")+"吞了下去。\n");
	me->set_temp("songtasks/yuyao/try_drug",time());
	this_object()->set("no_show",1);
	this_object()->move("/d/city/hideroom");
	remove_call_out("result");
	call_out("result",2+random(10),me);
	return 1;
}