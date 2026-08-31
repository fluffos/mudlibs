#include <std.h>
inherit ARMOUR;

int give_bonus();
int remove_bonus();
int calculate_bonus(object);

int wornbonus = 0;

void create() {
  ::create();
  set_id(({ "knuckles", "brass knuckles" }) );
  set_name("knuckles");
  set_short("brass knuckles");
  set_long("They look vicious. Several small, short spikes stick "
   "out of each knuckle.");
  set_weight(4);
  set_curr_value("gold", 25);
  set_ac(1);
  set_type("gloves");
  set_limbs( ({ "left hand", "right hand" }) );
  set_wear( (: give_bonus :) );
  set_remove( (: remove_bonus :) );
}

void heart_beat() {
  object tp = environment();
  object ob;
  if (!tp || !tp->is_living() || tp != query_worn()) return;
  if (tp->query_level() < 5) return;
  if (random(100) < 50) return;
  if (sizeof(tp->query_wielded())) return;
  if (!(ob = tp->query_current_attacker())) return;
  message("info", "%^ORANGE%^You clock your enemy right in the head!%^RESET%^", tp);
  tell_room(environment(tp), "%^ORANGE%^"+tp->query_cap_name()+
   " clocks "+ob->query_cap_name()+" right in the head!%^RESET%^",
   ({ ob, tp }));
  tell_object(ob, "%^ORANGE%^"+tp->query_cap_name()+
   " clocks you right in the head!%^RESET%^");
  ob->do_damage(ob->return_target_limb(), 20 + random(20+tp->query_level()));
}

int give_bonus() {
  wornbonus = calculate_bonus(this_player());
  this_player()->add_skill_bonus("melee", wornbonus);
  set_heart_beat(1);
  return 1;
}
int remove_bonus() {
  if (wornbonus)
    this_player()->add_skill_bonus("melee", -(wornbonus));
  set_heart_beat(0);
  return 1;
}
int calculate_bonus(object tp) {
  int level = tp->query_level();
  int bonus = 15;
  return 0;
  if (level >= 20)
    bonus += 5;
  if (level >= 50)
    bonus += 5;
  return bonus;
}

int query_auto_load() { if (this_player()->query_level() >= 14) return 1; }
