/*
** File: /cmds/std/_drop.c
** Based on TMI-2 version written by Zeus, 13 March 1993
**
** Completely rewritten by Cyanide 14 March 2000
*/

#include <move.h> 
#include <money.h>

#define CASH_NAMES ({ "credits", "credit", "coin", "coins", "cash" })
#define AMMO_NAMES ({ "rounds", "ammo" })

inherit DAEMON;

// Prototypes
int drop_cash(object, int);
int drop_ammo(object, string, int);
int drop_func(object, object);
string help();

int cmd_drop(string args) {
    int val, num, i;
    string id;
    object *obs;

    if (!environment(TP)) {
	write("You can't drop anything in the void!\n");
	return 1;
    }

    if (!args) {
	write(help());
	return 1;
    }

    // Syntax: drop 1000 credits
    //         drop 10 22mm rounds
    //         drop 175 12mm

    if (sscanf(args, "%d %s", num, id)==2) {
	// We pull out the wight word and lowercase it.
	id = lower_case((explode(id, " "))[0]);

	// Are we dropping money?
	if (member_array(id, CASH_NAMES) != -1) {
	    drop_cash(TP, num);
	    return 1;
	} else {  // Now, we assume they mean ammo
	    mapping ammo;
	    string *ammo_types, tmp;

	    if (TP->query("summoned")) {
		TP->command("shake");
		return 1;
	    }

	    if (TP->query("ammo"))
		ammo = TP->query("ammo");
	    else
		ammo = ([]);

	    ammo_types = keys(ammo);

	    for (i = 0; i < sizeof(ammo_types); i++) {
		tmp = lower_case(explode(ammo_types[i], " ")[0]);
		if (tmp==id) {
		    id = ammo_types[i];
		    break;
		}
	    }

	    // If this is true, we completed the loop, and therefore
	    // didn't find the correct ammo type.
	    if (i==sizeof(ammo_types)) {
		write("You don't have any ammo of that type.\n");
	    } else {
		drop_ammo(TP, id, num);
	    }

	    return 1;
	} // if (member_array(id, CASH_NAMES) != -1)
    } // if (sscanf(args, "%d %n", num, id)==2)

    // Syntax: drop all
    if (args=="all") {
	int sz, count = 0;

	obs = all_inventory(TP);
	sz = sizeof(obs);

	for (i=0; i<sz; i++) {
	    string str = obs[i]->query("short");
	    if (str) str = capitalize(str) + ": ";

	    if (drop_func(TP, obs[i])) {
		if (str)
		    write(str+"dropped.\n");
		count++;
	    } else {
		if (str)
		    write(str+"You can't drop that.\n");
	    }
	}

	if (!count)
	    write("You drop nothing.\n");
	else
	    write("You drop "+count+" items.\n");

	return 1;
    }

    // Syntax: drop all ammo
    //         drop all sword
    //         drop all 13mm round

    if (explode(args, " ")[0] == "all") {
	int sz;

	id = lower_case(args[4..<1]);   // Cut off the 'all' part

	if (member_array(id, CASH_NAMES) != -1) {
	    drop_cash(TP, TP->query("wealth") );
	    return 1;
	}

	if (member_array(id, AMMO_NAMES) != -1) {
	    string *ammo_types;

	    if (TP->query("summoned")) {
		TP->command("shake");
		return 1;
	    }

	    if (!TP->query("ammo")) {
		write("You have no ammo to drop.\n");
	    } else {
		ammo_types = keys(TP->query("ammo"));
		sz = sizeof(ammo_types);

		if (!sz) {
		    write("You have no ammo to drop.\n");
		} else {
		    for (i=0; i<sz; i++)
			drop_ammo(TP, ammo_types[i],
			  TP->query("ammo/"+ammo_types[i]) );
		}  // if (!sz)
	    } // if (!TP->query("ammo")

	    return 1;
	} // if (member_array(id, AMMO_NAMES)!=-1)

	// if we get here the player must be referring to objects.
	obs = all_inventory(TP);
	sz = 0;   // Using sz as a counter this time.

	for (i=0; i<sizeof(obs); i++) {
	    if (obs[i]->id(id)) {
		string str = capitalize(obs[i]->query("short"))+": ";

		if (drop_func(TP, obs[i])) {
		    write(str+"dropped.\n");
		    sz++;
		} else {
		    write(str+"You can't drop that.\n");
		}
	    }
	}

	if (sz != 1) id = pluralize(id);

	if (!sz) 
	    write("No "+id+" dropped.\n");
	else
	    write(sz+" "+id+" dropped.\n");

	return 1;
    } // if is an "all"

    if (sscanf(args, "%s %d", id, num)!=2) {
	num = 1;
	id = args;
    }

    obs = all_inventory(TP);

    val = 0;

    if (!present(id, TP)) {
	write("You don't have any "+id+" to drop.\n");
	return 1;
    }

    // Find the right one...
    for (i=0; i<sizeof(obs); i++) {
	if (obs[i]->id(id)) val++;

	if (val==num) break;
    }

    if (val < num) {
	write(wrap("You have don't have that many "+
	    pluralize(id)+" in your inventory.") );
    } else {
	val = drop_func(TP, obs[i]);

	if (val)
	    write("You drop "+obs[i]->query("short")+".\n");
	else
	    write("You can't drop "+obs[i]->query("short")+".\n");
    }

    return 1;
}

