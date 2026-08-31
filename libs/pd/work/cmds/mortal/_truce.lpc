//      truce.  removes hunters.
//      by nightshade.

#include <daemons.h>
#include <std.h>

inherit DAEMON;

mapping waiting;       // id = person initiated, value = person to accept

int cmd_truce(string str) {
    object *hunters;
    int i, flag;

    if(!str)
      return notify_fail("Truce whom?\n");

    if(!waiting)
      waiting = ([]);

    if(waiting[str] == this_player()->query_name() && find_player(str)) {
        write("You accept a truce with "+find_player(str)->query_cap_name()+".");
        message("info", this_player()->query_cap_name()+" accepts your truce.", find_player(str));
        this_player()->stop_hunting();
        find_player(str)->stop_hunting();
        return 1;
    }

    if(!find_player(str)) {
        write("They are not in this reality!");
        return 1;
    }
    flag = 0;
    hunters = this_player()->query_hunted();
    i = sizeof(hunters);
    while(i--) {
      if(hunters[i] == find_player(str))
        flag = 1;
    }

    hunters = find_player(str)->query_hunted();
    i = sizeof(hunters);
    while(i--) {
      if(hunters[i] == this_player())
        flag = 1;
    }

    if(flag == 0) {
        write("You are not out to kill them!");
        return 1;
    }

    write("You ask "+find_player(str)->query_cap_name()+" for a truce.");
    message("info", this_player()->query_cap_name()+" asks you for a truce.", find_player(str));
    waiting[this_player()->query_name()] = str;

    return 1;
}

void help() {
    write("Syntax: <truce [player]>\n\n"+
        "Lets you stop fighting another player.\n"+
        "Make sure that you are not currently fighting, and \n"+
        "you only try to truce one person at a time.\n"
);
}
