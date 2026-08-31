#include <std.h>
inherit ARMOUR;
void add_bonus(object);
void remove_bonus(object);
void create() {
  ::create();
  set_name("The Pain of Ages");
  set_short("%^BOLD%^%^YELLOW%^T%^RED%^he %^YELLOW%^P%^RED%^ai%^YELLOW%^n %^RED%^o%^YELLOW%^f %^RED%^A%^YELLOW%^g%^RED%^es%^RESET%^");
  set_long("A beautiful platinum ring, this was won by Uzamaki for saving Arlon from the Drow Goddess, Lloth.");
  set_id(({ "ring", "event ring", "the pain of ages", "uzamakieventring", "pain of ages"}));
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
  tp->add_stat_bonus("wisdom", 5);
}
void remove_bonus(object tp) {
  tp->add_stat_bonus("wisdom", -5);
}
