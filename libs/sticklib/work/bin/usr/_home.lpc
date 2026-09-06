#include <cmd.h>
#include <config.h>

nomask int
home_cmd(string str, object me)
{
    string workroom;
    string err;

    if (!CHECK || !me)
	return 0;

    if (!str)
	workroom = PATH_USER + (string)me->query_real_name() + "/workroom";
    else
	workroom = PATH_USER + lower_case(str) + "/workroom";

    err = catch(call_other(workroom, "???"));

    if (err) {
	me->tell_me(sprintf("Error in loading workroom: %s\n", err));
    }

    if (find_object(workroom)) {
	me->move_player("X", workroom);
	return 1;
    }
    me->tell_me("Argh! You are homeless!");
    return 1;
}
