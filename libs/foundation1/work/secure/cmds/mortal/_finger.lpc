#include <daemons.h>
#include <std.h>
#include <socket.h>

inherit DAEMON;

void remote_finger(object me, string target, string mud);

int cmd_finger(string str) {
    object ob;
    string wer, wo;

    if(!str)
        message("info", "Finger whom?", this_player());
    else if(sscanf(str, "%s@%s", wer, wo)) 
      remote_finger(this_player(), (wer ? wer : ""), wo);
    else
    message("info", (string)FINGER_D->user_finger_display(str),this_player());
    return 1;
}
 
void remote_finger(object ob, string who, string mud) {
    int tc_flag, ud_flag, id;

    ud_flag = NETWORK_D->mud_exists(mud);
    if(!ud_flag && !tc_flag)
        message("info", sprintf("%s is not listed as part of the tcp or udp "
        "networks.", mud), this_player());
    else if(who == "" && !tc_flag)
      SERVICES_D->send_gfinger_q(mud, 0, this_player());
    else if(!tc_flag || (ud_flag && who != ""))
      SERVICES_D->send_gfinger_q(mud, who, this_player());
}
 
void help() {
    message("help",
      "Syntax: <finger (([player])(@)([mud]))>\n\n"
      "Gives you information about a player named.  If you do not mention "
      "a particular mud, it searches for that player info here.  If you "
      "do not mention a player or a mud, it gives general finger info for "
      "everyone on line here.  If you mention another mud but no player, "
      "it gives you general info on the players on that mud.\n\n"
      "See also: gmuds, mail, muds, rwho, tell, users, who", this_player()
    );
}
