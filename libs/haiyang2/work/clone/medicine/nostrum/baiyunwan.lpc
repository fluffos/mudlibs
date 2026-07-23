// baiyunwan.c 白云熊胆丸

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(HIW"白云熊胆丸"NOR, ({"baiyun xiongdanwan", "wan"}));
	set("unit", "粒");
	set("vegetable", 26);
	set("nostrum", 92);
	set("level", 40);
	set("lev", 3+random(3));
	set("value", 1000);
	set("pour_type", "1");
	set("long", "这是一粒白云熊胆丸，雪白透亮。\n");
	setup();
}

int do_eat(string arg)
{
int exp,pot,i;
	object me = this_player();

exp = 888+random(888);
pot = exp/2;

	if(!id(arg)) return notify_fail("你要吃什么？\n");
	if(!present(this_object(), me))
		return notify_fail("你要吃什么？\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

	if ( me->query("eff_jing") >= me->query("max_jing") &&
		me->query("eff_qi") >= me->query("max_qi") &&
		me->query("neili") >= me->query("max_neili"))
	{
		message_vision("$N没必要吃白云熊胆丸。\n",me);
	}
	else
	{
       me->add("combat_exp",exp);
       me->add("potential",pot);
message_vision("$N获得了"+chinese_number(exp)+"点经验,"+chinese_number(pot)+"点潜能!\n", me);
i=1+random(3);
if (random(12)==0 || wizardp(me))
{
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}       
message_vision(HIR"$N获得了"+chinese_number(i)+"点成长上限!\n"NOR, me);
}       
}
		me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("eff_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("eff_qi"));
		me->set("neili",me->query("max_neili"));
		message_vision("$N吃下一粒白云熊胆丸，只觉得周身热乎乎的，十分舒坦。\n",me);
		destruct(this_object());
	}
	return 1;
}
