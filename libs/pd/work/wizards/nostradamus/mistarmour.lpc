#include <std.h>
inherit ARMOUR;

void create() {
::create();
   set_name("armour");
   set_short("Mist Armour");
   set_long("This armour was created by ancient elven mages.  It is "
    "made from the morning mist.  It is damp and cold to your senses."
    "  It looks as though you could pass your hand right through it.");
   set_id(({"armour", "mist", "mist armour", "plate"}));
   set_ac(15);
   set_mass(30);
   set_value(100000);
   set_type("armour");
   set_limbs(({"torso", "left arm", "right arm", "right leg", "left leg",
    }));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
