// The physical representation of the newsreader. It includes some basic
// help, though not as much as the newsreader itself does.
// This gives the newsreader more of a MUDlike flavor.
// Written by Mobydick@TMI-2, 12-12-94/
// The idea for this representation was suggested by Archimedes@TMI-2
// Leto hacked about around 188-200 (gettin tmp to work right)
// but isn't done yet (feel free ;)  950211

#include <mudlib.h>
#include <newsreader.h>

inherit OBJECT ;

void create() {
	seteuid(getuid()) ;
	set ("short", "a newspaper") ;
	set ("long", "A copy of the TMI-2 News. You could \"open\" it.\n"+
	"You might want to type \"help paper\" before opening it.\n") ;
	set ("id", ({ "news", "paper", "newspaper" }) ) ;
	set ("value", ({ 2, "copper" }) ) ;
	set ("mass", 5) ;
	set ("bulk", 10) ;
}

void init() {
	add_action("open", "open") ;
	add_action("help", "help") ;
}

int open (string str) {
	object barfulator ;

	if (str=="paper" || str=="newspaper") str=0 ;
	barfulator = clone_object(NEWS_OBJ) ;
	barfulator->start_up(str) ;
	return 1 ;
}

int help (string str) {
	if (!str || (str!="paper" && str!="newspaper")) return 0 ;
	write (@ENDHELP
This object is a front-end for Beek's rn.c newsreader. To start up news
normally, just type "open". You can also:
open -all:  See all news in subscribed groups, even if already read.
open -post <group>: Post to the named group.
open -poster <name>: I don't know what that does.
Once you are in the newsreader, you can type "h" for help at any time.
ENDHELP) ;
	return 1 ;
}

// I don't want to have zillions of newspapers lying around.
// The alternatives are to dest them when dropped somehow, or to have
// them be autoloading. I've settled for the latter cause it's easier :)

int query_auto_load() {
	return 1 ;
}
