#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("%^BOLD%^%^GREEN%^Acid %^BOLD%^%^BLACK%^Armour%^RESET%^");
   set_id( ({ "armour","acid armour","acid" }) );
   set_short("%^BOLD%^%^GREEN%^Acid %^BOLD%^%^BLACK%^Armour%^RESET%^");
   set_long("Armour made from the spit of %^BOLD%^%^RED%^Satan%^RESET%^ himself.");
   set_mass(40);
   set_curr_value("gold",300);
   set_ac(5);
   call_out("glow",40);
   call_out("talk",50);
    set_limbs(({ "torso"
}));
}

void glow() {
   write("%^BOLD%^%^BLACK%^The %^BOLD%^%^GREEN%^acid%^BODL%^%^BLACK%^ spits out of the armour.%^RESET%^");
   say("%^BOLD%^%^BLACK%^The %^BOLD%^%^GREEN%^acid%^BODL%^%^BLACK%^ spits out of the armour.%^RESET%^");
   remove_call_out("glow");
   call_out("glow",40);
}

void talk() {
   write("%^BOLD%^%^GREEN%^Gurgling and hissing comes from the armour.");
   say("%^BOLD%^%^GREEN%^Gurgling and hissing comes from the armour.");
   remove_call_out("glow");
   call_out("talk",50);
}