int drop_func(object player, object ob) {
    if (!userp(player) && TP->query("summoned")) {
	if (ob->query("native_object"))
	    return 0;
    }

    if (ob->query("prevent_drop")) return 0;

    if (ob->move(environment(player)) != MOVE_OK) {
	notify_fail("You can't drop that here.\n");
	return 0;
    }

    return 1;
}

int drop_cash(object player, int amount) {
    object ob;

    if (!player->debit(amount)) {
	write("You don't have that much cash on you.\n");
	return 0;
    } else {
	ob = clone_object(COINS);
	ob->set_number(amount);

	if (ob->move(environment(player)) != MOVE_OK) {
	    this_player()->credit(amount);
	    ob->remove();
	    notify_fail("You can't drop that here.\n");
	    return 0;
	}

	if(amount == 1) {
	    write("You drop 1 credit.\n");
	    say(player->query("cap_name")+" drop a credit.\n");
	} else {
	    write("You drop "+amount+" credits.\n");
	    say(player->query("cap_name")+" drops some credits.\n");
	}
    }

    return 1;
}

int drop_ammo(object player, string type, int amount) {
    object ob;

    if (!userp(player) && player->query("summoned")) {
	player->command("shake");
	return 0;
    }

    if (!player->ammo_debit(type, amount)) {
	write("You don't have that many "+type+" rounds on you.\n");
	return 0;
    } else {
	ob = clone_object(AMMO);
	ob->set_number(amount);
	ob->set_type(type);

	if (ob->move(environment(player)) != MOVE_OK) {
	    this_player()->ammo_credit(type, amount);
	    ob->remove();
	    notify_fail("You can't drop that here.\n");
	    return 0;
	}

	if(amount == 1) {
	    write("You drop 1 "+type+" round.\n");
	    say(player->query("cap_name")+" drop a "+type+" round.\n");
	} else {
	    write("You drop "+amount+" "+type+" rounds.\n");
	    say(player->query("cap_name")+" drops some "+type+
	      " rounds.\n");
	}
    }

    return 1;
}

string help() {
    return (@EndString
Syntax: drop <item | all>

This makes your character try to drop the specified item. If "all" is
used then your character drops all items carried. If you type "drop all
credits", then all your money is dropped. Similarly, you can "drop all
ammo", or "drop all 12mm ammo" (for example).

See also: get, put
EndString
    );
}

/* Enf of file */
