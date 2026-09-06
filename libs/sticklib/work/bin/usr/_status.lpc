#include <daemons.h>

int
status_cmd(string arg, object me)
{
    mapping x;
    string *ind;
    int i;
    mixed *val;
    string *s;
    string t;
    if (!me && !(me = this_player())) return 0;
    if (!arg || !sscanf(arg, "commands %s", t))
	return notify_fail("Status commands <path>?\n"), 0;
    if (!(x = (mapping) CMD_D -> query_cmd_stats(t)))
	return notify_fail("No commands linked to that path!\n"), 0;
    ind = m_indices(x);
    val = m_values(x);
    s = allocate(sizeof(ind));
    while (i < sizeof(ind)) {
	if (!pointerp(val[i])) s[i] = "-ERROR-";
	else
	    s[i] = sprintf("%s: used %d times, total ecost: %O, avg. ecost: %O.",
	      val[i][0],
	      val[i][3], val[i][4], val[i][4] / (val[i][3] ? val[i][3] : 1));
	i++;
    }
    s = sort_array(s, #'>);
    me->more(s);
    return 1;
}
