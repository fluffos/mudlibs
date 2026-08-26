// Originally coded by Ilzarion@Nightfall's Keep
// Drastically redone by Cyanide@Mortal Remains, 02/01/2000

#include <daemons.h>

inherit DAEMON;

int cmd_xp(string targ) {
    int lvl, exp, exp2, flag;
    string pre, klass, str;
    object ob;

    seteuid(getuid());

    if (targ && wizardp(TP)) {
	ob = find_player(targ);

	if (!ob || !visible(ob, TP)) {
	    write("There is no such player logged in.\n");
	    return 1;
	}
	flag = 0;
    } else {
	ob = TP;
	flag = 1;
    }

    if (!ob->query_level()) {    
	if (flag)
	    str = ob->query("cap_name")+" has not";
	else
	    str = "You have not";

	str += " yet joined a class.\n";

	write(str);
	return 1;
    }

    klass = keys(ob->query_levels())[0];
    lvl = values(ob->query_levels())[0];  
    exp = ob->query("experience");


    str = "[*********** Experience Needed ***********]\n";

    if (flag) pre = "You are ";
    else pre = ob->query("cap_name")+" is ";

    str += pre+"currently a level "+lvl+" "+klass+" with "+exp+
    " xp.\n\n"+pre;

    exp2 = ( exp - PROPERTY_D->query_xp_needed(klass, lvl) ) * 100;


    exp2 /= (PROPERTY_D->query_xp_needed(klass, lvl+1) -
      PROPERTY_D->query_xp_needed(klass, lvl));

    if (flag) pre = " you need ";
    else pre = " "+ob->query("cap_name")+" needs ";

    str += ""+exp2+"% of the way to the "+
    PROPERTY_D->query_xp_needed(klass, lvl+1)+" xp"+pre+"for "+
    "level "+(lvl+1)+".\n\n"; 

    str += "For level "+(lvl+2)+pre+
    PROPERTY_D->query_xp_needed(klass, lvl+2)+" experience points.\n";
    str += "For level "+(lvl+3)+pre+
    PROPERTY_D->query_xp_needed(klass, lvl+3)+" experience points.\n";

    write(str);
    return 1;
}

string help() {
    return @ENDHELP
Usage: xp

This command shows you how much experience you need for your few levels.
ENDHELP
    ;
}
/* EOF */
