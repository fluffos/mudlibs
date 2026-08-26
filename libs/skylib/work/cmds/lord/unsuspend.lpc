/*  -*- LPC -*-  */

#include <parser.h>
#include <access.h>

inherit COMMAND_BASE;

mixed cmd(string str) {
    if (this_player() != this_player(1))
        return 0;
    if (!lordp(geteuid(previous_object())))
        return notify_fail("You must be a lord to unsuspend someone.");
    notify_fail("We failed!\n");
    if (!BASTARDS_H->unsuspend_person(str))
        return 0;
    write(str+" unsuspended.\n");
    return 1;
} /* cmd() */

int help() {
    return notify_fail("Syntax: unsuspend <name>.\n");
}

mixed *query_patterns() {
    return ({ "<string>", (: cmd($4[0]) :), });
} /* query_patterns() */
