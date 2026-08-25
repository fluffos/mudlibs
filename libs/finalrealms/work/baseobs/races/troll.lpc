inherit "/std/races/standard";
#include "light_defs.inc"
#define HANDLER "/obj/handlers/weather"
#define STONE "/std/spells/cleric/stoned"
// Swims... like a rock.
int query_swim_stamina(object player) { return player->query_con(); }

void setup() {
    set_long("This has been set up as a monster race.\n");
    set_name("troll");
    set_light_limits(LIGHT_TROLL_LOW, LIGHT_TROLL_HIGH);
    reset_get();
} /* setup() */

void set_racial_bonuses() {
    previous_object()->adjust_bonus_con(3);
    previous_object()->adjust_bonus_int(-7);
    previous_object()->adjust_bonus_str(5);
    previous_object()->adjust_bonus_wis(-7);
    previous_object()->adjust_bonus_cha(-(previous_object()->query_cha()-3));
} /* set_racial_bonuses() */

int query_skill_bonus(int lvl, string skill) {
    return 0;
} /* query_skill_bonus() */

string query_desc(object ob) {
    return "An ugly looking troll.\n";
} /* query_desc() */


void race_heartbeat(object player)
{
    object stone, *obs;
    int i;

    if(!player || !ENV(player) || player->query_dead()) return;
    if(!ENV(player)->query_property("noguild"))
    {

	//if(!player->query_property("stoned"))
	{
	    obs = all_inventory(ENV(player));
	    obs -= ({ player });
	    tell_room(ENV(player),player->query_cap_name()+" snarls viciously "
	      "and attacks everything in sight.\n");
	    for(i=0;i<sizeof(obs);i++)
	    {
		if(!living(obs[i])) continue;
		if(obs[i]->query_race() != "troll")
		    player->attack_ob(obs[i]);
	    }
	}
	if(ENV(player)->query_outside() && (HANDLER->query_day(ENV(player))))
	{
	    if(player->query_property("stoned")) return;

	    tell_object(player, "You feel yourself slow, your body "
	      "feels leaden slowing your every movement.\n"); 
	    stone = clone_object(STONE);
	    player->add_static_property("stoned",1);
	    stone->move(player);
	    stone->reset_get();
	    stone->setup_shadow(player);
	    return;
	}
	else
	    // Yes, will allow the spell to remain, cause that's timed_prop.
	if(player->query_static_property("stoned"))
	{ 
	    tell_object(player, "Out of the burning sun, your flesh "
	      "soften and turn normal again.\n");
	    player->remove_static_property("stoned");
	    player->dispell_me();
	}
	player->add_static_property("fire",-100);
	player->adjust_hp(30,TO); // trol regen
    }
    ::race_heartbeat(player);
}
