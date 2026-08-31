#include <std.h>
inherit DAEMON;

int cmd_pkills(string who) {
    string *kills;
    object ob;
    int x, amt;

    if(!who)
	ob=this_player();
    else {
	if(!wizardp(this_player()))
	    return notify_fail("You can only see your own kills.\n");
	if(!ob=find_player(who))
	    return notify_fail("No such person!\n");
    }
    kills = ob->query_kills();
    message("info", "%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Kills %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+", this_player());
    if(!amt=sizeof(kills))
	return notify_fail("You havn't killed anything yet!\n");                    
    message("my_action", sprintf("You have killed %d creatures.",amt),
      this_player());
    message("info", "%^BLUE%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",this_player());

    for (x = 0; x < amt; x++) {	
	if (is_player(ob)) {
	    x++;
	    continue;

	    if(x == amt) {
		write(x);
		break;
	    }
	}
	message("info", "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=", this_player());
	return 1;
    }

