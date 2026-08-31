#include <std.h>

inherit DAEMON;

int cmd_code() {

    object *ob;
    object tp = this_player();

    ob = users();

    for (int i=0; i<sizeof(ob); i++) {
	if (wizardp(ob[i]) || archp(ob[i])) {         
	    if (in_edit(find_player(ob[i]->query_name())) ) {
		write(ob[i]->query_cap_name() + " " + "File:" + in_edit(ob[i]));
	    }
	}
	return 1;
    }
    return 1;
}
