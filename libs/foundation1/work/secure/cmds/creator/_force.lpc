//      /bin/dev/_force.c
//      from the Nightmare Mudlib
//      force a player or monster to act
//      created by Descartes of Borg 930824

#include <std.h>

inherit DAEMON;

int cmd_force(string str) {
    string who, act;
    object ob;
    int x;

    if(!str || (sscanf(str, "%s to %s", who, act) != 2 &&
      sscanf(str, "%s %s", who, act) != 2)) {
        notify_fail("Correct syntax: <force [who] to [what]>\n");
        return 0;
    }
    if(!(ob = find_living(who = lower_case(who)))) {
        notify_fail("Could not find anything living called "+str+".\n");
        return 0;
    }
    if(ob->is_player() && !adminp(previous_object())) {
        notify_fail("You are not allowed to do that!\n");
        return 0;
    }
    if(member_group(ob, "SUPERUSER")) return 1;
    catch(x=(int)ob->force_me(act));
    if(!x) message("my_action", "You failed to force "+who+" to "+act+".",
      this_player());
    else message("my_action", "Ok.", this_player());
    return 1;
}

void help() {
    message("help",
      "Syntax: <force [who] (to) [what]>\n\n"
      "Forces a player or monster to perform the act specified.  Only "
      "arches may force players.  Do not abuse this power.", this_player()
    );
}
