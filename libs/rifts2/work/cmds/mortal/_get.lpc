/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use the code here.
// Originally written by Brian Leet.
// Adapted by Sulam (12-13-91)
// Help added by Brian (1/28/92)  *smirk*
// Better messages added by Brian (2/5/92)
// Light checking added by Hanse 4/11/92  :P
// Modified by Geldron 030496
*/

#include "move.h"
#include <std.h>

inherit DAEMON;

int help();

int cmd_get(string str) {
    object ob, *inv;
    int silly;
    int res, i;
    string tmp, type;
    int ammount;

    if(this_player()->query_ghost()) {
	notify_fail("You cannot do that in your immaterial state.\n");
	return 0;
    }
    if (!str) {
	return help();
    }
    if(effective_light(this_player()) < -1) {
	notify_fail("It is too dark.\n");
	return 0;
    }
    if(sscanf(str, "%d %s from %s", ammount, type, tmp) != 3)
	if(sscanf(str, "%d %s", ammount, type) != 2) {
	    if(str == "all") {
		inv = all_inventory(environment(this_player()));
		for(i=0;i<sizeof(inv); i++) {
		    if(!inv[i]->query_short()) continue;
		    if(interactive(this_player()) && interactive(inv[i])) continue;
		    if(!inv[i]->get()) {
			write("You can't get " + inv[i]->query_short() + "!");
		    }
		    else {
			res = (int)inv[i]->move(this_player());
			if (res == MOVE_OK) {
			    write("You take " + inv[i]->query_short() + ".");
			    message("other_action", (string)this_player()->query_cap_name() + " takes " +
			      inv[i]->query_short() + ".", environment(this_player()),
			      ({ this_player() }));
			}
			else if(res == MOVE_NO_ROOM) {
			    write(inv[i]->query_short() + ": You cannot carry that much.");
			}
		    }
		}
		return 1;
	    }
	    ob = present(str, environment(this_player()));
	    if (!ob) {
		if ((int)environment(this_player())->id(str)) {
		    notify_fail("You can't take that!\n");
		    return 0;
		}
		notify_fail("What " + str + "?\n");
		return 0;
	    }
	    if(!ob->get() || (interactive(this_player()) && 
		interactive(ob))) {
		write("You can't get that!");
		return 1;
	    }
	    res = (int)ob->move(this_player());
	    if (res == MOVE_OK) {
		write("You take " + ob->query_short() + ".");
		message("other_action", (string)this_player()->query_cap_name() + 
		  " takes " + (string)ob->query_short(), 
		  environment(this_player()),
		  ({ this_player() }));
		return 1;
	    }
	    if (res == MOVE_NOT_ALLOWED)
		notify_fail("You can't do that.\n");
	    else if (res == MOVE_NO_ROOM)
		notify_fail("You cannot carry that much.\n");
	    return 0;
	}
    type = lower_case(type);
    if(ammount < 1) {
	notify_fail("You can only take positive ammounts of coins.\n");
	return 0;
    }
    if(tmp && strlen(tmp)) ob = present(tmp, environment(this_player()));
    else ob = present("coins", environment(this_player()));
    if(ob && living(ob)) {
      write("I don't think so....");
      return 1;
    }
    if(!ob || ob->query_money(type) < ammount) {
	if(tmp && strlen(tmp) && !ob)
	    notify_fail("There is no '"+tmp+"' here.");
	else notify_fail("I don't see that much "+type+" here.\n");
	return 0;
    }
    ob->add_money(type, -ammount);
    if((float)ob->query_money_value() == 0.0)
	ob->remove();
    write("You put " + ammount + " " + type + " pieces into your purse.");
    message("other_action", (string)this_player()->query_cap_name() + " takes some " + type + ".",
      environment(this_player()), ({ this_player() }) );
    this_player()->add_money(type, ammount);
    return 1;
}

int
help() {
    write("Command: get\nSyntax: get <item | all>\n"+
      "This command will have your character try to pick up the\n"+
      "item specified, or if all is typed, it will make your\n"+
      "character try to pick up everything in the room.\n"
      "Examples:\n"
      "    get all\n"
      "    get sword\n"
      "    get 400 gold\n"
      "    get 500 copper from pile 2");
    return 1;
}
/* EOF */
