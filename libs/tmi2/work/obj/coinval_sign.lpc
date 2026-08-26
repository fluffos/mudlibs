// The sign that gives the current exchange values. It queries coinvalue.c
// so it should stay current.
// The standard bank and the standard exchange both clone this sign.
// Written by Mobydick in October of 1992.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;
inherit COINVALUE ;

void create() {

	string *types ;
	string long ;
	int i ;

	set ("id", ({ "sign" }) ) ;
	set ("short", "Exchange rate sign") ;
	types = cointypes() ;
	long = "The least valuable coin in the realm is the "+types[sizeof(types)-1]+" coin.\n" ;
	for (i=sizeof(types)-2;i>-1;i--) {
		long += "A "+types[i]+" coin is worth "+coinvalue(types[i])+" "+types[sizeof(types)-1]+" coins.\n" ;
	}
	set ("long", long) ;
}

int set_location (mixed dest) {
	::move (dest) ;
}

// This makes it impossible to pick it up.

int move (mixed dest) {
	return MOVE_NOT_ALLOWED ;
}
