#include "../priest.h"

status
excom_cmd(object who, object sym, string str) {
    string name, reason;
    if(sym->query_rank()<5)
	return notify_fail("You don't have that power.\n"),0;

    if(!str) {
	who->tell_me(EXCOM_D->excoms());
	return 1;
    }

    if(sscanf(str, "%s %s", name, reason) != 2) {
	return notify_fail("usage: excom <name> <reason>\n"),0;
    }
    if(!FINGER_D->do_load(name))
	return notify_fail("No such player.\n"),0;
    name = lower_case(name);
    if(EXCOM_D->excom(name)) {
	write_file(PRIEST_DIR "log/excom_log",
	  sprintf("%s %s excomed %s, reason: %s\n",
	    ctime(time()), capitalize(who->query_real_name()),
	    capitalize(name), reason));
	who->tell_me("Ok, you excommunicated " + capitalize(name) + ".");
    } else {
	write_file(PRIEST_DIR "log/excom_log",
	  sprintf("%s %s absolved %s, reason: %s\n",
	    ctime(time()), capitalize(who->query_real_name()),
	    capitalize(name), reason));
	who->tell_me("Ok, you unbanished " + capitalize(name) + ".");
    }
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
