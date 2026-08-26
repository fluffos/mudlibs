// An elixir of healing.
// Drink this and you get some hits back, you lucky dog.
// It doesn't leave a bottle behind because otherwise empty bottles tend
// to clutter up memory. If you've got RAM to spare, then you might want
// to make an empty bottle object to leave behind. Or maybe not. Who really
// wants two dozen empty bottles?
// Written by Mobydick, 11-20-92.
// Remove this header and the fleas of a thousand camels will infest
// your armpits.

#include <mudlib.h>

#define HEALING 15

inherit OBJECT ;

void create() {
	set ("short", "an elixir of healing") ;
	set ("long", "This is a glowing potion. If you drink it you will become healthier.\n") ;
	set ("id", ({ "potion", "elixir" }) ) ;
	set ("mass", 50) ;
	set ("bulk", 20) ;
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
	write ("You drink the elixir of healing.\n"+
	"As you drink the last drop, the bottle vanishes in a puff of smoke!\n") ;
	res = this_player()->query("hit_points") ;
	max = this_player()->query("max_hp") ;
	res = res + HEALING ;
	if (res>max) res=max ;
	this_player()->set("hit_points", res) ;
	remove() ;
	return 1 ;
}
