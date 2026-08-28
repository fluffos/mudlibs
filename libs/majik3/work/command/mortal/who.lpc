#include <security.h>

int record;

create ()
{
    restore_object ("/data/misc/who");
}

int
main(string arg)
{
    string idle, flags, buf;
    int idle_t, j;
    object *list;
    object kludge;

    buf = "^cW^bb" + sprintf ("%-78s", "THE LIST OF USERS LOGGED IN ("
      + query_load_average() + ")") + "^c0\n";

    for (list = users(), j = 0; j < sizeof (list); j++)
    {
	if (list[j]->query_switch()) {
	    kludge = list[j];
	    list[j] = list[j]->query_switch();
	}

	flags = "";
	if (in_edit (list[j]))
	    flags += "E";
	if (in_input (list[j]))
	    flags += "B";

	if (!kludge && query_idle (list[j]) > 60 * 5)
	    flags += "I";

	idle_t = 0;

	if (objectp(kludge))
	    idle_t = query_idle (kludge);
	else
	    idle_t = query_idle (list[j]);

	kludge = 0;

	idle = "";

	if (idle_t > 60 * 60 * 24)
	    idle = "^c1" + sprintf ("%4d", idle_t / (60*60*24)) + "^c0d";
	else if (idle_t > 60 * 60)
	    idle = "^c1" + sprintf ("%4d", idle_t / (60*60)) + "^c0h";
	else if (idle_t < 60)
	    idle = "^c1" + sprintf ("%4d", idle_t) + "^c0s";
	else
	    idle = "^c1" + sprintf ("%4d", idle_t / 60) + "^c0m";

	if(!list[j]->query_name()||list[j]->query_name()=="")
	{
	    continue;
	}

	if (list[j]->query_security() /*&& THIS->query_security()*/)
	{
	    buf += "^c0^cp<^c0^c1" + sprintf("%3s",flags) + "^c0^cp>^c0 " +
	    sprintf("%-64s (%s)\n",list[j]->short(),idle);
	}
	else if (!list[j]->query_security())
	{
	    buf += "^c0^cc[^c0^c1" + sprintf("%3s",flags) + "^c0^cc]^c0 " +
	    sprintf("%-64s (%s)\n",list[j]->short(THIS),idle);
	}
    }
    if (j > record) {
	record = j;
	save_object ("/data/misc/who");
    }

    buf += "^c1"+ j + "^c0 players online (best: ^c1" + record +
    "^c0 players).\n";
    message ("0", buf, THIS);
    return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Who shows the players who are currently logged on.";
}

query_see_also()
{
  return "users(1), friends(1), friend(1)";
}

query_position()
{
  return POS_RESTING;
}

