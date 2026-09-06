#include "../priest.h"

status
cashlog_cmd(object who, object sym, string s) {
    string tmp_log;

    if(sym->query_rank()<2) {
	who->tell_me("You have no access to that.");
	return 1;
    }
    if(!s || s != "reset") {
	tmp_log=read_file(CASHLOG);
	if(!tmp_log)
	    return notify_fail("It's empty.\n"),0;
	who->more(explode(tmp_log,"\n"));
	return 1;
    }

    if((sym->query_rank() != 4) && (sym->query_rank() <10)) {
	who->tell_me(
	  "Only the Elector secularus or a Guild Admin can reset the log.");
	return 1;
    }
    rm(CASHLOG);
    write_file(CASHLOG, sprintf("%s reset the log: %s\n",
	capitalize(who->query_real_name()), ctime(time()) ));
    who->tell_me("Treasury log has been reset.");
    return 2;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
