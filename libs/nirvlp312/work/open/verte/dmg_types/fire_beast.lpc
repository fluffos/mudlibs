inherit "/obj/monster";

#include "/players/vertebraker/ansi.h"

void
reset(status arg)
{
    if(arg) return;
    ::reset();
    set_name("fire beast");
    set_alias("beast");
    set_short(HIR + "Fire Beast" + NORM);
    set_long("\
The fire beast is comprised of molten lava, and it\n\
roars before you.\n");
    set_level(20);
    set_hp(500);
    set_wc(30);
    set_ac(17);
    set_race("fire beast");
    set_gender("creature");
    /* 10 points of ac, 20% resistance to other|fire,
       calls the func 'fire_defense' */
    set_armor_params("other|fire", 10, 20, "fire_defense");
}

int
fire_defense()
{
    if(!random(4))
    {
      tell_room(environment(),
RED +"Flames" + NORM + " burn around the Fire Beast!\n");
      return 3001;
    /* this round, the beast gets an additional
       30% resistance to other|fire dmg,
       and 1 extra point of other|fire AC */
    }
}
