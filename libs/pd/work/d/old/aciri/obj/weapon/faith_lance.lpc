#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("lance");
   set_short("%^BOLD%^%^CYAN%^a %^WHITE%^la%^CYAN%^nc%^WHITE%^e o%^CYAN%^f f%^WHITE%^ai%^CYAN%^th%^RESET%^");
   set_long("The lance is made of a pure white light. The lance is sustained by "
     "the faith of it's user. This weapon does damage by the wielder's faith.");
   set_weight(15);
   set_id(({ "kris", "knife" }));
   set_wc(7);
   set_type("faith");
   set_value(350);
   set("skill level", 50);
}

int query_auto_load() {
   if (this_player()->query_skill("faith") >= 50) return 0;
}
