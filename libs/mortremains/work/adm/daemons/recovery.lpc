// recovery daemon.
// Just in case.

#include <uid.h>
#include <registry.h>
#include <daemons.h>
#include "/u/c/cyanide/debug.h"

void create() {
    seteuid(ROOT_UID);
}

int recover() {
    string *lines;
    int i, sz, flag, count = 0;
    string email, name;

    lines = explode(read_file("/open/reg.t"), "###\n");
    sz = sizeof(lines);
    DEBUG("0 = "+lines[0]+", SZ-1 = "+lines[sz-1]+"\n");

    for (i=1; i<sz; i++) {
	sscanf(lines[i], "%s %s", name, email);
	name = lower_case(name);
	flag = REGISTRY_D->add_player(email, name);

	if (flag==DAEMON_NOT_ACTIVE) {
	    write("ERROR: Daemon not active error.\n");
	    break;
	}

	switch(flag) {
	case OKAY : flag++; break;
	case NAME_IN_USE : write(name+": Name in use.\n"); break;
	case TOO_MANY_NAMES : write(name+": Too many names.\n"); break;
	default : write(name+": General Error.\n");
	}
    }

    write("Recover: "+sz+" attempted. "+flag+" successful.\n");

    return 1;        
}


/* EOF */
