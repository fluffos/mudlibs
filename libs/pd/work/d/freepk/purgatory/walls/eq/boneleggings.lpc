#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Bone-Plated Leggings");
    set_short("%^BOLD%^%^WHITE%^Bo%^RESET%^n%^BOLD%^%^WHITE%^e-P%^RESET%^lat%^BOLD%^%^WHITE%^ed Le%^BLACK%^ggi%^WHITE%^ngs%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The shins of many defeated foes have been sewn into a hard leather to be worn on the legs.");
    set_id(({"leggings", "bone leggings", "bone plated leggings", "bone-plated leggings"}));
    set_ac(4);            
    set_mass(35);
    set_type("leggings");
    set_curr_value("gold", 149+random(50));  
    set_limbs(({ "right leg", "left leg"}));
}
 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 89) return 0;
   write("You wouldnt dare wear this.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
