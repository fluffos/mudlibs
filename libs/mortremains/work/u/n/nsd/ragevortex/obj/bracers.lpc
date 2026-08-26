/*
** File: bracers.c
** Author: Ragevortex
** Other comments: Ragevortex's Bracers of thunderbolt
** Updated by: Lady Nsd (july 2000)
*/

#include <mudlib.h>

inherit ARMOR ;

void create() {
    set("id", ({"bracers", "twins"}) );
    set("short", "a pair of bracers");
    set("long", "Ragevortex's twin bracers of thunderbolt.\n");
    set_armor_type("bracers");
    set("size", 8);
    set("charges", 999);
    set("value", 7550);
}


void init() {
    add_action("cast_missile", "use") ;
}

int cast_missile (string str) {
    string targname ;
    int damage, hp, charges, skill ;
    object target ;

    if (this_player()->query("stop_attack")>0) {
	write ("You are too busy to do that right now.\n") ;
	return 1 ;
    }
    if (!str) {
	notify_fail("Use the  bracers on whom?\n");
	return 0 ;
    }
    if (sscanf(str,"bracers on %s",targname) != 1) {
	notify_fail ("Who do you want to use the bracers on?\n");
	return 0 ;
    }
    target = find_living(targname) ;
    if (!target) {
	notify_fail ("I don't see that here.\n") ;
	return 0 ;
    }
    if (target==this_player()) {
	notify_fail ("I don't think you want to do that.\n") ;
	return 1;
    }
    if (environment(target) != environment(this_player())) {
	notify_fail ("That is not here to be pointed at.\n") ;
	return 1;
    }
    write("A shining energy ball shoots out from the bracers.\n");
    this_player()->block_attack(2) ;
    target->kill_ob(this_player()) ;
    this_player()->set_target(target) ;
    this_player()->missile_effect() ;
    charges = query("charges") ;
    if (charges==1) {
	write("The bracers shatter into pieces!\n") ;
	remove() ;
	set ("charges", charges-1) ;
	return 1 ; 
    }
}
