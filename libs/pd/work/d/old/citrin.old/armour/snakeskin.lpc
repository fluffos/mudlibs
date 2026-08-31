// Coded by Whit
// Coded for Primal Darkness
// snakeskin.c

#include <std.h>
#include <citrin.h>
inherit ARMOUR;
int query_auto_load() {
if(this_player()->query_level() < 5) return 0;
return 1;
}
void create() {
::create();
    set_name("snakeskin");
    set_short("a green snakeskin");
    set_long("The skin is from that of a green snake.  It was skinned and made "
             "into a durable armour.");
    set_id(({"skin", "snake skin"}));
    set_ac(15);            // Armour class of armour
    set_mass(25);
    set_value(70);
    set_type("armour");   // Read help files for legal types
    set_limbs(({"torso", "left arm", "right arm"}));
}
