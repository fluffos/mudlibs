#include <ansi.h>
void init()
{
	add_action("do_eat",({"eat","fu"}));
}

int do_eat()
{
	object me=this_player();
	if (userp(me))
	{
		tell_object(me,"这是一枚NPC专用的"+query("name")+"，你吃下是没用的。\n");
		return 1;
	}
	if (query("drug_type")=="anti_busy")
	{
		if (me->is_busy())
		{
			me->start_busy(1);
			message_vision("$N服下一"+query("unit")+query("name")+"，行动有灵活起来了。\n",me);
			destruct(this_object());
		}
		return 1;
		
	}
	me->add("eff_"+query("drug_type"),query("effect"));
	me->add(query("drug_type"),query("effect"));
	message_vision("$N服下一"+query("unit")+query("name")+"，看起来起了作用。\n",me);
	destruct(this_object());
	return 1;
}
