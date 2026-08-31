#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("leggings");
   set_short("%^BOLD%^a%^RESET%^crilite %^BOLD%^chain%^RESET%^mail "
     "leg%^BOLD%^gings%^RESET%^");
   set_long("Leggings of a white metal, acrilite, provide good protection "
     "for the humanoid body. The rings are increadibly small and woven "
     "together to form chainmail leggings.");
   set_limbs(({ "left leg", "right leg" }));
   set_id(({ "leggings", "chainmail leggings", "acrilite leggings" }));
   set_weight(12);
   set_ac(2);
   set_type("leggings");
    set_curr_value("gold", 60);
}

int query_auto_load() {
   if (this_player()->query_level() >= 25) return 1;
}
