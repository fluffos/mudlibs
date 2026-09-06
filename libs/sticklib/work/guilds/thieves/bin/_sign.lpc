#include "../dirs.h"

status
sign_cmd(object mark, object who, string arg)
{
    object ob, form;
    string n;

    if (!who) return 0;

    if (!arg || sscanf(arg, "form for %s", n) != 1)
    {
	notify_fail("Sign...? What do you mean? ('sign form for someone'?)\n");
	return 0;
    }

    if (!(ob = present(n, environment(who))))
    {
	who->tell_me("There is no one called \"" + n + "\" here.");
	return 1;
    }

    if (mark->query_guildmaster() < 1)
	return notify_fail("Currently only enforcers and higher can sign.\n"), 0;

    if (!(form = present("thief_accept_form", ob)))
    {
	who->tell_me((string)ob->query_name() +
	  " is not carrying the official form.");
	return 1;
    }

    if (form->signed_by(who))
    {
	who->tell_me("Ok. You sign " + (string)ob->query_name() +
	  "'s application!");
	ob->tell_me((string)who->query_name() +
	  " signed your application!");

	THIEF_LOG("SIGN_LOG",
	  capitalize((string)who->query_real_name()) +
	  " signed for " + capitalize((string)ob->query_real_name()) +
	  " at " + ctime(time()) + "\n");
    }

    return 1;
}
