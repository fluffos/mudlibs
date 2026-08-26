#include <parser.h>
#include <access.h>

inherit COMMAND_BASE;

private int do_suspend(string, int, string);

// The lord version of suspend.
mixed cmd(string name, int tim, string reason) {
    if (this_player() != this_player(1)) {
        return 0;
    }

    if (!lordp(geteuid(previous_object()))) {
        return notify_fail("You must be a lord to suspend "
          "someone.");
    }

    return do_suspend(name, tim, reason);
}

// The normal creator suspend
int suspend(string who, string reason) {
    if(this_player() != this_player(1))
        return 0;

    if(!lordp(geteuid(previous_object())) &&
      !DOMAIN_H->query_member("liaison",geteuid(previous_object())))
        return notify_fail("Only liaisons can do that.\n");

    return do_suspend(who, 2, reason);
}

#ifdef 0
// The liaison multiplayer suspend
int suspend_multi(string who) {
    if(this_player() != this_player(1))
        return 0;

    if (!lordp(geteuid(previous_object()))) {
        return notify_fail("You must be a lord to suspend "
          "someone for multiplaying.");
    }

    if(!DOMAIN_H->query_member("liaison",TP->query_name()))
        return notify_fail("Only liaisons can do that.\n");

    return do_suspend(who, 14*24, "Multiplaying");
}
#endif

private int do_suspend(string name, int tim, string reason) {
    notify_fail("We failed!\n");

    if (!BASTARDS_H->suspend_person(name, tim*60*60, reason)) {
        return 0;
    }

    write(name+" suspended until "+ctime(time()+tim*60*60)+"\n");
    return 1;
}

int help() {
    if(!lordp(geteuid(previous_object())) &&
      !DOMAIN_H->query_member("liaison",TP->query_name()))
        return notify_fail("");

    write("suspend <name> <reason> -- will suspend a player for 2 hours.\n");
    write("suspend <name> multiplaying -- will suspend a multiplayer for "
      "2 weeks.\n");

    if (lordp(geteuid(this_player())))
        write("suspend <name> <time> <reason> where time is in hours.\n");

    return 1;
}

mixed *query_patterns() {
    return ({ "<word'player'> <number'time'> <string'reason'>",
      (: cmd($4[0], $4[1], implode($4[2..], " ")) :),
      "<word'player'> <string'reason'>",
      (: suspend($4[0], implode($4[1..], " ")) :),
#ifdef 0
      "<word'player'> multiplaying",
      (: suspend_multi($4[0]) :),
#endif              
      "help", (: help() :) });
} /* query_patterns() */
