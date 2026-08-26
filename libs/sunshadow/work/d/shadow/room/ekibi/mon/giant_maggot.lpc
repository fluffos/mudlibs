//giant_maggot.c - Mob for low level underdark area
//by Circe 3/11/05
#include <std.h>
#include "../ekibi.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("giant maggot");
    set_short("%^BOLD%^%^WHITE%^A writhing giant maggot%^BOLD%^%^RED%^");
    set_id(({ "maggot", "giant maggot", "writhing maggot" }));
    set_long("%^BOLD%^%^WHITE%^About the size of a human child, this " +
             "writhing maggot is the larva of some giant insect.  It has " +
             "tiny legs that make it look something like a hairless " +
             "caterpillar.  There seems to be no eyes or other appendages, " +
             "and it seems bent on one thought alone - FOOD!%^RESET%^");
    set_gender("neuter");
    set_race("maggot");
    set_body_type("snake");
    set_size(1);
    set_alignment(5);
    set_hd(5, 5);
    set("aggressive", 18);
    set_property("swarm", 1);
//   set_class("fighter");
//   set_mlevel("fighter",5);
//   set_hp(random(10)+40);
    set_overall_ac(8);
    set_stats("strength", 12);
    set_damage(1, 4);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "mouth" }));
    set_exp(120);
    set_max_level(7);
    set_hp(query_max_hp());
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 10; }
string query_DC_type(){ return "survival"; }

