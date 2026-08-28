/*  /cmds/adm/_resurrect.c

 *  Made for DarkeMUD

 *  Created by Geldron 031096

 *  Copyright (c) 1996, DarkeMUD

 *  Do not remove this header

 */





inherit DAEMON;



int cmd_resurrect(string arg) {

    object ob;



    if(!arg) {

	message("resurrect", syntax("resurrect USER"), TP);

	return 1;

    }

    ob = find_player(arg);

    if(!ob) {

	message("resurrect", arg + ": not found.", TP);

	return 1;

    }

    if(!ob->query_ghost()) {

	message("resurrect", ob->query_cap_name() + " is already alive.", TP);

	return 1;

    }

    ob->cheap_revive();

    message("resurrect", "You resurrect " + ob->query_cap_name() + ".", TP);

    message("resurrect", "You have been resurrected by " + TPQCN + ".", ob);

    return 1;

}



void help() {

    message("resurrect_help", syntax("resurrect USER") + "\n\n"

      "USER is revived without any penalties.", TP);

}

