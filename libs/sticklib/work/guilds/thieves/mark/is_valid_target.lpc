#include <living_defs.h>

/* It's query_dead(), not dead()! Fixed by Graah 23-Jan-96 */

status
is_valid_target(object ob)
{
    string sh;

    if (!ob)
    {
	return 0;
    }

    if (!living(ob) ||
      !ob->query(LIV_IS_PLAYER_OR_NPC) ||
      (string)ob->query_name() == "Leo")
    {
	notify_fail("You can't do that!\n");
	return 0;
    }

    if (((string)ob->query_real_name() == "guest") ||
      ((sh = (string)ob->short()) &&
	(sh == "Tim the Sorcerer" ||
	  sh == "Santa Claus" ||
	  sh == "Wizard (grey)")))
    {
	notify_fail("That is not allowed!\n");
	return 0;
    }

    if (ob->query_dead())
    {
	notify_fail("But that person is dead!\n");
	return 0;
    }

    return 1;
}
