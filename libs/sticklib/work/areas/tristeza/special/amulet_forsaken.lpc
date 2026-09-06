// This is an amulet of +2 int. (+3 you mean?)
// Needless to say, it is unique, and in the posession
// of one of the toughest monsters in the mud. :)
//

// With the new rules, this needs to have an equal countereffect
// for stat boost. /Graah

#include <unique_armour.h>
#include <stats.h>

void
create_armour()
{
    set_type("amulet");
    set_weight(1);
    set_ac(1);
    if (set_unique(object_name(this_object()), UNIQUENESS_PARTIAL, 2, 1))
    {
	set_name("amulet of the forsaken");
	set_short("Amulet of the Forsaken");
	set_long("This is the amulet of the ancient daemon Ba'alzamon,\
 the Forsaken. You sense a magical aura about it, but cannot determine it's\
 exact nature.");
	set_value(10000);
	add_special_property( ARM_SP_BOOST_STAT, ST_INT, 3 );
	add_special_property( ARM_SP_DRAIN_STAT, ST_STR, 2 );
	add_special_property( ARM_SP_DRAIN_STAT, ST_FP_HEAL_RATE, 1 );
    }
    else
    {
	set_name("broken amulet");
	set_short("Broken amulet of the Forsaken");
	set_long("This is the amulet of the ancient daemon Ba'alzamon,\
 the Forsaken. Unfortunately, it is blackened and partially melted.\
 You can sense no power in it.");
	set_value(500);
    }
}
