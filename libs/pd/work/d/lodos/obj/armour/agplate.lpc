#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("platevest");
   set_short("%^BOLD%^%^WHITE%^go%^YELLOW%^lden "
     "pl%^RESET%^%^ORANGE%^ate%^BOLD%^mail ve%^WHITE%^st%^RESET%^");
   set_long("The golden platemail vest looks like it may be part of a "
     "complete, very magnificent set. This vest is made of gold and "
     "acrilite, giving an impressive apearance.");
   set_limbs(({ "torso" }));
   set_id(({ "vest", "golden platemail vest", "platemail vest",
             "plate" }));
   set_weight(23);
   set_ac(5);
   set_type("vest");
    set_curr_value("gold", 85);
}

int query_auto_load() {
   if (this_player()->query_level() >= 25) return 1;
}
