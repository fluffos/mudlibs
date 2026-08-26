#include <std.h>
#include "../../defs.h"
inherit WEAPONLESS;

int following;

void create() {
    ::create();
    set_id(({"ravener","raptor","vicious raptor"}));
    set_name("ravener");
    set_short("%^RESET%^%^BLUE%^A vicious raptor%^RESET%^");
    set_long("%^RESET%^This vicious-looking reptile, known to underdark travellers as a ravener, stands upon "
"its hind-legs to walk upright, with its razor-sharp clawed forelegs and its thick tail held steady for balance"
". Its muscular, %^BLUE%^dark-scaled %^RESET%^body moves with the grace of a predator, blending into its dark "
"surroundings, and its %^BOLD%^%^GREEN%^sharp green eyes %^RESET%^show a feral intelligence unlike any animal "
"you've seen in your life. The only sound it makes as it moves is the soft %^RED%^click %^RESET%^of its talons "
"on the stone ground.");
    set_race("lizard");
    set_body_type("reptile");
    if (random(2)) set_gender("male");
    else set_gender("female");
    set_alignment(5);
    set_class("fighter");
    set_hd(25,6);
    set_guild_level("fighter",25);
    set_mlevel("fighter",25);
    set_max_hp(200);
    set_hp(query_max_hp());
    set_property("swarm",1);
    set_stats("strength",18);
    set_exp(1000);
    set_overall_ac(-12);
    set("aggressive",25);
    set_attack_limbs(({"right forefoot","left forefoot"}));
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_damage(1,6);
    set_funcs(({"special"}));
    set_func_chance(10);
}

void special(object target) {
   tell_room(ETO,"%^RED%^The ravener goes into a rage, slashing at anything within reach!%^RESET%^");
   TO->execute_attack();
   TO->execute_attack();
   TO->execute_attack();
   return;
}

void init(){
   object ob;
   ::init();
   if(!following) {
     if(ob = present("ravener leader",ETO)) {
       ob->add_follower(TO);
       following = 1;
     }
   }
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_sapient(){ return 0; }
int is_tamable(){ return 1; }
int query_tame_DC(){ return 40; }
string query_DC_type(){ return "survival"; }

