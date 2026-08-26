/*
** This makes it so people can tell which area they're currently in, 
** and allows them to identify who coded an object.
** Balkalarre, Thursday, July 11th, 1996.
(08-27-96) Throughly improved by Chronos.
(04-06-98) Help() function added by Chronos.
(14-04-00) Chronos added a bunch of shit, but he had to leave
	   real quick, and Cyanide finished it.
*/

inherit DAEMON;

int cmd_whocoded(string What) {
    object ob;
    string Tmp, Who;

    if (!What) {
	if (!environment(TP)->query("author")) {
	    if (sscanf(base_name(environment(TP)),
		"/u/%s/%s/%s", Tmp, Who, Tmp) == 3) {
		write(wrap(sprintf("This area was coded by %s.",capitalize(Who))));
		return 1;
	    } else {
		if (sscanf(base_name(environment(this_player())),
		    "/d/%s/%s/%s", Who, Tmp, Tmp) == 3 || 
		  sscanf(base_name(environment(this_player())),
		    "/d/%s/%s", Who, Tmp) == 2 ) {
		    write(wrap(
			sprintf("This area was coded by the wizards of the %s domain.",
			  capitalize(Who))));
		    return 1;
		} else {
		    write(wrap("This room was coded by Mudlib."));
		    return 1;
		}
	    }
	} else {
	    write(wrap(sprintf("This area was coded by %s.", 
		  capitalize(environment(TP)->query("author")))));
	    return 1;
	}
    }
    ob = present(What, environment(TP));
    if (!ob) ob = present(What, TP);

    if (ob) {
	if (ob->query("author")) {
	    write("This object was coded by "+
	      capitalize(ob->query("author")) + ".\n") ;
	    return 1;
	} else {
	    if (sscanf(base_name(ob),"/u/%s/%s/%s", Tmp, Who, Tmp) == 3) {
		write(wrap(sprintf("This object was coded by %s.",capitalize(Who))));
		return 1;
	    } else {
		if (sscanf(base_name(ob),
		    "/d/%s/%s/%s", Who, Tmp, Tmp) == 3 || 
		  sscanf(base_name(ob), 
		    "/d/%s/%s", Who, Tmp) == 2 ) {
		    write(wrap(
			sprintf("This object was coded by the wizards of the %s domain.",
			  capitalize(Who))));
		    return 1;
		} else {  
		    if (userp(ob))
			write("That player was coded by the Mudlib God, Cyanide... indirectly at least.\n") ;
		    else
			write(wrap("This object was coded by Mudlib."));
		    return 1;
		}
	    }
	}
    }
    write("No such object is present.\n");
    return 1;
}

string help() {
    return @ENDHELP
Usage: whocoded [object]

This command identifies the creator of an object or room. Objects
not created by wizards are listed as 'Mudlib'.
ENDHELP
    ;
}
