/* Equipment list (a la DikuMUD) */



#include <cmd.h>
#include <macros.h>
#include <std_lib>

varargs nomask status
eq_cmd(string arg, object me)
{
    int i, flag;
    object who,*ob;
    string str, txt;

    if (!me && !(me = this_player())) return 0;

    if (me -> test_dark()) return 0;

    if (arg) {
	who = present(lower_case(arg),environment(me));
	if (!who) {
	    me -> tell_me("You can't see any "+arg+ " around here.");
	    return 1;
	}
    } else who = me;

    if (living(who)) {
	if (me != who) {
	    txt = "\t\n"+capitalize(arg) + " is using:";
	    if (!((int)me->query_coder_level())) who -> tell_me(
		  (string)me->query_name(0,me)+" looks at your equipment.");
	} else txt = "You are using:";

	flag = 0;
	ob = all_inventory(who);
	if (ob)
	    for(i = sizeof(ob) - 1; i >= 0; i--) {

		if (!ob[i] -> is_used()) continue;

		str = (string)ob[i]->short(0,me);
		if (str) {
		    txt += "\n" + str + ".";
		    flag = 1;
		}
	    }

	if (!flag) txt += "\nNothing.";

    } else txt = "That doesn't seem to use any equipment.";

    me -> tell_me(txt);

    return 1;
}
