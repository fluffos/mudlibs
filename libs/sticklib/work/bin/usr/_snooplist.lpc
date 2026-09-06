#include "/sys/interactive_info.h"

#include <cmd.h>
#include <coder_levels.h>

nomask int
snooplist_cmd(string s, object me)
{
    object sn,*ulist;
    int i, cl;
    string text;

    if (!me && !(me = this_player())) return
	notify_fail("Nasty you...\n"), 0;
    if (me != this_player()) return notify_fail("Sure...\n"), 0;
    cl = (int) me->query_coder_level();
    if (cl < LVL_COADMIN) {
	me->tell_me("This command is for (co-)admins only.");
	return 1;
    }
    ulist = users();
    for(i = sizeof(ulist) - 1; i >= 0; i--)
	if ((sn=interactive_info(ulist[i], II_SNOOP_NEXT))
	  && ((cl >= LVL_COADMIN) ||
	    ((int)sn->query_coder_level()<= cl))) {
	    if (!text) text = ""; else text += "\n";
	    text += capitalize((string)sn->query_real_name()) +
	    " is snooping " +
	    capitalize((string)ulist[i]->query_real_name());
	}
    if (!text) me->tell_me("No-one is snooping at the moment.");
    else me->tell_me(text);
    return 1;
}
