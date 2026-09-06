#include <cmd.h>
#include <skills.h>

/* Ty|n orjat sorron y|st{ nouskaa */
/* T{{ on viimeinen taisto */

nomask int
skdel_cmd(string arg)
{
    string skname;

    if (!arg) {
	notify_fail("Usage: skdel <skillname>\n");
	return 0;
    }

    skname = lower_case(arg);

    if (!TP->query_liv_Skill(skname)) {
	notify_fail("You don't have skill \"" + skname + "\".\n");
	return 0;
    }

    write("Removing skill \"" + skname + "\", score " +
      (int)TP->query_skill_value(skname) + "...\n");

    if (!TP->set_skill(skname, 0))
	write("FAILED!\n");
    else
	write("Ok.\n");

    return 1;
}
