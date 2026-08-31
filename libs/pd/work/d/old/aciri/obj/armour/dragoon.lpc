#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("armour");
   set_short("%^RESET%^%^ORANGE%^%^D%^YELLOW%^rag%^BOLD%^%^WHITE%^oon A%^YELLOW%^rmou%^RESET%^%^ORANGE%^r");
   set_long("The stunning dragoon armour is made of platinum with gold trim "
     "around the edges of the armour. The armour consists of a platinum "
     "breastplate and sholder guards with golden lined bracers. A platinum and "
     "gold leg coverings extend from the breastplate.");
   set_weight(70);
   set_id(({ "armour", "dragoon armour" }));
   set_ac(12);
   set_type("body armour");
   set_value(472);
   set_limbs(({ "torso", "left arm", "right arm", "left leg", "right leg" }));
}

int query_auto_load() { if (this_player()->query_level() >= 38) return 3; }
