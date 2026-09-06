#include "../dirs.h"

status
form_cmd(object mark, object who, string arg)
{
    object ob, form;

    if (!who) return 0;

    if (!arg)
    {
	notify_fail("Check whose form?\n");
	return 0;
    }

    if (!(ob = present(lower_case(arg), environment(who))))
    {
	who->tell_me("There is no one called \"" + arg + "\" here.");
	return 1;
    }

    if (!(form = present("thief_accept_form", ob)))
    {
	who->tell_me((string)ob->query_name() +
	  " is not carrying the official form.");
	return 1;
    }

    this_player()->tell_me("Ok, you read " +
      (string)ob->query_possessive() + " form...\n\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    form->read_cmd("form");

    this_player()->tell_me("\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    return 1;
}
