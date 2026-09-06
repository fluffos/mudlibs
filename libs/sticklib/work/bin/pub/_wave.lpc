#include <cmd.h>

inherit "/lib/find_name";

/* Wave feeling is so complicated that it has to be done here */

varargs status
wave_cmd(string arg, object me)
{
    object who;
    string x, wn, *cl;
    mapping c;
    int i, s;

    if (!me && !(me = this_player())) return 0;

    if (!me->query_can_move()) return 0;

    if (arg) {
	if (!(who = present(lower_case(arg), me)))
	    who = present(lower_case(arg), environment(me));
	if (who) wn = (string) who->query_name(0, me);
	else {
	    c = (mapping)me->query_clothes();
	    cl = m_indices(c);

	    wn = 0;

	    if (cl && (s = sizeof(cl)) > 0) {
		for (i = 0; i < s; i++) {
		    if (member(explode(c[cl[i]][0], " "),
			lower_case(arg)) != -1) {
			wn = c[cl[i]][0];
			break;
		    }
		}
	    }

	    if (!wn) {
		notify_fail("You can't see any " + arg + " around here.\n");
		return 0;
	    }
	}
    }

    if (!who && !wn) {
	me -> tell_me("You wave happily.");
	environment(me) -> tell_here((string)me->query_name(0, me)
	  +" waves happily.", me);
	return 1;
    }

    if (who && living(who)) {
	string s2, s3;
	s2 = (string) me -> query_name(0, who);
	s3 = (string) who -> query_name(0, me); 
	who -> tell_me(s2 + " waves goodbye to you.");
	me -> tell_me("You wave goodbye to " + s3 +".");
	environment(me)->tell_here(s2+" waves goodbye to "+s3+".", ({who, me }));
	return 1;
    }

    if (!wn) return notify_fail("Waving invisible things is silly.\n"), 0;

    x = ({" furiously"," in the air"," clumsily"," happily",
      ". How silly"})[random(5)];

    me -> tell_me("You wave " + wn + x + ".");
    environment(me) -> tell_here((string)me->query_name(0, me)
      + " waves " + wn + x + ".", me);

    return 1;
}
