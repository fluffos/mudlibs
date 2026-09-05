#include <ansi.h>
inherit ITEM;
#include "eat.h"
void create()
{
        set_name(HIY"续命八丸"NOR, ({"xuming bawan", "wan"}));
        set_weight(300+random(60));
        set("long", "这是一颗散发着淡淡金色的丹丸，据说有神奇的功效。\n");
        set("unit", "颗");
		set("value",2500);
		setup();
}


int do_eat(string arg)
{
	int effect=random(query("effect"))+1;
	object me=this_player(),ob=this_object();
	if (!can_eat(ob,arg)) return 0;
	if (time()-me->query("Remedy_effect/cd/xuming")<300)
	{
		tell_object(me,"你刚吃过"+ob->query("name")+"不久，药力尚未全部消化。\n");
		return 1;
	}
	me->set("Remedy_effect/cd/xuming",time());
	if (me->query("eff_qi")<me->query("max_qi")*9/10)
		me->set("eff_qi",me->query("max_qi")*9/10);
	if (me->query("eff_jing")<me->query("max_jing")*9/10)
		me->set("eff_jing",me->query("max_jing")*9/10);
	me->set("qi",me->query("eff_qi"));
	me->set("jing",me->query("eff_jing"));
	message_vision("$N服下了一"+ob->query("unit")+"$n。\n",me,ob);
	destruct(ob);
	return 1;
	
}