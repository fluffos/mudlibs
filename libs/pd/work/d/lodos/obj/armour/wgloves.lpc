#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("gloves");
   set_short("%^BOLD%^%^WHITE%^wh%^YELLOW%^i%^WHITE%^te "
     "gl%^YELLOW%^ov%^WHITE%^es%^RESET%^");
   set_long("Long white gloves reach just shy of the elbow. These gloves "
     "are made of a very thin material and are completely white.");
   set_limbs(({ "left hand", "right hand" }));
   set_fingers(5);
   set_id(({ "gloves", "white gloves" }));
   set_weight(3);
   set_ac(2);
   set_type("gloves");
    set_curr_value("gold", 25);
}

int query_auto_load() {
   if (this_player()->query_level() >= 15) return 1;
}
