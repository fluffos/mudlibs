/*
** _invoke.c - Coded by Cyanide@Nightfall's Keep.
** Changes
**  16 Dec 98   Cyanide fixed.
*/

#define PRIEST_SPELLS PRIESTS+"spells/"

#include <p_spells.h>

int cmd_invoke (string str) {
    string *spell_info;
    string spell, arg1, arg2, deity;
    object ob;
    int n;

    seteuid(getuid());

    deity = TP->query("deity");

    if (!str) {
	write("Invoke what spell?\n");
	return 1;
    }

    if (sscanf(str, "%s at %s", spell, arg1) != 2)
	if (sscanf(str, "%s at", spell) == 1) {
	    write ("Invoke "+spell+" at whom?\n");
	    return 1;
	} else {
	    if (sscanf(str, "%s %s", spell, arg1) != 2)
		spell = str;
	}

    if (this_player()->query("power_delay") > 0) {
	write("You haven't recovered from that last spell yet!\n");
	return 1;
    }

    if (environment(this_player())->query("no_magic")) {
	write ("You seem to be in  magic dead area.\n");
	return 1;
    } else {
	if (this_player()->query("no_cast")) {
	    write("You cannot seem to gather your thoughts.\n");
	    return 1;
	} else {
	    if ( ( (environment(this_player())->query("silent")) ||
		(this_player()->query("mute")) ) &&
	      ( (spell != "vocalize") &&
		(!present("#VOCALIZE_OB#", this_player() )) ) )  {
		write ("You open your mouth to invoke, but no sound comes"+
		  " out!\n");
		return 1;
	    } else {
		if (this_player()->query("held") || this_player()->query("bound")) {
		    write ("You can't even move!\n");
		    return 1;
		}
	    }
	}
    }

    spell_info = (string *)this_player()->query("priest_spells");
    if (!spell_info) {
	write ("You don't know any spells!\n");
	this_player()->delete("priest_spells");
	return 1;
    }

    n = member_array(spell, spell_info);
    if (n == -1) {
	write ("You don't know that spell.\n");
	return 1;
    }

    if (present("#VOCALIZE_OB#", this_player() )) {
	write ("You begin invokeing wordlessly...\n");
	say (this_player()->query("cap_name")+" begins invoking wordlessly...\n");
    } else {
	/*
		deity = capitalize(deity);
		write("You invoke the name of "+deity+"!\n");
		say(TPN+" invokes the name of "+deity+"!\n");   
	*/
    }

    call_other(PRIEST_SPELLS+spell_info[n], "invoke_"+spell, arg1, arg2);
    return 1;
}

/* EOF */
