

#include <cmd.h>

varargs nomask status
clothes_cmd(string arg, object me)
{
    object who;
    string s;

    if (!me && !(me = this_player())) return 0;

    if (me -> test_dark()) return 0;

    /* Why shouldn't we use this cmd even if paralyzed? */
    if (arg) {
	who = present(lower_case(arg),environment(me));
	if (!who) {
	    me -> tell_me("You can't see any " + arg + " around here.");
	    return 1;
	}
    } else who = me;

    if (!living(who) || who->query_npc()) {
	if (!(s = (string) who -> query_pronoun())) s = "it";
	me -> tell_me(s+" isn't wearing any special clothing.");
	return 0;
    }

    if (!(s = (string)who->query_clothing_text())) s = "Nothing.";

    me->tell_me("Clothing "+(string)who->query_name(me,0)+" is wearing:\n"+s);

    return 1;
}
