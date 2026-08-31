#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
set_name("cloak");
set_short("%^BOLD%^%^BLACK%^The c%^RESET%^%^MAGENTA%^lo%^BOLD%^%^BLACK%^ak of m%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^dnight%^RESET%^");
set_long("A magical cloak comprised of midnight.  The wearer is given protection by a flowing violet flame that is produced when worn.");
set_id(({"cloak", "cloak of midnight"}));
set_ac(8);
set_weight(20);
set_curr_value("gold",115);
set_type("cloak");
set_wear("%^BOLD%^%^BLACK%^You are engulfed within a %^RESET%^%^MAGENTA%^voilet%^BOLD%^%^BLACK%^ flame.%^RESET%^");
set_remove("%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^voilet%^BLACK%^BOLD%^%^ flame subsides.%^RESET%^");
set_limbs(({"torso", "head", "right leg", "left leg", "right wing", "left wing", "tail", "right arm", "left arm", "horns"}));
}
int query_auto_load() {
if(this_player()->query_level() < 40) return 0;
return 1; }
