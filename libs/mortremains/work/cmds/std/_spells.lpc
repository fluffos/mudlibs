// _spells.c
// Lists a player's known spells.
// Mobydick@TMI-2, 1-31-93. Mobydick doesn't care who wins the Super Bowl.
// Ilzarion@NK, 10-23-97 - Hacked quickly.
// Cyanide@NK, 1-3-98 - Cyanide spent some time on this; also, he don't
//             give a shit who wins either.

string pad(string, int);

#include <mudlib.h>

#define COLS 4
#define WIDTH 18

inherit DAEMON ;

int cmd_spells(string str) {
    int c, i, j, size, xtra, flag = 0;
    object ob;
    string *spells, strtmp;

    if (!str || !wizardp(TP))
	ob = TP;
    else 
	ob = find_player(str);

    if (!ob) {
	write("Cannot find player.\n");
	return 1;
    }

    str = "";
    if (!ob->query("mage_spells") && !ob->query("priest_spells")) {
	if (TP==ob) write("You haven't learned any spells yet.\n") ;
	else write (ob->query("cap_name")+
	      " hasn't learned any spells yet.\n") ;

	return 1 ;
    }

    for (c = 0; c <= 1; c++) {
	string name;

	if (ob!=TP) name = ob->query("cap_name") + " knows ";
	else name = "You know ";

	spells = ({});

	switch (c) {
	case 0:
	    if (ob->query("mage_spells")) {
		spells = ob->query("mage_spells") ;
		str = name + "the following mage spells:\n ";
		flag = 1;
	    } else
		continue;
	    break;
	default:
	    if (ob->query("priest_spells")) {
		spells = ob->query("priest_spells") ;
		if (flag) {
		    str = "\n"+name+"the following priest spells:\n ";
		} else {
		    str = name+"the following priest spells:\n ";
		}
	    } else
		continue;
	    break;
	}  // End switch

	xtra = sizeof(spells)%COLS;

	for (i=0; i<sizeof(spells); i++) {
	    if (!spells[i] || spells[i]=="") continue;
	    str += capitalize(pad(spells[i], WIDTH));

	    if (!((i+1)%COLS) || i==(sizeof(spells)-1)) {
		str += "\n ";
	    }
	}  // End i loop

	write (str) ;
    } // End c loop

    return 1 ;
}


// This func pads a string str to length i with spaces.
string pad(string str, int i) {
    string tmp = str;
    int loop, strsz = strlen(str);

    if (i <= strsz) return str;
    for (loop = strsz; loop < i; loop++) {
	tmp += " ";
    }
    return tmp;
}


string help() {
    string help;

    if (wizardp(TP)) help = ("Usage: spells\n\n"+
	  "The spells command will list the names of all the spells you know.\n");
    else help = ("Usage: spells <target>\n\n"+
	  "The spells command will list the names of all the spells the target\n"+
	  "knows.\n");

    help += "See also: cast, magic.\n" ;
    return help;
}

/* EOF */
