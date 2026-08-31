#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("bracers");
   set_short("%^BOLD%^acrilit%^RESET%^e brace%^BOLD%^rs%^RESET%^");
   set_long("The acrilite bracers are strong and sturdy. They are "
     "of a very rare metal, acrilite. The white bracers gleam in the "
     "light.");
   set_limbs(({ "left arm", "right arm" }));
   set_id(({ "bracers", "acrilite bracers" }));
   set_weight(3);
   set_ac(2);
   set_type("bracers");
    set_curr_value("silver", 325);
}

int query_auto_load() {
   if (this_player()->query_level() >= 24) return 1;
}
