#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("cap");
   set_short("%^BOLD%^%^CYAN%^a jester's cap%^RESET%^");
   set_long("The jester's cap is a brilliant array of colors. It "
     "has five long stalks that hang down over the wearer's face. "
     "At the tip of each stalk is a tiny golden bell.");
   set_weight(7);
   set_id(({ "cap", "jesters cap" }));
   set_ac(3);
   set_type("helmet");
   set_value(200);
   set_limbs(({ "head" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 18) return 3;
}
