// chard.c
// Modified by iszt@pkuxkx, 2007-03-21, enable to max_force when login
// Modified by iszt@pkuxkx, 2007-04-07, changed to show victim->long(1)
// 对最大内力/最大精力的判定采用/feature/attribute.c里面的算法
// by seagate@pkuxkx 2012/03/22

#define HUMAN_RACE		"/adm/daemons/race/human"
#define BEAST_RACE		"/adm/daemons/race/beast"
#define MONSTER_RACE	"/adm/daemons/race/monster"
#define BIRD_RACE		"/adm/daemons/race/bird"
#define SNAKE_RACE         "/adm/daemons/race/snake"
#define HORSE_RACE 		"/adm/daemons/race/horse"
#define STOCK_RACE "/adm/daemons/race/stock"
#define ROBOT_RACE "/adm/daemons/race/robot"

void create() 
{
	seteuid(getuid());
}

void setup_char(object ob)
{
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
		case "机关人":
			ROBOT_RACE->setup_robot(ob);
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
//        if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
  if( undefinedp(my["eff_jing"]) || my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];  
	if( undefinedp(my["eff_qi"]) || my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];        
	// avoid excess neili
	if (userp(ob)) 
	{
/*	    my["hist_max_neili"]=my["max_neili"];
	    my["hist_max_jingli"]=my["max_jingli"];*/
     	my["max_neili"] = ob->query_max_neili();
			my["max_jingli"] = ob->query_max_jingli();

  		if (my["neili"] > my["max_neili"])
	  		my["neili"] = my["max_neili"];
      
		  if (my["jingli"] > my["max_jingli"])
			  my["jingli"] = my["max_jingli"];
	}

	if( undefinedp(my["shen_type"]) ) my["shen_type"] = 0;
        if( undefinedp(my["level"]) ) my["level"] = 0;

	if( undefinedp(my["shen"]) ) {
		if (userp(ob))
			my["shen"] = 0;
		else
			my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
	}
	
	if( !ob->query_max_encumbrance() )
//                ob->set_max_encumbrance( my["str"] * 5000 );
                ob->set_max_encumbrance( my["str"] * 3000 +(int)ob->query_str() * 1000);
                if (ob->query("special_skill/greedy"))
                ob->set_max_encumbrance( my["str"] * 6000 +(int)ob->query_str() * 1500);
	ob->reset_action();
}

varargs object make_corpse(object victim, mixed killer)
{
	int i;
	object corpse, *inv;
	
	if( victim->is_ghost() )
	{
		inv = all_inventory(victim);
		if(objectp(killer))
			inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--)
			inv[i]->move(environment(victim));
		return 0;
	}
	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long(1)
		+ "然而，" + gender_pronoun(victim->query("gender")) 
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set("victim_id", victim->query("id"));
        if (objectp(killer))
	corpse->set("kill_by",killer->query("id"));
	corpse->set("combat_exp",victim->query("combat_exp"));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));
	// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) )
	{
		inv = all_inventory(victim);
		if(objectp(killer))
			inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--)
		{
			if(inv[i]->query("unique"))
			{
				if(objectp(killer))
				{
					inv[i]->move(killer);
					message_vision("$N自行跃入$n手中。\n",inv[i],killer);
				}
				else
					inv[i]->move(corpse);
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

