/*
 * Called/used now and then when hungry and/or thirsty
 *
 * - spell points drain
 * - can't carry so much any more
 * - when moving, goes in wrong direction sometimes
 * - drops things now and then
 * - rest or sit goes on sometimes
 * - invisibility breaks (lords)
 * - can't see for a short while (C_BLINDNESS)
 * - loses consciousness for a short while (C_STUNNED)
 *   (You faint from lack of food.)
 * - if sees drink or food, automatically uses it
 *
 */
#include <conditions.h>

nomask void
hunger_effect(object ob)
{
    int sev;

    /* NPCs and monsters don't get the effects. Perhaps some day. */
    if (!ob || !living(ob) || ob->query_npc()) return 0;

    /* Severity? */
    sev = (int) ob->query_some_func_which_returns_hunger_severity_level();

    switch(random(sev)) {
    case 0: /* SP drain */
	if ((int)ob->query_sp() > 0)
	    ob->add_sp(-(5 + random(sev)));
	ob->tell_me("Your head spins due lack of food.\n");
	break;
    case 1: /* Faint */
	ob->set_condition(C_UNCONSCIOUS, 2 + random(sev));
	ob->tell_me("You faint from lack of food.\n");
	break;
    default:
	ob->tell_me(
	  "You feel very hungry. You'd better find something to eat soon.\n");
	break;
    }
}

nomask void
thirst_effect(object ob)
{
}
