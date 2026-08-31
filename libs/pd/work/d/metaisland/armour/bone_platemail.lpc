#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Bone platemail");
    set_short("%^BOLD%^%^BLACK%^B%^WHITE%^on%^BLACK%^e Pl%^WHITE%^atem%^BLACK%^ail");
    set_long("The platemail is made from the ribs of old animals.");
    set_id(({"bone platemail", "platemail"}));
    set_ac(13);
    set_weight(46);
    set_curr_value("gold",154);
    set_type("body armour");
    set_limbs(({"torso", "left arm", "right arm"}));
}
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
