# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("cloak");
    
set_short("%^BLUE%^Bl%^BOLD%^ue Feat%^RESET%^%^BLUE%^he%^BOLD%^red Clo%^RESET%^%^BLUE"
"%^ak%^RESET%^");
    set_long("The Cloak of a Vampire. ");
    set_id(({"cloak", "feathers"}));
    set_ac(16);            
    set_mass(1);
    set_type("cloak");   
set_limbs(({"right foot", "left foot", "right arm", "left arm",
    "right leg", "left leg", "torso", "head", "right hand", "left hand"}));

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
