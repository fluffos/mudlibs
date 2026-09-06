#include <npc.h>

/* Make thieves train somewhere else. */
int
prevent_stab(object att)
{
    if ((int)att->query_level() > 15)
    {
	att->tell_me("The pigeon flies away from you in panic. \
You know, pigeons have almost 360-degree vision, and are \
almost impossible to surprise.");
	return 1;
    }
    return 0;
}

void
create_monster()
{
    set_level(1);
    set_name("pigeon");
    set_short("Pigeon");
    set_race("bird");
    set_long("This pigeon looks very dirty and even diseased.. it might \
be a good idea to not touch it.");
    // set(NPC_NOT_AGGRESSIVE);
    load_chat(7, ({
	"Pigeon coos.",
	"Pigeon picks up some bread crumbs.",
	"Pigeon shits.",
	"Suddenly, pigeon flaps it's wings loudly.",
	"Suddenly, pigeon takes a short flight and shits upon you.",
	"Pigeon takes a sand bath. It doesn't make it any cleaner.",
	"Pigeon pecks an insect.",
	"Pigeon pecks your foot."}));
    set_wander(11);
}
