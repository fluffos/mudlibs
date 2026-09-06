#include <npc.h>

/* Make thieves train somewhere else. */
int
prevent_stab(object att)
{
    if ((int)att->query_level() > 15)
    {
	att->tell_me("The mouse is much too small and quick to be stabbed.");
	return 1;
    }
    return 0;
}

void
create_monster()
{
    set_level(1);
    set_name("mouse");
    set_short("Mouse");
    set_race("mouse");
    set_long("Cute, little grey mouse. It looks harmless.");
    // set(NPC_NOT_AGGRESSIVE);
    set_wander(11);
}

/* Redefine random_move(): don't wander out of own level */
random_move()
{
    command(({"north","south","east","west",
	"northwest","southwest","northeast","southwest"})[random(8)]);
}


