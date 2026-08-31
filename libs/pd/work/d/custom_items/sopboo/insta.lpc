#include <std.h>
inherit ARMOUR;
void add_bonus(object);
void remove_bonus(object);
void create() {
  ::create();
  set_name("Insta");
  set_short("%^BOLD%^%^BLACK%^I%^RED%^n%^BLACK%^s%^RED%^t%^BLACK%^a%^RESET%^");
  set_long("A beautiful platinum ring, this was won by Sopboo for saving Arlon from the Drow Goddess, Lloth.");
  set_id(({ "ring", "event ring", "sopbooeventring", "insta"}));
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
  tp->add_stat_bonus("dexterity", 5);
}
void remove_bonus(object tp) {
  tp->add_stat_bonus("dexterity", -5);
}
