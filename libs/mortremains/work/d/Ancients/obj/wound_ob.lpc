// Ilzarion coded this.
// No clue when.

#include <move.h>
#include <mudlib.h>

inherit OBJECT;

void create() {
    set("id", ({ "#WOUND_OB#" }) );
    /*
	set("extra_look", "$N has horrible bleeding wounds!\n");
    */
    set("dest_at_die", 1);
    set("prevent_drop", 1);
    set("woundlevel", 0);
}

int move(mixed dest) {
    string tmp ;
    int i ;
    object ob ;    
    if (living(dest)) {
	ob = present("#WOUND_OB#", dest);
	if (ob){
	    /*
			ob->set("woundlevel", (ob->query("woundlevel") + 
			    query("woundlevel")));
	    */
	    remove();
	    return MOVE_OK ;
	}
	if (!ob) {
	    i = ::move(dest) ;
	    return i ;
	}
    }else{
	remove();
    }               
}                       
