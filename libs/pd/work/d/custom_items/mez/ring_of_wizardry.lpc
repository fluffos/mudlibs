#include <std.h>
inherit ARMOUR;
void add_bonus(object);
void remove_bonus(object);
void create() {
  ::create();
  set_name("ring of wizardry");
  set_short("%^BOLD%^%^GREEN%^R%^RESET%^%^ORANGE%^in%^BOLD%^%^GREEN%^g%^RESET%^ %^ORANGE%^of %^BOLD%^%^GREEN%^W%^RESET%^%^ORANGE%^iz%^GREEN%^ar%^ORANGE%^dr%^BOLD%^%^GREEN%^y%^RESET%^");
  set_long("A beautiful platinum ring, this was won by Mez for saving Arlon from the Drow Goddess, Lloth.");
  set_id(({ "ring", "event ring", "mezeventring", "ring of wizardry"}));
  set_weight(5);
  set_limbs(({"right hand", "left hand"}));
  set_type("ring");
  set_ac(1);
  set_post_wear_func( (: add_bonus :) );
  set_post_remove_func( (: remove_bonus :) );
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 1);
}
void add_bonus(object tp) {
  tp->add_stat_bonus("intelligence", 5);
  tp->add_stat_bonus("wisdom", 4);
}
void remove_bonus(object tp) {
  tp->add_stat_bonus("intelligence", -5);
  tp->add_stat_bonus("wisdom", -4);
}
