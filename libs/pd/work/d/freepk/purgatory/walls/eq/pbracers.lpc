#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Bone-Plated Bracers");
    set_short("%^BOLD%^%^WHITE%^Bo%^RESET%^n%^BOLD%^%^WHITE%^e-P%^RESET%^lat%^BOLD%^%^WHITE%^ed Br%^BLACK%^ace%^WHITE%^rs%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^These bracers have been made from the arms of many slain foes. The nicks and cuts on the bones shows it protects the owners arm quite well.%^RESET%^");
    set_id(({"bracers", "bone-plated bracers", "bone plated bracers"}));
    set_ac(3);            
    set_mass(25);
    set_type("bracers");
    set_curr_value("gold", 90+random(30));  
    set_limbs(({ "right arm", "left arm"}));
}
 int query_auto_load() { if (this_player()->query_level() > 89) return 1; }


int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 89) return 0;
   write("Why, in the immortals name, would you want to wear that?");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}
