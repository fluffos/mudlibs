// CHANGELOG
// Written by Chopin 21-Apr-98

// Use this command to report changes you have made in guild code or in the lib

#include <cmd.h>
#include <guild.h>
#include <coder_levels.h>

#define LOG_DIR "/log/changelog/"
#define ALL_LOG LOG_DIR "all"
#define LOGS ({ GN_PRIEST, GN_THIEF, "lib" })

#define LAST_AMOUNT 5


void show_reports(object pl, string fname, int amount) {
    int i, max, columns, time;
    string str, name, msg;

    max = file_lines(fname);
    if(!max) {
	pl->tell_me("Log is empty.");
	return;
    }
    columns = pl->query_env("columns");
    if(!columns) columns = 80;

    if(amount == -1  || max < amount)
	amount = max;
    str = "";
    for(i = max - amount + 1; i <= max; i++) {
	if(sscanf(read_file(fname, i, 1), "%d#%s#%s", time, name, msg) == 3)
	    str += sprintf("<%d> %s %s:\n%-=*s\n\n", i, ctime(time),
	      capitalize(name), columns, msg);
    }
    pl->more(explode(str, "\n"));
}

void show_reports_from_all(object pl) {
    int i, max, columns, amount, time;
    string str, log, name, msg;

    amount = LAST_AMOUNT;
    max = file_lines(ALL_LOG);
    if(max < amount) amount = max;

    columns = pl->query_env("columns");
    if(!columns) columns = 80;

    str = "";
    for(i = max - amount + 1; i <= max; i++) {
	if(sscanf(read_file(ALL_LOG, i, 1), "%s#%d#%s#%s", log, time, name, msg) == 4)
	    str += sprintf("(%s) %s %s:\n%-=*s\n\n", log, ctime(time),
	      capitalize(name), columns, msg);
    }
    pl->more(explode(str, "\n"));
}


status changelog_cmd(string str) {
    int n;
    string gname, text, option, name;
    string fname, tmp, *tmps, deleted_line;

    if(!CHECK) return 0;

    notify_fail("Usage: changelog <guild/lib> [report <message>/more/delete]\n");
    if(!str) {
	show_reports_from_all(TP);
	return 1;
    }

    if(sscanf(str, "%s %s %s", gname, option, text) < 3)
	if(sscanf(str, "%s %s", gname, option) < 2)
	    gname = str;

    if(member(LOGS, gname) < 0) return
	notify_fail("First parameter should be " + implode(LOGS, ", ", " or ") + ".\n"),0;
    fname = LOG_DIR + gname;

    if(!option) {
	show_reports(TP, fname, LAST_AMOUNT);
    }
    else {
	switch(option) {
	case "more":
	    show_reports(TP, fname, -1);
	    break;

	case "report":
	    if(!text) return 0;
	    tmp = sprintf("%d#%s#%s\n", time(), TP->query_real_name(), text);
	    write_file(fname, tmp);
	    write_file(ALL_LOG, sprintf("%s#%s", gname, tmp));

	    // let's clean it up every now and then
	    if((n = file_lines(ALL_LOG)) > 3*LAST_AMOUNT) {
		tmp = read_file(ALL_LOG, n - 2*LAST_AMOUNT, 2*LAST_AMOUNT);
		rename(ALL_LOG, ALL_LOG ".tmp");
		write_file(ALL_LOG, tmp);
	    }
	    TP->tell_me("Ok.");
	    break;

	case "delete":
	    if(!text || !(n = to_int(text)))
		return 0;
	    if(!(text = read_file(fname, n, 1)) || text == "")
		return notify_fail("No such report number.\n"),0;
	    if(sscanf(text, "%s#%s#%s", tmp, name, text) < 3)
		return notify_fail("Error in log file.\n"),0;
	    if(name != TP->query_real_name() && TP->query_coder_level() < LVL_COADMIN)
		return notify_fail("You can remove only your own reports.\n"),0;

	    // This will most likely cause errors if the file gets too large :(
	    tmp = read_file(fname);
	    tmps = explode(tmp, "\n");
	    deleted_line = sprintf("%s#%s\n", gname, tmps[n-1]);
	    tmps = tmps[0..n-2] + tmps[n..];
	    rename(fname, fname + ".tmp");
	    write_file(fname, implode(tmps, "\n"));

	    // we have to delete the same line from "all" log too
	    tmp = read_file(ALL_LOG);
	    rename(ALL_LOG, ALL_LOG ".tmp");
	    write_file(ALL_LOG,implode(explode(tmp, deleted_line), ""));

	    TP->tell_me("Ok.");
	    break;

	default:
	    return 0;
	}
    }
    return 1;
}
