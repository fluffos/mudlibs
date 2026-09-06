#include "../priest.h"

status
raidlog_cmd(object who, object sym, string s) {
    string tmp_log;

    if(sym->query_rank()<5){
	who->tell_me("You have no access to that.");
	return 1;
    }
    if(!s || s != "reset") {
	tmp_log=read_file(RAIDLOG);
	who->more(explode(tmp_log,"\n"));
	return 1;
    }
    rm(RAIDLOG);
    write_file(RAIDLOG, sprintf("%s reset the log: %s\n",
	capitalize(who->query_real_name()), ctime(time()) ));
    who->tell_me("Raid log has been reset.");
    return 2;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
