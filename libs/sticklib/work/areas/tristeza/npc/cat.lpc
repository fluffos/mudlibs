#include <npc.h>

/* Make thieves train somewhere else. */
int
prevent_stab(object att)
{
    if ((int)att->query_level() > 15)
    {
	att->tell_me("The cat is much too small and quick to be stabbed.");
	return 1;
    }
    return 0;
}

void
create_monster()
{
    set_level(2);
    set_name("cat");
    set_short("Stray cat");
    set_race("cat");
    set_long("This scrawny, little kitten has been abandoned by someone. \
It looks very thin and hungry.");
    // set(NPC_NOT_AGGRESSIVE);
    load_chat(8, ({
	"Cat meows loudly.",
	"Cat purrs.",
	"Cat rubs its head against your leg.",
	"Cat stretches it's body.",
	"Cat plays with an insect.",
	"Suddenly the cat scratches you.",
	"Cat slaps your foot playfully.",
	"Cat plays with a pigeon feather.",
	"Cat hisses loudly!",
	"Cat falls asleep."}));
    set_wander(11);
}
