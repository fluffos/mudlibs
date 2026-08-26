/*
**  File:_cast.c
**  Creator: Cyanide@?Mud  (Inspired by a cmd written by Chronos@AtFoD)
**  Changes:
**    04 Apr 97  Cyanide@Nightfalls Keep  Created the file after losing
**                                       his previous work.
*/

#define MAGE_SPELLS MAGES+"spells/"

#include <m_spells.h>

int cmd_cast (string str) {
    string *spell_info;
    string spell, arg1, arg2; 
    object ob;
    int n;

    seteuid(getuid());

    if (!TP->query_level("wizard") && !TP->query_level("dragon")) {
	write("You're not a wizard.  You don't know how!\n");
	return 1;
    }

    if ((int)TP->query("stat/intelligence") < 9) {
	write("You can't remember how...\n");
	return 1;
    }

    if (!str) {
	write("Cast what spell?\n");
	return 1;
    }

    if (sscanf(str, "%s at %s", spell, arg1) != 2)
	if (sscanf(str, "%s at", spell) == 1) {
	    write ("Cast "+spell+" at whom?\n");
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
	if (this_player()->query("no_cast") || TP->query("stunned")
	  || TP->query("stop_attack")) {
	    write("You cannot seem to gather your thoughts.\n");
	    return 1;
	} else {
	    if ( ( (environment(this_player())->query("silent")) ||
		(this_player()->query("mute")) ) &&
	      ( (spell != "vocalize") &&
		(!present("#VOCALIZE_OB#", this_player() )) ) )  {
		write ("You open your mouth to cast, but no sound comes"+
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

    spell_info = (string *)this_player()->query("mage_spells");
    if (!spell_info) {
	write ("You don't know any spells!\n");
	this_player()->delete("spells");
	return 1;
    }

    n = member_array(spell, spell_info);
    if (n == -1) {
	write ("You don't know that spell.\n");
	return 1;
    }

    if (present("#VOCALIZE_OB#", this_player() )) {
	write ("You begin casting wordlessly...\n");
	say (this_player()->query("cap_name")+" begins casting wordlessly...\n");
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
	      write("Your spell just flows around "+
		   ob->query("cap_name")+"!\n");
	      return 1;
	 }
    */

    call_other(MAGE_SPELLS+spell_info[n], "cast_"+spell, arg1, arg2);
    return 1;
}
