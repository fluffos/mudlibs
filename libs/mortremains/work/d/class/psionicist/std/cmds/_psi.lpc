/*
**  File:_psi.c
**  Creator: Cyanide@?Mud  (Inspired by a cmd written by Chronos@AtFoD)
**  Changes:
**    04 Apr 97  Cyanide@Nightfalls Keep  Created the file after losing
**                                       his previous work.
*/

#include "/u/c/cyanide/debug.h"
#include <psionics.h>

int cmd_psi (string str) {
    string *power_info;
    string power, arg1, arg2; 
    object ob;
    int n;

    seteuid(getuid());

    if (!TP->query_level("psionicist") && !wizardp(TP)) {
	write("You're not a wizard.  You don't know how!\n");
	return 1;
    }

    if ((int)TP->query("stat/intelligence") < 9) {
	write("You can't remember how...\n");
	return 1;
    }

    if (!str) {
	write("Invoke which power?\n");
	return 1;
    }

    if (sscanf(str, "%s at %s", power, arg1) != 2)
	if (sscanf(str, "%s at", power) == 1) {
	    write ("Psi "+power+" at whom?\n");
	    return 1;
	} else {
	    if (sscanf(str, "%s %s", power, arg1) != 2) 
		power = str;
	}

    if (TP->query("power_delay") > 0) {
	write("You haven't recovered from that last power yet!\n");
	return 1;
    }

    if (environment(this_player())->query("no_magic")) {
	write ("You seem to be in a magic dead area.\n");
	return 1; 
    }

    if (this_player()->query("no_cast") || TP->query("stunned")
      || TP->query("stop_attack")) {
	write("You cannot seem to gather your thoughts.\n");
	return 1;
    }

    power_info = (string *)this_player()->query("psi_powers");
    if (!power_info) {
	write ("You don't know any powers!\n");
	this_player()->delete("psi_powers");
	return 1;
    }

    n = member_array(power, power_info);
    if (n == -1) {
	write ("You don't know that power.\n");
	return 1;
    }

    /*
	 if (arg1) ob = present(arg1, environment(this_player())); 
	   else (ob = this_player() );
    write(ob->query("cap_name"));
	 if (!ob) ob = present(arg1,this_player());
	 if (ob) n = ob->query("magic_resist");
    write("Resist "+n+" becomes ");
	 if (n) n = (n - ((TP->query_level() - 12) * 5) );
    write(n+"\n");
	 if ((n) && (n > random(100)) ) {
	      write("Your power just flows around "+
		   ob->query("cap_name")+"!\n");
	      return 1;
	 }
    */

    say(TPN+" begins to concentrate...\n");

    call_other(PSI_POWERS+power_info[n], "psi_"+power, arg1, arg2);
    return 1;
}
