#include <npc.h>
#include "../DEFS.h"

/* Make thieves train somewhere else. */
int
prevent_stab(object att)
{
    if ((int)att->query_level() > 15)
    {
	att->tell_me("The duck ducks your stab (they have an almost \
360-degree vision, you know...");
	return 1;
    }
    return 0;
}

void
create_monster()
{
    set_level(1);
    set_name("duck");
    set_id(({ "happy duck", "happy-looking duck" }));
    set_short("Happy-looking duck");
    set_long("A happy-looking duck is swimming around in the pool.");
    set_race("bird");
    set_dead_ob(this_object());
}

monster_died(killer) {
    if (!present("wishbone", environment()))
	move_object(clone_object(OBJ_DIR+"wishbone"), environment());
    return 0;
}
