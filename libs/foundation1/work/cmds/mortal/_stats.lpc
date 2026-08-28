//      /bin/user/_stats.c
//      from the Nightmare mudlib
//      lists a player's stats
//      created by Descartes of Borg 25 april 1993

#include <std.h>

inherit DAEMON;

int cmd_stats(string str) {
    int i, stats_size;
    string *stats;

    if(str) return 0;
    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in an immaterial state.\n");
        return 0;
    }
    message("status", "You have the following physical traits:",this_player());
    stats = ({ "strength", "constitution", "dexterity", "charisma",
      "intelligence", "wisdom" });
    stats_size = sizeof(stats); /* speed patch by Val */
    for(i = 0; i < stats_size; i += 3) {
        message("status", sprintf("%s: %d     ", arrange_string(stats[i],
          13), (int)this_player()->query_base_stats(stats[i]))+
          (i+1 >= stats_size ? "" : sprintf("%s: %d     ",
          arrange_string(stats[i+1], 13),
          (int)this_player()->query_base_stats(stats[i+1])))+(i+2>=stats_size ?
          "" : sprintf("%s: %d", arrange_string(stats[i+2], 13),
          (int)this_player()->query_base_stats(stats[i+2]))), this_player());
    }
    return 1;
}

void help() {
    message("help",
      "Syntax: <stats>\n\n"
      "Gives you a numerical representation of your genetically inherited "
      "physical traits.\n\nSee also: score, skills, status", this_player()
    );
}
