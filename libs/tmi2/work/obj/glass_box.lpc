// glass_box.c
// This object is invisible to players, though not to wizards.
// If a player becomes aware of its existence somehow, he can pick it
// up and drop it and sell it and so on, and it will show up on his
// inventory list, marked "invisible".
// Probably this item isn't too useful, but you should be able to think
// of all kinds of uses for invisible items in your own game.
// Written for debugging purposes by Mobydick on 93-08-24.

#include <mudlib.h>

inherit OBJECT ;

void create() {
	set ("id", ({ "box", "glass", "glass box" }) ) ;
	set ("short", "a fine glass box") ;
	set ("long",
"The glass is so fine and transparent, you feel lucky to be able to see the\n"+
"box at all.\n") ;
	set ("invisible", 1) ;
	set ("mass", 100) ;
	set ("bulk", 15) ;
	set ("value", ({ 2, "platinum" }) ) ;
}
