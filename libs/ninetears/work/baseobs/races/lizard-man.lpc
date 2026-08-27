inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
    set_long("A green-scaled lizard-man.\n");
    set_name("lizard-man");
    set_light_limits(LIGHT_LIZARDMAN_LOW, LIGHT_LIZARDMAN_HIGH);
    reset_get();
    set_limbs(3);
}
int query_underwater_breathing(object player) { return player->query_con()*30; }
int query_swim_stamina(object player) { return player->query_con()*30; } // 3* default

void set_racial_bonuses() 
{
    previous_object()->adjust_bonus_str(1);
    previous_object()->adjust_bonus_int(-1);
}

int query_skill_bonus(int lvl, string skill) 
{
    if (skill == "dex.stealth")
	return 20;
    return 0;
}

string query_desc(object ob) 
{
    switch((int)ob->query_gender())
    {
    case 1 : return("A lizard-man.\n");
    case 2 : return("A lizard-woman.\n");
    case 3 : return("A bisexual lizard-man.\n");
    default: return("An asexual lizard-man.\n");
    }
}
