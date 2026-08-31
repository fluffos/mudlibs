# include <std.h>
inherit ARMOUR;

void create() {
::create();
  
    set_name("rock armor");
    
set_short("Massive Rock Platemail");
    set_long("Massive plates of rock have been put together to form "
         "this impressive suit of armor.  The rock, mined in the "
         "Acirian mines, is very durable.");
    set_id(({"armor", "platemail"}));
    set_ac(15);            
    set_mass(99);
    set_type("armour");   
set_limbs(({"right arm", "left arm", "right leg", "left leg", "torso", "head", "right hand", "left hand", "right foot", "left foot" }));

}
int query_auto_load() { if (this_player()->query_level() >=1) return 1; }
