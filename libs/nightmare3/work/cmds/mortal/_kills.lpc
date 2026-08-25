#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_kills(string who) {
    string *kills, tmp;
    object ob;
    int x, amt;

    if(!who)
        ob=this_player();
    else {
        if(!creatorp(this_player()))
            return notify_fail("You can only see your own kills.\n");
        if(!ob=find_player(who))
            return notify_fail("No such person!\n");
    }
    kills = ob->query_kills();
    if(!amt=sizeof(kills))
        return notify_fail("You havn't killed anything yet!\n");		    
    message("my_action", sprintf("You have killed %d monsters.",amt),
      this_player());
    for(x=0;x<amt;x++) {
        tmp = (string)PLAYER_D->query_monster(kills[x]);
        tmp = arrange_string(tmp, 20);
	x++;
        if(x == amt) {
            message("my_action", tmp, this_player());
            break;
        }
        tmp += (string)PLAYER_D->query_monster(kills[x]);
        tmp = arrange_string(tmp, 40);
        x++;
        if(x == amt) {
            message("my_action", tmp, this_player());
            break;
        }
        tmp += (string)PLAYER_D->query_monster(kills[x]);
        tmp = arrange_string(tmp, 60);
        x++;
        if(x == amt) {
            message("my_action", tmp, this_player());
            break;
        }
        tmp += (string)PLAYER_D->query_monster(kills[x]);
        message("my_action", tmp, this_player());
    }
    return 1;
}

void help() {
    if(!creatorp(this_player())) {
        message("help", "Usage: <kills>\n\nLists all of your kills.",
          this_player());
    }
    message("help", "Usage: <kills [who]>\n\nLists your kills "
      "or kills for [who].", this_player());
    return ;
}
