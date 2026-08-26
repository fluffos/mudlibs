//_Hide.c started on June 12th, 1997 by Nightmask@Nightfall's Keep
//   This will make the thief class able to slip into the shadows.
#include <mudlib.h>

inherit DAEMON;

/*
#define TPN this_player()->query("cap_name")
*/

int cmd_Hide() {
    object ob, hide_ob;
    int invis;
    ob = this_player();

    if (TP->query_attacker()) {
	write("You cannot hide while in combat!\n");
	return 1;
    }

    invis = (int)ob->query("invisible");
    if (!invis) {
	say(TPN+" fades into the shadows.\n");
	write("You fade into the shadows.\n");
	ob->set("invisible", 1);
	ob->do_new();
	hide_ob = present("#HIDE_OB#", ob);
	if (!hide_ob){
	    hide_ob = clone_object ("/d/class/rogue/obj/hide_ob") ;
	    hide_ob -> move (ob) ;
	}
	hide_ob -> set("move_counter", (ob->query_level("thief") + 3) );
    } else {
	write("You are already hidden!\n");
    }
    return 1;
}
