#include <cmd.h>
#include <daemons.h>
#include <coder_levels.h>

nomask int
peace_cmd(string s, object me)
{
    int i, cl;

    if (!me && !(me = this_player()))
	return notify_fail("Nasty you...\n"), 0;

    if (me != this_player()) return notify_fail("Sure...\n"), 0;

    if (!s)
    {
	me->tell_me(PEACE_D->query_peace() ?
	  "Peace is upon the world. Player killing is not possible." :
	  "There is no Peace in this world! Player kills are allowed.");
	return 1;
    }

    cl = (int) me->query_coder_level();

    if (cl < LVL_COADMIN) {
	me->tell_me("This is allowed for (co-)admins only.");
	return 1;
    }

    if (s == "0" || s == "no" || s == "-clear" || s == "off")
    { 
	me->tell_me("Ok.");
	PEACE_D->set_peace(0);
	log_file("PEACE", (string)TP->query_real_name() + " lifted peace at " +
	  ctime(time()));
    }
    else if (s == "1" || s == "on" || s == "yes")
    {
	me->tell_me("Ok.");
	PEACE_D->set_peace(1);
	log_file("PEACE", (string)TP->query_real_name() + " set peace at " +
	  ctime(time()));
    }
    else
	me->tell_me("What's that \"peace " + s + "\" supposed to mean?");

    return 1;
}
