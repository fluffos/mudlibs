#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "blade", "silver blade" }));
   set_name("blade");
   set_short("%^BOLD%^a long %^RESET%^silver%^BOLD%^ blade%^RESET%^");
   set_long("The blade's length is approximatly four and a half feet long. It is "
     "as wide as the width of two hands. The blade is heavy and deadly, though "
     "because it was forged of silver, it is worth a pretty copper piece as "
     "well.");
   set_weight(8);
    set_curr_value("gold", 25);
   set_wc(6);
   set_type("blade");
}

int query_auto_load() { if (this_player()->query_skill("blade") >= 15) return 1; }
