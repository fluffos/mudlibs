#include <std.h>
#include <amun.h>
inherit WEAPON;                                                         
void create() {
    ::create();                                                             
    set_name("boomerang");
    set("id", ({ "boomerang" }) );
    set("short",
      "%^RESET%^%^ORANGE%^b%^RED%^o%^ORANGE%^omera%^RED%^n%^ORANGE%^g%^RESET%^"
    );
    set("long",
      "%^RESET%^%^ORANGE%^This boomerang was forged in secret by the monks "
      "and is used primarily for training.%^RESET%^"
    );
    set_type("projectile");
    set_weight(10);
    set_curr_value("gold", 75);
    set_wc(3);
}
int query_auto_load() {
  return this_player()->query_level() >= 15;
}
