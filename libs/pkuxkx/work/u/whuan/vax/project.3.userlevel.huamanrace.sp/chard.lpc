// chard.c
#define HUMAN_RACE		"/adm/daemons/race/human"
#define BEAST_RACE		"/adm/daemons/race/beast"
#define MONSTER_RACE	"/adm/daemons/race/monster"
#define BIRD_RACE		"/adm/daemons/race/bird"
#define SNAKE_RACE         "/adm/daemons/race/snake"
#define HORSE_RACE 		"/adm/daemons/race/horse"
#define STOCK_RACE "/adm/daemons/race/stock"

void create() 
{
	seteuid(getuid());
}

void setup_char(object ob)
{
	int max_possible_neili;
	string race;
	mapping my;
	
	if( !stringp(race = ob->query("race")) )
	{
		race = "人类";
		ob->set("race", "人类");
	}
	
	switch(race)
	{
		case "人类":
			HUMAN_RACE->setup_human(ob);
			break;
		case "妖魔":
			MONSTER_RACE->setup_monster(ob);
			break;
		case "野兽":
			BEAST_RACE->setup_beast(ob);
			break;
		case "飞禽":
			BIRD_RACE->setup_bird(ob);
			break;
                case "蛇类":
                        SNAKE_RACE->setup_snake(ob);
                        break;
                case "家畜":
                        STOCK_RACE->setup_stock(ob);
                        break;
                case "马类":
                        HORSE_RACE->setup_stock(ob);
                        break;
		default:
			error("Chard: undefined race " + race + ".\n");
	}
	my = ob->query_entire_dbase();
	if( undefinedp(my["pighead"]) ) my["pighead"] = 0;
	if( undefinedp(my["jing"]) ) my["jing"] = my["max_jing"];
	if( undefinedp(my["qi"]) ) my["qi"] = my["max_qi"];
	if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
	if( undefinedp(my["eff_qi"]) || my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];        
	// avoid excess neili
	if (userp(ob)) 
	{
		max_possible_neili = (int)ob->query_skill("force") * 10;
		max_possible_neili += max_possible_neili * SPECIAL_D->query_effect(ob, "neili")/200;
		if (my["max_neili"] > max_possible_neili)
			my["max_neili"] = max_possible_neili;
		if (my["neili"] > my["max_neili"])
			my["neili"] = my["max_neili"];
	}
	
	if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;
	
	if( undefinedp(my["shen"]) ) {
		if (userp(ob))
			my["shen"] = 0;
		else
			my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
	}
	
	if( !ob->query_max_encumbrance() )
		ob->set_max_encumbrance( my["str"] * 5000 );
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
		while(i--)
			inv[i]->move(environment(victim));
		return 0;
	}	
	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long()
		+ "然而，" + gender_pronoun(victim->query("gender")) 
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));
	// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) )
	{
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--)
		{
			if(inv[i]->query("unique"))
			{
				inv[i]->move(killer);
				message_vision("$N自行跃入$n手中。\n",inv[i],killer);
			}
			else if((string)inv[i]->query("equipped")=="worn" )
			{
				inv[i]->move(corpse);
				if( !inv[i]->wear() ) inv[i]->move(environment(victim));
			}
			else
				inv[i]->move(corpse);
		}
	}	
	return corpse;
}
