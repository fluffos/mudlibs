inherit "/std/guild";

#define SPELL_TABLE "/table/spell_table"

int query_skill_cost(string skill)
{
    return 6;
}

void setup()
{
    set_name("mage");
    set_short("mage");
    set_long(
      "Mages are the most powerful magic-users on "
      "Magisk Jord.  Their power lays in quickness of thought "
      "and powerful spells rather than hand to hand fighting "
      "ability.  They favor the power of  the Arcane and have "
      "no desire for the 'barbaric' forms of combat.\n"); 
    reset_get();
}
void create()
{
    ::create();
    set_main_skill("int");
}

int query_advance_cost() { return  500; }
int query_xp_cost()      { return 2500; }
int query_dice()         { return 6;    }
int query_thac0_step()   { return 2;    }
string query_main_skill() {return "int";}

int query_legal_race(string race) {
    switch(race) {
    case "dwarf":
    case "halfling":
    case "lizard-man":
    case "half-orc":
    case "orc": return 0;
    default       :return 1;
    }
}

string query_spell_directory() { return "/std/spells/wizard/"; }

int query_legal_weapon(string type)
{
    switch(type)
    {
    case "dagger":
    case "dirk":
    case "dart":
    case "quarterstaff":
    case "staff":
    case "sling":
    case "knife":
	return 1;
    default: return 0;
    }
}

int query_legal_armour(string type)
{
    switch(type)
    {
    case "robe":
    case "boots":
    case "shoes":
    case "bracers":
    case "cloak":
    case "ring":
    case "amulet":
    case "pendant":
    case "necklace":
    case "cape":
    case "slippers":
    case "leather":
    case "belt":
	return 1;
    default:
	return 0;
    }
}


int query_dual_wield_penalty(object me, object w1, object w2)
{
    return 50;
}


/*
void set_gp(object ob)
{ ob->set_max_gp(level+(int)ob->query_int()); }

void set_hp(object ob)
{ ob->set_max_hp(query_dice()*level); }
int query_see_magic()
{
  return 1;
} 
*/
void on_death(object player, object killer) {
}
