// Rewrote by iszt@pkuxkx, 2007-02-12

#include <ansi.h>

inherit NPC;

void init()
{
	object ob;

	if( interactive(ob = this_player()))
	{
		remove_call_out("hunting");
		this_object()->set_leader(ob);
		call_out("hunting",1);
	}
}

void hunting()
{
	int i;
	object *ob;
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i]))
			continue;
		if(ob[i]->query("vendetta/authority"))
			continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
}

void die()
{
	object ob, me, corpse;
	string death_msg;

	ob = this_object();
	me = get_damage_origin_object();

	if (!me)
		return;

	death_msg = ob->query("death_msg");
	if(!stringp(death_msg))
		death_msg = "$N一声悲鸣，死去了。\n";
	message_vision(WHT + "\n" + death_msg + NOR, ob, me);

	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		corpse->move(environment(this_object()));
	if((int)me->query("combat_exp") < 1400000)
	{
		message_vision(HIW"$N被奖励了四十点经验和二十点潜能。\n"NOR, me);
		me->add("combat_exp", 40);
		me->add("exp/liquan", 40);
		me->add("potential", 20);
		me->add("potential", 20);
	}
	destruct(ob);

	return;
}