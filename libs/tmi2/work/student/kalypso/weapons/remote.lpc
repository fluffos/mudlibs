#include <mudlib.h>

inherit WEAPON ;

void create() {
	set ("id", ({ "remote" }) ) ;
	set ("short", "a deadly evil remote") ;
	set ("long" , @EndText
This is the remote to the television only it looks a little different.
It seems to have an evil glow. You might try to Wield it. 
EndText
);
	set ("mass", 120) ;
	set ("bulk", 30) ;
	set ("value", ({ 75, "gold" }) ) ;
	set ("weapon", 5) ;
	set ("damage", ({ 2,8 }) ) ;
	set ("type", "bludgeoning") ;
	set ("name", "remote") ;
	set_verbs( ({ "attack", "swing at", "mute volume", "turn power off" }) ) ;
	set_verbs2( ({ "attacks", "swings at", "mutes volume", "turns power off" }) ) ;
	set("second", 0) ;
	set("nosecond",0) ;
	set ("wield_func", "glow") ;
	set ("unwield_func", "noglow") ;
}

void glow() {
	write ("The remote begins to glow in your hand.\n") ;
	say ("The remote begins to glow in "+possessive(this_player()->query("gender"))+" hand.\n") ;
	set ("light", 1) ;
}

void noglow() {
	say ("The remote stops glowing.\n") ;
	say ("It ceases to glow.\n") ;
	set("light", 0) ;
}
