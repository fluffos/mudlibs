// A Glass of MILK.
// MILK It does a body good!
// It doesn leave a glass behind cause i stole ... ahem rephrased this code.
// Rephrased by Ragevortex.

#include <mudlib.h>

inherit OBJECT ;

void create() {
    set ("short", "a glass of MILK") ;
    set ("long", "This is a glass of MILK. Poured by a minocow. It looks refreshing and healthy.\n");
    set ("id", ({ "milk", "MILK", "Milk"}) );
    set("mass", 1);
}

void init() {
    add_action ("drink", "drink") ;
}

int drink (string str) {

    int res, max ;

    if (!str || !id(str)) {
	notify_fail ("What would you like to drink?\n") ;
	return 0 ;
    }
    write ("You are abbout to drink the MILK.\n");
    res = this_player()->query("hit_points") ;
    max = this_player()->query("max_hp") ;
    if (res < max) {
	res = res + ( (max - res) / 2);
	write("You notice the glass is sparkling but the MILK looks Delicious.\n");
	write("As soon as you drink the MILK the glass vanishes into thin air.\n");
	// this_player()->set("hit_points" + 50 + res);  
	this_player()->set("hit_points", res);
	remove() ;
    }
    else { write("You are not thirsty enough to drink this.\n");
    }

    return 1;
}
