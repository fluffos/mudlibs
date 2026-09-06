#include "../priest.h"

status
shoplog_cmd(object who, object sym, string s) {
    string tmp_log;

    if(sym->query_rank()<2) {
	who->tell_me("You have no access to that.");
	return 1;
    }
    if(!s || s != "reset") {
	tmp_log=read_file(SHOPLOG);
	who->more(explode(tmp_log,"\n"));
	return 1;
    }

    if((sym->query_rank() != 4) && (sym->query_rank() <7)) {
	who->tell_me(
	  "You don't have the authority for that.");
	return 1;
    }
    rm(SHOPLOG);
    write_file(SHOPLOG, sprintf("%s reset the log: %s\n",
	capitalize(who->query_real_name()), ctime(time()) ));
    who->tell_me("Treasury log has been reset.");
    return 2;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
