/*  /cmds/adm/_cycle.c
 *  Made for DarkeMUD
 *  Created by Geldron 031796
 *  Copyright (c) 1996
 *  Do not remove this header
 */


int cmd_cycle(string arg) {
    object ob;
    string str;
    int val, i, count;

    if(!TP) return 0;
    if(!archp(TP)) return 0;
    sscanf(arg, "%s %d", str, val);
    if(!str || !val) {
	message("cycle", syntax("cycle USER TIMES"), TP);
	return 1;
    }
    ob = find_player(str);
    if(!ob) {
	message("cycle", str + ": not found.", TP);
	return 1;
    }
    message("cycle", "%^BOLD%^%^RED%^You hear the sound of "
      "an executioner getting ready for his job on " +
      CAP(ob->query_name()) + ".%^RESET%^", users());
    for(i = 0; i < val; i++) {
	count++;
	message("cycle", "%^RED%^You hear an old piece of machinary "
	  "operate!  It counts: " + count + ".%^RESET%^", users());
	ob->die();
present("corpse", ENV(ob))->remove();
	ob->revive();
    }
    return 1;
}
