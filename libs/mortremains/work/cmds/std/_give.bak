/*
** File: _give.c
** Purpose: To move an item, several items, or cash from a giver living 
**   object to another living object.
** Credits:
**   21 Oct 97  Rewritten from scratch by Cyanide because the old one was a
**              hacked piece of crap and was buggy as hell.
**   14 Apr 98  Cyanide fixed up a bit.
**   02 Jun 99  Cyanide converted coins to credits.
*/

#define SYNTAX "Syntax: give (all) <credits|object> (#) to <living object>\n"

#include "/u/c/cyanide/debug.h"
#include <mudlib.h>
#include <move.h>

object check_valid_receiver(string);
int give_money (int, object);
int give_object(object, object);

int cmd_give (string strMain) {
    string strA, strB, strGetter;
    int num = 1, counter = 0, i;
    object obGetter, *obInv;

    if (!strMain) {
	write(SYNTAX);
	return 1;
    }

    // Formats: "give all to cyanide"
    //          "give all credits to IRS"
    //          "give all spam to nightmask"

    DEBUG("Str = "+strMain+"\n");
    strA = "STUFF";
    if ((sscanf(strMain, "all %s to %s", strA, strGetter) == 2) ||
      (sscanf(strMain, "all to %s", strGetter)==1) ) {
	obGetter = check_valid_receiver(strGetter);
	if (!obGetter) return 1;

	// We keep the antiquated 'gold', just for convenience.
	if (strA == "gold" || strA == "credits" || strA=="credit") {
	    num = (int)this_player()->query("wealth");
	    if (num<1) {
		write("You have no credits to give!\n");
		return 1;
	    }
	    give_money(num, obGetter);
	    return 1;
	} else {
	    obInv = all_inventory(this_player());
	    if (!sizeof(obInv)) {
		write("You have nothing to give!\n");
		return 1;
	    }
	    counter = 0;         // Initializing the variable
	    for (num=sizeof(obInv)-1; num>=0; num--)
		if (strA=="STUFF" || obInv[num]->id(strA))
		    if (give_object(obInv[num], obGetter))
			counter++;
	    if (!counter)
		write("You give nothing.\n");
	    else
		write(counter + " objects given.\n");
	    return 1;
	}
    }

    // Format: "give 4000 credits to sweetleaf"
    if (sscanf(strMain, "%d %s to %s", num, strA, strGetter)==3) {
	DEBUG("Parsed: num = "+num+", str = "+strA+", strGetter = "+strGetter+"\n");
	obGetter = check_valid_receiver(strGetter);
	if (!obGetter) return 1;
	if (strA=="credits" || strA=="gold" || strA=="credit") {
	    give_money(num, obGetter);
	    return 1;
	}
    }

    // Formats: "give statue to makeriham"
    //          "give sword 2 to fell"

    num = 1;
    if ((sscanf(strMain, "%s %d to %s", strA, num, strGetter)==3) ||
      (sscanf(strMain, "%s to %s", strA, strGetter)==2) ) {
	obInv = all_inventory(this_player());
	obGetter = check_valid_receiver(strGetter);
	if (!obGetter) return 1;

	i = 0;
	counter = 0;
	while ((counter < num) &&  (i < sizeof(obInv)) ) {
	    if (obInv[i]->id(strA)) counter++;
	    if (counter==num) give_object(obInv[i], obGetter);
	    i++;
	}
	return 1;
    }

    write (SYNTAX);
    return 1;
}

// This function checks to see if the thing with the id "str" is a valid
// receiver, and than returns that thing's object designation.

object check_valid_receiver(string str) {
    object ob;

    ob = present(str, environment(this_player()));
    if (!ob) {
	write("There is no "+capitalize(str)+" to give anything to!\n");
	return 0;
    }

    if (!living(ob)) {
	write("That's not even alive!\n");
	return 0;
    }

    if (ob==TP) {
	write("Give to yourself? Why?\n");
	return 0;
    }

    return ob;
}

// This function handles all the moving of credits from one object to another.

int give_money (int cash, object ob) {
    string str;

    if (cash<1) {
	// They try to be sneaky, we beat 'em at their own game. - Cyanide
	write("Sneaky.  Attempt logged and Law notified.\n");
	return 0;
    }

    // Do they have enough?
    if (!this_player()->debit(cash)) {
	write("You don't have that much.\n");
	return 0;
    }

    // Can ob for whatever reason not take the cash?
    if (!ob->credit(cash)) {
	write(ob->query("cap_name") + " cannot take that.\n");
	message("command", TPN + " tried to give you "+cash+
	  " credits.\n", ob);
	// Give back the money that wasn't given...
	TP->credit(cash);
	return 0;
    }
    if (cash>1) {
	write("You give "+cash+" credits to "+
	  ob->query("cap_name")+".\n");
	message("command", TPN+" gives you "+cash+
	  " credits.\n", ob);
    } else {
	write("You give a credit to "+
	  ob->query("cap_name")+".\n");
	message("command", TPN+" gives you a"+
	  " credit.\n", ob);
    }

    switch(cash) {
    case 1 : str ="a single credit"; break;
    case 2..10 : str ="a handful of credits"; break;
    case 11..30 : str ="a small roll of credits"; break;
    case 31..90 : str ="a roll of credits"; break;
    case 91..270 : str ="a thick roll of credits"; break;
    case 271..810 : str ="a stack of credits"; break;
    case 811..2430 : str ="a few stacks of credits"; break;
    case 2431..7290 : str ="several stacks of credits"; break;
    case 7291..21870 : str ="a sack of credits"; break;
    case 21871..65610 : str ="a briefcase full of credits"; break;
    case 65611..196830 : str ="an AWFUL lot of credits"; break;
    default : str ="a small fortune"; break;
    }
    say(wrap(TPN+" gives "+str+" to "+ob->query("cap_name")
	+"."), ({ ob }) );
    return 1;
}

// This handles the giving of actual objects.
// In the future, all tell_object()'s will be message()'s
int give_object(object item, object getter) {
    string strName;
    object *folks;
    int i;

    if (!item->query("short")) return 0;
    if (item->query("prevent_drop") || item->query("prevent_give")) {
	write("You can't give away "+item->query("short")+".\n");
	return 0;
    }
    if (item->move(getter) == MOVE_OK) {
	folks = all_inventory(environment(this_player()));
	for (i=0; i<sizeof(folks); i++) {
	    if (!living(folks[i])) continue;
	    if (folks[i]==TP) {
		message("command", "You give "+item->query("short")
		  +" to "+getter->query("cap_name")+".\n", folks[i]);
		continue;
	    }
	    if (folks[i]==getter) {
		message("command", TPN+" gives "+item->query("short")+
		  " to you.\n", folks[i]);
		continue;
	    }
	    message("command", TPN+" gives "+item->query("short")+" to "+
	      getter->query("cap_name")+".\n", folks[i]);
	}
    } else {
	write(getter->query("cap_name")+" could not take "+item->query("short")
	  +".\n");
	message("command", TPN+" tried to give you "+
	  item->query("short")+", but you couldn't take it.\n",
	  getter);
	return 0;
    }
    return 1;
}

string help() {
    return(SYNTAX+"\n"+
      "This command will make you give an item in your inventory\n"+
      "to the player specified.  You must be in the same room for\n"+
      "this to occur.\n"+
      "\nSee also: drop\n");
}


/* EOF */
