#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("blade");
   set_short("%^RESET%^%^CYAN%^a s%^BOLD%^hi%^WHITE%^mmer%^CYAN%^in%^RESET%^%^CYAN%^g b%^BOLD%^l%^WHITE%^a%^CYAN%^d%^RESET%^%^CYAN%^e%^RESET%^");
   set_long("The light blue blade shimmers and reflects light into many "
     "different hues of color. It is almost impossible to tell whether the "
     "blade is real or illusory.");
   set_weight(8);
   set_id(({ "blade", "shimmering blade", "illusory blade" }));
   set_wc(7);
   set_type("blade");
   set_value(390);
}

int query_auto_load() {
   if (this_player()->query_level() >= 31) return 0;
}
