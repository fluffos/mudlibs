#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("lance");
   set_short("%^BOLD%^%^CYAN%^A %^YELLOW%^L%^BOLD%^%^CYAN%^i%^YELLOW%^g%^BOLD%^%^CYAN%^h%^YELLOW%^tning %^BOLD%^%^CYAN%^L%^YELLOW%^ance%^RESET%^");
   set_long("A very bolt of lightning, frozen within time and space. The "
     "lightning is here, solid. The bolt of lightning is a great lance.");
   set_weight(21);
   set_id(({ "lance", "lightning", "lightning lancee" }));
   set_wc(9);
   set_type("projectile");
   set_value(345);
   set("skill level", 20);
}

int query_auto_load() {
   if (this_player()->query_level() >= 30) return 0;
}
