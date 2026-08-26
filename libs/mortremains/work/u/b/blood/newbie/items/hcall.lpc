
#include <mudlib.h>
#include <move.h>

inherit OBJECT ;

void create() {
    seteuid(getuid());
    set ("id", ({ "havens", "call", "havens call" }) ) ;
    set ("short", "The Haven's Call") ;
    set ("long", @EndText
The Haven's Call was invented by wizards to let them see whom ever they 
want, whenever they want. However one key thing, it can only be used once.
On it's side are etched are the words "call playername".
EndText
    );
    set ("mass", 1) ;
    set("enchantment", 5);
    set("value", 2500);
}

void init() {
    add_action("call_player", "call");
}

int call_player(string name) {
    object player;
    int res;

    if(!name) {
	notify_fail("Call whom?\n");
	return 0;
    }

    player = find_player(name) ;
    if (!player) {
	notify_fail ("There is no one logged on by that name.\n") ;
	return 0 ;
    }

    if (wizardp(player)) {
	notify_fail("You cannot call  wizards.\n") ;
	return 0 ;
    }

    res = player->move(environment(this_player())) ;

    if (res==MOVE_OK) {
	write ("Havens call does your bidding, calling "+
	  capitalize(name)+" to you.\n") ;
	tell_object(player,(string)this_player()->query("cap_name")+
	  " has used havens call, summoning you to "+
	  objective((string)this_player()->query("gender"))+"!\n");
	tell_room(environment(TP), TPN+" just invoked the powers of The "+
	  "Havens Call on "+ player->query("cap_name")+"!\n", 
	  ({ TP, player }) );
    } else {
	write ("The Haven's Call's powers have failed!\n") ;
    }

    tell_object(TP, "The Haven's Call fades into non-existance.\n");
    remove();

    return 1 ;
}
