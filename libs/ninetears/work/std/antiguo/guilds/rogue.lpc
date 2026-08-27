#include "skills.h"
#include "weapon.h"
inherit "/std/guild";

int query_skill_cost(string skill) {
    return 6;  /* Need a list of possible skills first.  Awaiting Dank */
}

void setup() {
    set_name("rogue");
    set_short("rogue");
    set_long(
      "Rogues are the thieves and scoundrels of Magisk Jord "
      "They are good at opening locks, disarming traps,  "
      "at relieving other people of things they no longer require "
      "and general sneaking around.  "
      " Their survival depends on their speed and ready tongue.\n");
    reset_get();
    add_guild_command("palm", 1);
    add_guild_command("sneak", 1);
    add_guild_command("hide", 1);
    add_guild_command("slip", 1);
    add_guild_command("steal", 1);
}

void create()
{
    ::create();
    set_main_skill("str");
} /* setup() */

string query_main_skill() {return "str";}
int query_advance_cost() { return  1000; }
int query_xp_cost()      { return 1250; }
int query_dice()         { return 8;    }
int query_thac0_step() {return 4;}

int query_legal_race(string race) {
    return 1;
}

int query_legal_armour(string type)
{
    switch(type)
    {
    case "leather":
    case "padded leather":
    case "padded":
    case "elfin chain":
    case "basinet":
    case "shoes":
    case "slippers":
    case "boots":
    case "amulet":
    case "pendant":
    case "necklace":
    case "cape":
    case "cloak":
    case "ring":
    case "belt":
	return 1;
    default: return 0;
    }
}

int query_legal_weapon(string type)
{
    switch(type)
    {
    case "polearm":
    case "two-handed sword":
    case "bow":
    case "lance":
    case "mace":
	return 0;
    default : return 1;
    }
}

void check_stab(object ob) {
    if (ob && random(4))
	call_out("do_it", 0, ob);
} /* check_stab() */

void do_it(object ob) {
    if (ob)
	do_command("backstab", ob->query_name());
} /* do_it() */

/*
void set_gp(object ob) {
  ob->set_max_gp(level+(int)ob->query_dex());
}

void set_hp(object ob) {
  ob->set_max_hp(query_dice()  *(level +1));
}
*/

int query_dual_wield_penalty(object me, object w1, object w2)
{
    int bon;

    if ( w1->query_attack_type() != 3 || w2->query_attack_type() != 3 )
	return 50;

    bon = 50 - (int)me->query_level()*3/2;
    bon = ( bon<10 ? 10 : bon );

    return bon;
}
void on_death(object player, object killer) {
}
