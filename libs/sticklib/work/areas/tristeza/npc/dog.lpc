#include <npc.h>

/* Make thieves train somewhere else. */
int
prevent_stab(object att)
{
    if ((int)att->query_level() > 15)
    {
	att->tell_me("If you'd stab that, you'd get fleas!");
	return 1;
    }
    return 0;
}

void
create_monster()
{
    set_level(3);
    set_name("dog");
    set_short("Stray dog");
    set_race("dog");
    set_long("This poor, flea-ridden mutt has been abandoned by someone. \
It looks very thin and hungry.");
    // set(NPC_NOT_AGGRESSIVE);
    load_chat(8, ({
	"Dog whimpers.",
	"Dog looks sadly at you.",
	"Dog drools on your shoes.",
	"Dog smells your pockets.",
	"Dog looks very hungry.",
	"Dog eats some scrap.",
	"Dog tries to snatch an insect.",
	"Dog scratches its back with its hind leg."}));
    set_wander(11);
}
