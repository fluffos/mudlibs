// light_sword.c
// This sword casts light when wielded: it stops casting it when unwielded.
// Written by Mobydick@TMI-2, 7-3-93
// Based on an idea by Kaeleaxe@TMI-2

#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "sword" }) ) ;
	set ("short", "a long shiny sword") ;
	set ("long", "This sword gleams in the light, and seems valuable.\n") ;
	set ("mass", 120) ;
	set ("bulk", 30) ;
	set ("value", ({ 75, "gold" }) ) ;
	set ("weapon", 5) ;
	set ("damage", ({ 2,8 }) ) ;
	set ("type", "cutting") ;
// message will not be grammatical.
	set ("name", "sword") ;
	set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
	set_verbs2( ({ "attacks", "swings at", "stabs at", "slashes at" }) ) ;
	set("second", 0) ;
	set("nosecond",0) ;
	set ("wield_func", "glow") ;
	set ("unwield_func", "noglow") ;
}

void glow() {
	write ("The sword begins to glow in your hand.\n") ;
	say ("The sword begins to glow in "+possessive(this_player()->query("gender"))+" hand.\n") ;
	set ("light", 1) ;
}

void noglow() {
	write ("The sword stops glowing.\n") ;
	say ("It ceases to glow.\n") ;
	set("light", 0) ;
}
