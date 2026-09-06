#include "../dirs.h"

status
join_cmd(object mark, object who, string str)
{
    object ob, form;
    string n;

    if (!who || !mark) return 0;

    if (!str)
	return notify_fail("Join who?\n"), 0;

    if ((int)mark->query_guildmaster() < 1)
	return notify_fail("Only enforcers and higher can join people.\n"), 0;

    if (!(ob = present(str, environment(who))))
    {
	who->tell_me("There is no one called \"" + str + "\" here.");
	return 1;
    }

    if (!(form = present("thief_accept_form", ob)))
    {
	who->tell_me((string)ob->query_name() +
	  " is not carrying the official form.");
	return 1;
    }

    if (form->signed_ok(who))
    {
	call_other(GDIR + "rooms/entry", "join_to_guild", ob);
	THIEF_LOG("JOIN_LOG",
	  capitalize((string)ob->query_real_name()) +
	  " joined by " +
	  capitalize((string)who->query_real_name()) +
	  " at " + ctime(time()) + "\n");
	destruct(form);
    }

    return 1;
}
