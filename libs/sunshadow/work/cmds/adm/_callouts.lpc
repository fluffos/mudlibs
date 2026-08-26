#include <std.h>

inherit DAEMON;

mixed cmd_callouts(string input) {
    mixed *callouts;
    string *items = ({ });

    callouts = call_out_info();
    if (input) {
        input = lower_case(input);
        callouts = filter_array(callouts, (: regexp(lower_case(identify($1[0])), $(input)) || regexp(lower_case(identify($1[1])), $(input)) :));
    }
    callouts = sort_array(callouts, (: $1[2]==$2[2] ? 0 : $1[2] > $2[2] ? 1 : -1 :));
    if (sizeof(callouts)) {
        foreach (mixed *c in callouts) {
            c[1] = replace_string(c[1], "\n", "\\n");
            c = map(c, (: identify($1) :));
            items += ({ sprintf("%:-40s %:-25s %:-5s", c[0], c[1], c[2]) });
        }
    }

    if (!sizeof(items)) {
        message("system", "No pending callouts.", this_player());
        return 1;
    }
    
    write(sprintf("header row")+"\n"+implode(items, "\n"));
    return 1;
}

int help() {
  write("Command: callouts ([filter])\n\n" +
        "This command lists all the call_outs on the mud.\n" +
        "An optional filter argument allows you to narrow the results down.\n\n" +
        "See man: call_out_info\n"+
        "See also: cache, mstatus, netstat, fdinfo, opcprof, dumpallobj\n"+
        "" );
  return 1;
}