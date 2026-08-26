#include <std.h>
inherit "/std/monster";

void create() {
  ::create();
  set_name("hell hound");
  set_id(({"hell hound","Hell hound","hellhound","hound"}));
  set("race","hell hound");
  set_gender("female");
  set("short","Hell hound");
  set("long","Hell hounds are rusty red to red brown in color.  Their eyes\n"+
             "are glowing red while teeth and tongues are sooty black.  Hell \n"+
             "hounds are not normally from the material plane, but some few\n"+
             "now dwell on it, having been brought along by various creatures\n"+
             "who wished their evil service.");
  set_level(7);
  set_hd(7,1);
  set_body_type("quadruped");
  set_exp(8000);
  set_class("fighter");
  set("aggressive", 18);
  set_size(2);
  set_alignment(9);
  set_stats("dexterity", 18);
  set_stats("strength", 17);
  set_funcs(({"breathe"}));
  set_func_chance(20);
  set_max_hp(70);
  set_hp(query_max_hp());
}

void breathe(object targ) {
   if(!objectp(targ)) return;
  if("/daemon/saving_d"->saving_throw(targ,"breath_weapon"))
    targ->do_damage("torso", 4);
  else
    targ->do_damage("torso", 7);
  tell_object(targ, "%^RED%^The hell hound breathes out a scorching fire upon you.");
  tell_room(environment(targ), "%^BOLD%^The hell hound breathes upon "+targ->query_cap_name()+" with a scorching fire.");
  return 1;
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 10; }
string query_DC_type(){ return "survival"; }

