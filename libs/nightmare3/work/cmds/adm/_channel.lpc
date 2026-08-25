/*    /cmds/adm/_channel.c
 *    from Nightmare IV
 *    command to handle channel privs
 *    created by Descartes of Borg 940428
 */

#include <std.h>

inherit DAEMON;

int cmd_channel(string str) {
    string opt, who, channel;
    object ob;

    if(!str) return 0;
    if(!archp(previous_object())) return 0;
    if(sscanf(str, "%s %s %s", opt, who, channel) != 3) return 0;
    if(!(ob = find_player(who = lower_case(who)))) 
      return notify_fail("No such player online.\n");
    if(opt == "remove") {
        ob->restrict_channel(channel);
        message("system", sprintf("You restrict %s from %s.", capitalize(who),
          channel), this_player());
        message("system",sprintf("You have lost your %s rights.",channel), ob);
        return 1;
    }
    else if(opt == "add") {
        ob->unrestrict_channel(channel);
        message("system", sprintf("You unrestrict %s from %s.", capitalize(who),
          channel), this_player());
        message("system", sprintf("You can now use the %s channel.",
          channel), ob);
        return 1;
    }
    else return 0;
}

void help() {
    message("help", "Syntax: <channel [add|remove] [player] [channel]>\n\n"
      "Used to restrict a player from using a line, or to allow them back "
      "onto that line.", this_player());
}
