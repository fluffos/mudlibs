//LUCAS 2000-6-18
//Modified by iszt@pkuxkx, 2007-02-17

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIW "冰剑" NOR, ({"bing jian", "icesword", "sword", "jian"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把散发着森森寒气的冰剑，令人望之生寒。\n");
		set("value", 8);
		set("material", "ice");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，只觉一股寒气扑面而来！\n");
		set("unwield_msg", "$N将手中的$n插入腰间，觉得暖和多了。\n");
	}
	init_sword(50);
	setup();
	call_out("melt", 40+random(40));
}  

void melt()
{
	object env;
	object ob = this_object();

	if(!ob)
		return;

	env = environment(ob);

	if( env->is_character() )
	{//a player or a NPC.
		if( (int)env->query_skill("force") < 100 )
		{
			message_vision("$N觉得身上凉凉的，湿湿的，原来是$n化了。\n", env, ob);
			destruct(ob);
			return;
		}
	}
	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "凌霄城" )
		{
			tell_object(env, ob->name()+"终于化成了一滩水，流得到处都是。\n");
			destruct(ob);
			return;
		}
	}
	call_out("melt", 40+random(40));
}