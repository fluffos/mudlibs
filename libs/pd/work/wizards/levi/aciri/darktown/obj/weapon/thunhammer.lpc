#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("fangs");
   set_short("%^BOLD%^%^CYAN%^T%^RESET%^%^CYAN%^h%^BOLD%^e "
     "%^RESET%^%^CYAN%^T%^BOLD%^h%^RESET%^%^CYAN%^u%^BOLD%^n%^RESET%^%^CYAN%^d%^BOLD%^e%^RESET%^%^CYAN%^r "
     "%^BOLD%^H%^RESET%^%^CYAN%^a%^BOLD%^m%^RESET%^%^CYAN%^m%^BOLD%^e%^RESET%^%^CYAN%^r%^RESET%^");
   set_long("Nicknamed The Thunder Hammer, this hammer's top is empowered with "
     "the captured power of thunder. The thunder hammer is said to be able to "
     "channel a person's power from their spirit to their defense.");
   set_weight(7);
   set_id(({ "hammer", "thunder hammer" }));
   set_wc(9);
   set_ac(3);
   set_type("blunt");
   set_value(225);
}

int query_auto_load() {
   if (this_player()->query_level() >= 18) return 0;
}
