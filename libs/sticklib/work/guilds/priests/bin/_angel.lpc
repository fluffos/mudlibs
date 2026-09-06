#include <living_defs.h>
#include "../priest.h"

status
angel_cmd(object who, object sym, string str) {
    string cmd, tar_name;
    object target, *slaves,  ob;
    int i;

    if(who->query_hp()<0)
	return notify_fail("You can't do that while unconscious.\n"),0;
    if(sym->query_banned())
	return notify_fail("You wouldn't dare break the traditional \
prohabition against a new priest using spells and powers of the Order. \
You must first talk to the Vicegerant.\n"),0;
    if(sym->query_casting() || sym->query_mixing())
	return notify_fail("You can not concentrate on so much at once.\n"),0;
    if(!who->query_can_move())
	return notify_fail("You can't move to do that!\n"),0;

    notify_fail("Type 'advice angel' to get help on the usage.\n");
    if(!str) return 0;

    if(sscanf(str, "%s %s", cmd, tar_name) !=2)
	cmd = str;
    if(!cmd) return 0;

    slaves = SLAVE_D->query_slaves(who);
    for(i=sizeof(slaves);--i>=0;) {
	ob = slaves[i];
	if(ob->is_priest_angel())
	    break;
    }
    if(!ob) return notify_fail("You have to first pray for " GOD_NAME " \
that He would send one to you.\n"),0;
    return ob->do_cmd(cmd, tar_name);
}

