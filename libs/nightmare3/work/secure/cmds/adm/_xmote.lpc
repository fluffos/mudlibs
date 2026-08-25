/*    /cmds/adm/_xmote.c
 *    from the Nightmare Mudlib 3.2
 *    a promote/demote style command for use with the Nightmare system
 *    created by Descartes of Borg 940124
 */

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;
 
int cmd_xmote(string str) {
    string pos, nom;
    object ob;
    int lev;

    if(!archp(previous_object())) return 0;
    if(sscanf(str, "%s %s", nom, str) != 2)
      return notify_fail("Usage: <xmote [player] ([level]) ([position])>\n");
    if(sscanf(str, "%d %s", lev, pos) != 2) {
        if(!sscanf(str, "%d", lev)) {
            log_file("xmote", sprintf("%s went to position %s thanks to "
              "%s on %s.\n", nom, str, (string)previous_object()->query_name(),
              ctime(time())));
            if(ob = find_player(nom = lower_case(nom))) ob->set_position(str);
            else USERS_D->xmote(nom, str, 0);
            message("info", sprintf("%s is now position %s", capitalize(nom),
              str), this_player());
            message("info", sprintf("You have been xmoted to %s", str), ob);
            return 1;
        }
        log_file("xmote", sprintf("%s went to level %d thanks to %s on %s.\n",
          nom, lev, (string)previous_object()->query_name(), ctime(time())));
        if(ob = find_player(nom = lower_case(nom))) ob->set_level(lev);
        else USERS_D->xmote(nom, 0, lev);
        message("info", sprintf("%s is now level %d.", capitalize(nom), lev),
          this_player());
        message("info", sprintf("You have been xmoted to level %d.\n",lev),ob);
        return 1;
    }
    log_file("xmote", sprintf("%s went to position %s and level %d thanks to "
      "%s on %s.\n", nom, pos, lev, (string)previous_object()->query_name(),
      ctime(time())));
    if(ob = find_player(nom = lower_case(nom))) {
        ob->set_level(lev);
        ob->set_position(pos);
    }
    else USERS_D->xmote(nom, pos, lev);
    message("info", sprintf("%s is now level %d and position %s.\n",
      capitalize(nom), lev, pos), this_player());
    message("info", sprintf("You are now level %d %s.\n", lev, pos), ob);
    return 1;
}

void help() {
    message("help", "Syntax: <xmote [player] ([level]) ([position])>\n\n"
      "Changes the level, position, or both of a player.", this_player());
}
