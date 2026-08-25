inherit "/std/races/standard";
#include "light_defs.inc"
#define CLAWS "/std/races/shadows/claws"
#define CONT_CHANCE 250
#define WOLF_SHADOW "/std/races/shadows/werewolf_sh"
#define WEATHERHAND "/obj/handlers/weather"
#define OLDRACE "old_race"
void change_race(object player);

void setup() {
    set_long("The demonical werewolf was once a normal being, now possessed "
      "by a fearful spirit..\n");
    set_name("werewolf");
    set_light_limits(LIGHT_DROW_LOW, LIGHT_DROW_HIGH);
}

//Needed for healing by the werewolf shadow
int query_enchant() { return 1; }

void set_racial_bonuses()
{
    previous_object()->adjust_bonus_str(10);
    previous_object()->adjust_bonus_dex(30);
    previous_object()->adjust_bonus_int(-5);
    previous_object()->adjust_bonus_wis(-5);
    previous_object()->adjust_bonus_cha(-(previous_object()->query_cha()-3));
}

string query_desc(object ob) {
    return "A fierce looking wolf with red glowing eyes.\n";
}

void race_heartbeat(object player)
{
    object *obs; 
    string moon_str;
    int i;

    if(!player||!ENV(player)||player->query_dead()) return;
    if( !ENV(player)->query_property("noguild"))
    {
	obs = all_inventory(ENV(player));
	obs -= ({ player });
	tell_room(ENV(player),player->query_cap_name()+" snarls viciously "
	  "and attacks everything in sight.\n");
	for(i=0;i<sizeof(obs);i++)
	{
	    if(!obs[i]->query_alive()) continue;
	    if(obs[i]->query_property("wolfbane") || player->query_property("wolfbane"))
	    {
		tell_object(player,"A terrible smell assault your wolf senses "
		  "driving you away.\n");
		player->run_away();
		break;
	    }
	    if(!interactive(player) && !random(CONT_CHANCE))
	    {
		tell_object(obs[i],player->query_cap_name()+"'s teeth sinks deep "
		  "into your thigh.\n");
		obs[i]->add_property("WEREWOLF",1);
	    }
	    player->attack_ob(obs[i]);
	}
	player->adjust_hp(100);
	if(WEATHERHAND->query_day(ENV(player)))
	    change_race(player);
    }
    ::race_heartbeat(player); // or they can't drown
}

void start_player(object player)
{
    object claws, shadow;
    int i;

    player->add_static_property("nocast",1);
    player->add_static_property("noguild",1);
    player->add_static_property("magical",70);
    "/std/spells/wizard/useful_stuff"->force_drop_everything(player);
    for(i=0;i<2;i++)
    {
	claws = clone_object(CLAWS);
	claws->move(player);
	player->hold_ob(claws);
	claws->add_property("cursed",1);
    }
    shadow = clone_object(WOLF_SHADOW);
    shadow->setup_shadow(player);
    player->set_language("werewolf");

    ::start_player(player);
}



void change_race(object player)
{
    object *claws;
    int i;

if(player->query_property("JUST_CHANGED")) return;
    player->remove_werewolf_shadow();
    player->remove_static_property("nocast");
    player->remove_static_property("noguild");
    player->remove_static_property("magical");
     player->add_timed_property("JUST_CHANGED",1,100);

    claws = find_match("claws",player);
    for(i=0;i<sizeof(claws);i++)
    {
	claws[i]->remove_property("cursed");
	claws[i]->dest_me();
    }
    player->set_race_ob("/std/races/"+player->query_property(OLDRACE));
}

void player_quit(object player)
{
    change_race(player);
}
