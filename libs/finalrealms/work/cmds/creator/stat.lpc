/* 
 * Externalize by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string str, object me) {
    object *ob;
    mixed *ob1;
    string s,bing;
    int i,j;

    bing = "";
    ob = wiz_present(str, me);
    if (!sizeof(ob)) {
	write("No such object.\n");
	return 1;
    }
    for (j=0;j<sizeof(ob);j++) {
	ob1 =ob[j]->stats();
	if (!pointerp(ob1))
	    continue;
	s = "";
	for (i=0;i<(sizeof(ob1)-1);i++)
	    if(ob1[i])
		if(ob1[i][0])
		    s += ob1[i][0] + ": "+ob1[i][1]+"\n";
	bing += sprintf("%-*#s\n\n\n", me->query_cols(), s);
    }
    me->more_string(bing);
    me->set_trivial_action();
    return 1;
} /* show_stats() */


