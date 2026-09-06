#include <cmd.h>

nomask int
force_cmd(string str)
{
    string who, what;
    object ob;

    if (!CHECK) return 0;   // checks ti == tp

    notify_fail("Usage: force <who> [to] <what>\n");

    if (!str || str == "")
	return 0;

    if (sscanf(str, "%s to %s", who, what) != 2 &&
      sscanf(str, "%s %s", who, what) != 2)
	return 0;

    if(!ob = present(who, environment(TP)))
	if(!ob = find_player(who))
	    return notify_fail("Could not find "+capitalize(who)+".\n"), 0;

	/* I don't like being forced... //Graah */
    if ((int)TP->query_coder_level() <=
      (int)ob->query_coder_level())
    {
	ob->tell_me(capitalize((string)TP->query_real_name()) +
	  " tried to force you to: " + what);
	TP->tell_me("Failed.");
	return 1;
    }

    ob->tell_me((ob->query_coder_level() ?
	capitalize((string)TP->query_real_name()) :
	(string)TP->query_name()) +
      " forces you to: " + what + "\n");

    /* Forcing to quit causes ob-variable to be zeroed, so... */
    who = (string)ob->query_real_name();

    if(!command(what, ob))
    {
	TP->tell_me("Force failed.");
	return 1;
    }

    TP->tell_me("Ok.");
    /* Added the FORCE log 4.3.1992 //Frobozz */
    log_file("FORCE",capitalize(
	(string)TP->query_real_name())+" forced "+
      capitalize(who) + " to " + what +
      " at "+ctime(time())+"\n");
    return 1;
}
