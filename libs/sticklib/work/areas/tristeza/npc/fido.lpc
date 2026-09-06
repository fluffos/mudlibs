#include <npc.h>

/* Make thieves train somewhere else. */
int
prevent_stab(object att)
{
    if ((int)att->query_level() > 15)
    {
	att->tell_me("If you stab that, you'd get fleas!");
	return 1;
    }
    return 0;
}

void
create_monster()
{
    set_level(3);
    set_name("beastly fido");
    set_short("Beastly Fido");
    set_race("dog");
    set_long("Fido is a small dog that has a foul smell and pieces of \
rotten meat hanging around his teeth.");
    set_id(({ "beastly", "fido" }));

    // set(NPC_NOT_AGGRESSIVE);
    set_wander(11);
}
