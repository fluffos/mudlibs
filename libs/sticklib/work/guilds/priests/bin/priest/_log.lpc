#include "../../priest.h"

#define LOG_NAME 0
#define ACCESS_RANK 1
#define CAN_BE_RESET 2
#define WHO_CAN_RESET 3

#define MAX_SIZE 40000
#define SHOWLINES 20

mapping log_info;


create() {
    log_info = ([
      // rank required to read; can be reset; who can reset
      // (0 = all who can read, pos. int. = officer rank & >=vg)
      "shop" : "shoplog"; 2; 1; 4,
      "cash" : "cash_log"; 2; 1; 4,
      "raid" : "raiders"; 2; 1; 0,
      "join" : "new_priests"; 2; 0; 0,
      "pool" : "moonwell"; 2; 1; 4,
      "excom": "excom_log"; 2; 0; 0,
    ]);
}

string usage() {
    return "Usage: priest log <log_name> [reset|more]";
}

status
log_cmd(object who, object sym, string args) {
    string log, cmd, tmp, fname;
    int r, s, lines;

    if(!args) {
	this_player()->tell_me(usage());
	return 1;
    }

    args = lower_case(args);
    if(sscanf(args, "%s %s", log, cmd) != 2)
	log = args;

    if(!member(log_info, log))
	return notify_fail("No such log.\n"),0;

    fname = PRIEST_LOG_DIR + log_info[log, LOG_NAME];
    r = sym->query_rank();
    if(r < log_info[log, ACCESS_RANK])
	return notify_fail("You have no access to that.\n"),0;

    if(!cmd) {
	if(file_size(fname) <= 0)
	    return notify_fail("The log is empty.\n"),0;
	lines = file_lines(fname);
	if(lines > SHOWLINES) {
	    tmp = read_file(fname, lines-SHOWLINES+1, SHOWLINES);
	    lines = SHOWLINES;
	}
	else tmp = read_file(fname);
	tmp = sprintf("The last %d events in %s log:\n%s", lines, log, tmp);
	who->tell_me(tmp);
	return 1;
    }

    switch(cmd) {
    case "reset":
	if(!log_info[log,CAN_BE_RESET])
	    return notify_fail("That log can not be reset.\n"),0;
	s = log_info[log, WHO_CAN_RESET];
	if((r<VG_RANK) && s && (r!=s)) return
	    notify_fail("You don't have the authority for that.\n"),0;

	rm(fname);
	write_file(fname,
	  sprintf("%s reset the log: %s\n",
	    capitalize(who->query_real_name()), ctime(time()) ));
	who->tell_me(sprintf("Log \"%s\" has been reset.", log));
	break;

    case "more":
	if(file_size(fname) > MAX_SIZE)
	    return notify_fail("Log file is too large. Try resetting it \
or complaining to someone.\n"),0;
	who->more(explode(read_file(fname), "\n"));
	break;

    default:
	return notify_fail("No such option.\n"),0;
    }
    return 1;
}


int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}

