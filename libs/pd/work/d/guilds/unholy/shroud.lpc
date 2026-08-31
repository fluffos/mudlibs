#include <std.h>
inherit ARMOUR;
int add_bonus();
int remove_bonus();
void create() {
  ::create();
  set_name("shroud");
  set_short("%^BOLD%^BLACK%^S%^RESET%^%^MAGENTA%^h%^BOLD%^BLACK%^r%^RESET%^%^MAGENTA%^o%^RESET%^%^RED%^u%^RESET%^%^MAGENTA%^d %^BOLD%^BLACK%^of%^RESET%^ %^RED%^A%^RESET%^%^MAGENTA%^s%^RED%^m%^BOLD%^BLACK%^o%^RESET%^%^MAGENTA%^d%^BOLD%^BLACK%^e%^RESET%^%^MAGENTA%^u%^MAGENTA%^%^RESET%^%^MAGENTA%^%^RESET%^%^RED%^s%^RESET%^");
  set_property("dragon wear", 1);
  set_long("%^BOLD%^BLACK%^This shroud seems void of material, bearing a ghastly aura. The mask seems to conform and contort to the users face, sprawling tendrils of evil down the neck and chest. Only the darkest of beings may dare touch such a%^RESET%^ %^RED%^spectacle.%^RESET%^");
  set_id(({ "mask", "shroud"}));
  set_weight(10);    
  set_curr_value("gold", 175000);
  set_limbs(({"head"}));
  set_type("mask");
  //   set_ac(3);
  set_ac(0);
  set_post_wear_func( (: add_bonus :) );
  set_post_remove_func( (: remove_bonus :) );

}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 1);
}
void add_bonus(object tp) {
  tp->set_disguised_short("A follower of Asmodeus");
  tp->set_disguised_id(({ tp->query_name(), "follower", "follower of asmodeus"}));
}
void remove_bonus(object tp) {
  tp->remove_disguised_short();
  tp->remove_disguised_id();
}
