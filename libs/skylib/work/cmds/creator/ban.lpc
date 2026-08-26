
#include <parser.h>
#include <access.h>

inherit COMMAND_BASE;

/*
 * This will ban a site
 */
mixed cmd(string ip, string reason) {
    seteuid("Root");

    if (this_player() != this_player(1))
        return 0;

    if(!lordp(geteuid(previous_object())))
        return notify_fail("Only lords can do that.\n");

    if(strsrch(ip, "*") != -1)
        return notify_fail("This command does not take wildcards.\n");

    if (!BASTARDS_H->change_access(explode(ip, "."), "*", 2, reason,
        time() + (60*60*2))) {
        write("Error changing permissions.\n");
        return 0;
    }

    write("Site banned.\n");
    return 1;
} /* cmd() */

int help() {
    return notify_fail(
      "Syntax: ban <ip number> <reason>\n");
}
mixed *query_patterns() {
    return ({ "<word'address'> <string'reason'>",
      (: cmd($4[0], implode($4[1..], "")) :),
      "help", (: help() :)
    });
} /* query_patterns() */
