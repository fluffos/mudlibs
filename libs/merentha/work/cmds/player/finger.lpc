// Petrarch
// Merentha Lib 1.0
// <finger>

#include <daemons.h>

string help() {
    return "Syntax: finger <player>\n        finger @<mud>\n        finger \
<player>@<mud>\n\nDisplay basic information about a player.  If no player \
is listed then displays basic information about all people currently \
logged on.\n\
If the @ symbol is used, displays either basic information about a single \
player, or all players on the MUD named.  The MUD must be conneted to the \
Merentha InterMUD System.\
\n\nSee also: users, muds";
}

varargs int command(string who) {
    string mud;
    int i=to_int(this_player()->getenv("SCREEN"));
    if(!i) i=75;
    if(!who) message("command", FINGER_D->get_player_list(i),this_player());
    else {
        if(strsrch(who, "@")!=-1) {
            sscanf(who, "%s@%s", who, mud);
            if(who=="") who=0;
            return NETWORK_D->send_finger_request(mud, this_player()->query_name(), who,i);
        }
        else this_player()->more(FINGER_D->get_player_info(who, i));
    }
    return 1;
}

