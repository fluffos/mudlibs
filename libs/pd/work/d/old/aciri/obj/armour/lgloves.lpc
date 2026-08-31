#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("gloves");
   set_short("%^BOLD%^%^BLACK%^sof%^WHITE%^t le%^RESET%^ather %^BOLD%^%^WHITE%^glo%^BLACK%^ves%^RESET%^");
   set_long("The comfortable leather gloves are soft from being worn in. The "
     "leather is soft, and almost feels new. These gloves have an excellent "
     "grip.");
   set_weight(4);
   set_id(({ "leather gloves", "soft gloves", "gloves" }));
   set_ac(3);
   set_type("gloves");
   set_value(152);
   set_limbs(({ "left hand", "right hand" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 16) return 3;
}
