//      /cmds/wiz/_locate.c
//      from the TMI-2 Mudlib
//      searches the muds linked by DNS for a player
//      created by Descartes of Borg 931019
//      Updated by Drizzt@Tmi-2 to be compatable for I3

#include <mudlib.h>
#include <net/dns.h>

inherit DAEMON;

int cmd_locate(string who) {
    object ob;

    if(!who) return notify_fail("Locate whom?\n");
    if((ob=find_player(who=lower_case(who))) && !(ob->query("invis")) &&
      !hiddenp(ob))
        message("write", capitalize(who)+" is right here on this mud!\n",
          this_player());
     "/adm/daemons/network/I3/locate"->send_locate_req(who,this_player()->query("name"));
    message("write", "Locate query sent.\n", this_player());
    return 1;
}

int help() {
    message("help", "Syntax: <locate [player]>\n\n"
      "Searches all the muds linked on various intermud systems\n"
      "for the player named.\n", this_player());
    return 1;
}
