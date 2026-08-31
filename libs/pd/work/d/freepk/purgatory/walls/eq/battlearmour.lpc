#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Bone-Plated Battle Armour");
    set_short("%^BOLD%^%^WHITE%^Bo%^RESET%^n%^BOLD%^%^WHITE%^e-P%^RESET%^lat%^BOLD%^%^WHITE%^ed Ba%^RESET%^ttl%^BOLD%^%^WHITE%^e Ar%^BLACK%^mo%^WHITE%^ur%^RESET%^");
    set_long("This armour is a hard leather with the bones of defeated foes sewn into it. The bones have been chipped and scarred in battle.");
    set_id(({"armor","armour", "bone-plate", "bone plate", "bone_plated battle armour", "bone plated battle armour"}));
    set_ac(8);            
    set_mass(187);
    set_type("armour");
    set_curr_value("gold", 50+random(50));
    set_wear("%^BOLD%^%^WHITE%^The skulls try to rend your flesh as you wear the armour.%^RESET%^") ;
    set_remove("%^BOLD%^%^RED%^Your flesh is ripped open as the teeth drag along your skin.%^RESET%^");
    call_out("glow", 200);
    set_limbs(({ "torso", "right arm", "left arm"}));
}
 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 89) return 0;
   write("You are too afraid of the skulls to wear this armour.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

void glow() {
   if(!this_object()->query_worn()) return 0;
   write("%^BOLD%^%^WHITE%^The skulls gnash their teeth together.%^RESET%^");
   say("%^BOLD%^%^WHITE%^The skulls gnash their teeth together.%^RESET%^");
   remove_call_out("glow");
   call_out("glow",300);

}
