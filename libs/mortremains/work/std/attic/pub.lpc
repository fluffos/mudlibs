/*
** Pub.c
** Cyanide's version, 23 May 1999
*/

#include "/u/c/cyanide/debug.h"
#include <messages.h>

// Beverages as  ([ "name" : drunk amount ])
#define DRINKS  ([          \
    "beer" : 5,             \
    "wine" : 10,            \
    "tequila" : 20,         \
    "coffee" : -5,          \
    "cappaccino" : -10,    \
    "espresso" : -15,       \
  ])

// The cost of a drink is its cost times 4. Double that
// for coffee beverages =
#define COST_MULT 4

string drink(string);

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());

    set("drink_types", DRINKS);
}

void init() {
    add_action("buy", "buy");
    add_action("listf", "list");
    add_action("listf", "menu");
}

int buy(string str) {
    int cost, hp_add = 0, drunk_add;
    mapping drink_map;
    string drink_name;


    if (!str)
	return notify_fail("Buy what?\n");

    str = lower_case(str);

    drink_map = (mapping)query("drink_types");

    if (!drink_map) {
	write("The bartender says, \"Sorry, there's an error.\"\n");
	return 1;
    }

    drunk_add = member_array(str, keys(drink_map));

    if (drunk_add==-1) {
	write("Sorry, but that drink isn't on the menu.\n");
	return 1;
    }

    // Determine the drinks proper name and the amount of
    // drunkeness and adds or subtracts.
    drink_name = capitalize(str);
    drunk_add = (values(drink_map))[drunk_add];

    if ((drunk_add>0) && (int)TP->query("drunk") > 25) {
	write("The bartender says: Sorry, you've had enough.\n");
	return 1;
    }

    if (drunk_add-5 > TP->query_level()) {
	write("You're not tough enough to handle a drink like that yet!\n");
	return 1;
    }

    // Get the drinks cost. Coffee costs more.
    cost = drunk_add * COST_MULT;
    if (cost < 0) cost *= -2;

    if (!TP->debit(cost)) {
	write("The bartender yells: You can't afford that! Get "+
	  "outta' here!\n");
	return 1;
    }

    // HP addition is done by the formula y = 7x-25
    hp_add = 0;
    if (drunk_add > 0) {
	if ((int)TP->query("hit_points") < (int)TP->query("max_hp")) {
	    hp_add = (7 * drunk_add) - 25;
	    if ((int)TP->query("hit_points") + hp_add >
	      (int)TP->query("max_hp"))
		hp_add = (int)TP->query("max_hp") -
		(int)TP->query("hit_points");
	    TP->add("hit_points", hp_add);
	}
    } else {
	if ((int)TP->query("drunk") + drunk_add < 0)
	    drunk_add = (int)TP->query("drunk") * -1;
    }

    TP->add("drunk", drunk_add);

    say(TPN+" buys "+article(str)+" "+str+".\n");
    message(MSG_MOVEMENT, drink(str), TP);
    return 1;
}

string list() {
    string list, drink, cost, *dkeys;
    int i = 2, j, sz, num, *dvals;
    mapping drinks = query("drink_types");

    if (!drinks) { 
	return "The bar is try at the moment.\n";
    }

    dkeys = keys(drinks);
    dvals = values(drinks);
    sz = sizeof(dkeys);

    list = "";
    while(i--) {
	string tmplist = "";
	for (j=0; j<sz; j++) {
	    if (i==1 && dvals[j]<1) continue;
	    if (i==0 && dvals[j]>0) continue; 

	    drink = capitalize(dkeys[j]);
	    num = dvals[j] * COST_MULT;
	    if (num < 0) num *= -2;

	    cost = "" + num + " credits";

	    tmplist = sprintf("%20s     %-10s\n", drink, cost) + tmplist;
	}
	list += tmplist;
	if (i==1) list += "\n";
    }

    return list;
}

int listf() {
    write("We have the following drinks this evening:\n");
    write(list());

    return 1;
}

// This function is expected to be overridden.
string drink(string str) {
    return ("The drink is very refreshing.\n");
}


/* EOF */

