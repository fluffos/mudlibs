#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("suit");
   set_short("a %^BOLD%^%^BLACK%^leather%^RESET%^ jumpsuit");
   set_long("The leather jumpsuit was made to fit a humanoid body. "
     "It is light and fits very tight to the body, allowing maximal "
     "movement.");
   set_weight(1);
   set_id(({ "suit", "leather jumpsuit", "leather suit", "jumpsuit" }));
   set_ac(2);
   set_type("armour");
   set_value(100);
   set_limbs(({ "torso", "left leg", "right leg", "right arm",
                "left arm" }));
}

int query_auto_load() { if (this_player()->query_level() >= 3) return 0; }
