#include <ansi.h>
inherit COMBINED_ITEM;
#include "eat.h"
void create()
{
        set_name(HIG"蛇胆川贝"+HIR+"枇杷膏"NOR, ({"shedan gao", "gao"}));
        set_weight(300+random(60));
        set("long", "这是一块蛇胆川贝枇杷膏，对提升体质稍有助益。\n");
        set("unit", "块");
		set("value",20);
		set("effect",7);
		set_amount(1);
		setup();
}


int do_eat(string arg)
{
	int effect=random(query("effect"))+1;
	object me=this_player(),ob=this_object();
	if (!can_eat(ob,arg)) return 0;
	message_vision("$N服下了一"+query("unit")+"$n。\n",me,ob);
	if(query_amount()<=1)
	{
		write("你把剩下的"+name()+"都吃完了。\n");
	}
	add_amount(-1);
	if (!me->query_temp("Remedy_effect/shedan"))
	{
		me->set_temp("Remedy_effect/shedan",1);
		if (me->query("level")>110)
		effect*=2;
		me->add_temp("apply/constitution",effect);
		tell_object(me,"你运转内息，增加了"+chinese_number(effect)+"点"+HIR+"临时"+NOR+"根骨。\n");
	}
	return 1;
}