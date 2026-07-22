// chard.c
// Modify by Jingxue for XYCQ 6.10.2003

#include <race.h>
#include <skill.h>

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
	int force,mana;
	string race;
	mapping my;

	if( !stringp(race = ob->query("race")) ) 
	{
		race = "人类";
		ob->set("race", "人类");
	}
	switch(race) 
	{
		case "妖魔": MONSTER_RACE->setup_monster(ob);break;
		case "野兽": BEAST_RACE->setup_beast(ob);break;
		default : HUMAN_RACE->setup_human(ob);break;
	}
	my = ob->query_entire_dbase();
	if( !userp(ob) )
	{
		force = ob->query_skill("force")*10;
		mana = ob->query_skill("spells")*10;
		if( ob->query_maxforce()<force )
			my["max_force"] = force;
		if( ob->query_maxmana()<mana )
			my["max_mana"] = mana;
		my["force"] = ob->query_maxforce()*2;
		my["mana"] = ob->query_maxmana()*2;	
		my["food"] = ob->max_food_capacity();
		my["water"] = ob->max_water_capacity();
	}
		
	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = ob->query_maxgin();
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = ob->query_maxkee();
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = ob->query_maxsen();

	if( undefinedp(my["gin"]) ) my["gin"] = my["eff_gin"];
	if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
	if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];
	
	if( !userp(ob) )
	{
		if( undefinedp(my["daoxing"]) 
		 || my["daoxing"]>ob->query_max_daoxing() )
			my["daoxing"] = ob->query_max_daoxing();
	}

	if( !ob->query_max_encumbrance() )
//		ob->set_max_encumbrance( my["str"] * 5000 );
		ob->set_max_encumbrance( ob->query_str()*3000 +(int)ob->query_skill("unarmed",1)*200);
	ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, *inv;

	if( victim->is_ghost() ) 
	{
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}
	corpse = new(CORPSE_OB);
	// mon changed name(1) to name(), 5/9/98
	corpse->set("level",victim->query_level());
	corpse->set_name( victim->name() + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long()+ "然而，" + gender_pronoun(victim->query("gender")) + "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set_weight( victim->query_weight()/2 );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));
	return corpse;
}

varargs object make_toulu(object corpse)
{
        object toulu;
 	toulu=new("/d/obj/misc/toulu");
        toulu->set("name",(string)corpse->query("oldname")+"的头颅");
        toulu->set("level",corpse->query("level"));
        toulu->set("gender",corpse->query("gender"));
        toulu->set("age",corpse->query("age"));
        return toulu;
}

varargs object make_wutoucorpse(object corpse)
{
        string name,oldname;
        sscanf(corpse->query("name"),"%s的尸体%*s",oldname);
        corpse->set("oldname",oldname);
        switch(corpse->query("gender"))
        {
        case "男性":
                name="无头男尸";
                break;
        case "女性":
                name="无头女尸";
                break;
        default:
                name="性别不明的尸体";
                break;
        }

        corpse->set("name",name);
        corpse->set("id",({"wutou corpse"}));
        return corpse;
}
