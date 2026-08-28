/*  /cmds/mortal/_cpr.c
 *  Made for DarkeMUD
 *  Created by Geldron 031096
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

#include <std.h>

inherit DAEMON;

int cmd_cpr(string arg) {
    object ob;

    if(arg) {
	ob = present(arg, ENV(TP));
	if(!ob) {
	    message("cpr", arg + ": not found.", TP);
	    return 1;
	}
	ob->restart_heart_beat();
	message("cpr", "You have successfully performed CPR on " +
	  ob->query_cap_name() + ".", TP);
	message("cpr", "%^CYAN%^You hear sounds of your heart beating, "
	  "\"BuhBump, BuhBump.\"%^RESET%^", ob);
	return 1;
    }
    TP->restart_heart_beat();
    message("cpr", "%^CYAN%^You hear sounds of your heart beating, "
      "\"BuhBump, BuhBump.\"%^RESET%^", TP);
    return 1;
}

void help() {
    message("cpr_help", syntax("cpr [LIV]") + "\n\n"
      "This command, without arguments, will opreate cpr on yourself.  "
      "Otherwise, with arguments, it'll operate cpr on the LIV you specify.  "
      "The target must be in the current room.  Not only will heart beats be "
      "restored to yourself or LIV, it will work all the time.", TP);
}
