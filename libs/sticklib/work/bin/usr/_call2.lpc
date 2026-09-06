// Enhanced a bit 21-Sep-98, Doomdark.

#include <cmd.h>


nomask status
call2_cmd(string str, object me)
{
    string tmp;

    if (!CHECK) return 0;

    if (str && sscanf(str, "%s %s", tmp, str)) {
	object ob;
	mixed arg;
	int i;

	if (ob = get_object(tmp)) {
	    if (sscanf(str, "%s %s", str, arg) &&
	      sscanf(arg, "%d%s", i, tmp) && tmp == "")
	    {
		arg = i;
	    }
	    if (!function_exists(str, ob)) {
		notify_fail(sprintf("No function '%s' in '%s'.\n",
		    str, object_name(ob)));
		return 0;
	    }
	    arg = (mixed)call_other(ob, str, arg);
	    me->tell_me(sprintf("Returns: %O.", arg));

	    return 1;
	}
	notify_fail(sprintf("Can't find object '%s'.\n", tmp));
	return 0;
    }
    notify_fail("Usage: call <object> <function> [argument]\n");
}
