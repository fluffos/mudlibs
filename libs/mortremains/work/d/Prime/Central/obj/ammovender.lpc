/* 
** FILE:    Ammovender.c
** PURPOSE: An ammunition vending machine
** CREDITS:
**   11 Jun 99  Cyanide wrot ethe file.
*/

#define COST 250
#define QUANTITY 80

// This is what one can get for COST credits

#include "/u/c/cyanide/debug.h"

mapping stuffmap = ([
".44" : 80,
"9mm" : 100,
"shotshell" : 90,
"12mm" : 100,
]);

mapping bought = ([]);
string *k_stuff;
int *v_stuff;

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("author", "cyanide");
    set("short", "an ammunition vending machine");
    set("long", "@@query_long");
    set("id", ({ "machine", "vending machine" }) );
    set("mass", 3000);
    set("prevent_get", 1);
    set("prevent_clean", 1);

    k_stuff = keys(stuffmap);
    v_stuff = values(stuffmap);
}

void init() {
    add_action("vend", "vend");
}

string query_long() {
    string str;
    int i, sz;


    str = wrap("This is an antique candy vending machine that has "+
      "been modified to sell ammunition. One purchase costs "+COST+
      " credits.\nYou may <vend #> the to purchase the following "+
      "items:\n");

    sz = sizeof(v_stuff);
    for (i=0; i<sz; i++)
	str += "         "+(i+1)+" - "+v_stuff[i]+" "+k_stuff[i]+
	" rounds\n";

    return str;
}

int vend(string str) {
    int sz, i, num;
    object ammo;

    if (!str) {
	write("Vend what?\n");
	return 1;
    }

    if (sscanf(str, "%d", num)!=1) {
	write("Syntax: vend <# desired>\n");
	return 1;
    }

    sz = sizeof(v_stuff);
    num--;
    if (num > sz-1 || num < 0) {
	write("That is not a valid number!\n");
	return 1;
    }

    if (bought[k_stuff[num]] >= v_stuff[num]*QUANTITY) {
	write("There are no more of those left.\n");
	return 1;
    }

    if (!TP->debit(COST)) {
	write("You don't have enough credits!\n");
	return 1;
    }

    ammo = clone_object(AMMO);
    ammo->set_number(v_stuff[num]);
    ammo->set_type(k_stuff[num]);
    ammo->move(TP);
    i = bought[k_stuff[num]];
    bought[k_stuff[num]] = i + v_stuff[num];

    write(wrap("You buy "+v_stuff[num]+" "+k_stuff[num]+" rounds for "+
	COST+" credits."));
    say(TPN+" buys some "+k_stuff[num]+" rounds from the vending "+
      "machine.\n");

    return 1;
}

void clean() {
    bought = ([]);
}

/* EOF */   
