#include <std.h>
inherit ARMOUR;


void create() {
   ::create();
   set_name("%^BOLD%^%^GREEN%^Acid %^BOLD%^%^BLACK%^Armour%^RESET%^");
   set_id( ({ "armour","acid armour","acid" }) );
   set_short("%^BOLD%^%^GREEN%^Acid %^BOLD%^%^BLACK%^Armour%^RESET%^");
   set_long("just a buncha acid");
   set_mass(40);
   set_curr_value("gold",300);
   set_ac(5);
   call_out("glow",40);
   call_out("talk",50);
    set_limbs(({ "torso"
}));
}


   
void glow() {
   if(!this_object()->query_worn()) return 0;
   write("You are odd");
   say("%^BOLD%^%^BLACK%^The %^BOLD%^%^GREEN%^acid%^BOLD%^%^BLACK%^ spurts forth from the armour.");
   remove_call_out("glow");
   call_out("glow",40);

}

void talk() {
   if(!this_object()->query_worn())  return 0;
   write("Strange, I didnt put that there!");
   say("%^BOLD%^%^GREEN%^Acid %^BOLD%^%^BLACK%^burble, bubbles, and foams around itself.");
   remove_call_out("talk");
   call_out("talk",50);

}
