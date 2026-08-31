#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("armour");
   set_short("armour of thorns");
   set_long("The armour is made out of millions of thorns, all intertwined and "
     "interlaced into a thick suit. The armour is a bit uncomfortable, but is "
     "pretty durable.");
   set_weight(5);
   set_id(({ "armour", "armour of thorns" }));
   set_wear("You cringe as thousands of thorns pierce into your flesh.");
   set_remove("The thorn wounds magically heal.");
   set_ac(6);
   set_type("body armour");
   set_value(172);
   set_limbs(({ "torso", "head", "left arm", "right arm", "left leg",
                "right leg" }));
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 3; }
