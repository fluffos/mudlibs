#include <mudlib.h>
#include "../ww.h"
#include "/u/d/dragoon/include/format.h"

inherit ROOM ;

int lifted ;

void create() {
    ::create() ;
    seteuid(getuid()) ;
    set("light", 1) ;
    set("short", "town square") ;
    set("long", format(
	"The grayish-brown paving stones in the north-east corner of the square "
        "are much less traveled than the other high traffic areas. "
        "Off to the north-west, sits the governor's mansion, to the south, lies "
         "the main road through town. A large grate in the stone stands out. "
      )) ;
    set("exits", ([
      "west" : ROOMS+"tsq_nw",
      "south" : ROOMS+"tsq_se",
    ])) ;
    set("item_desc", ([
      "grate" : "A heavy iron grate covering a sewer system. It looks like "+
      "it could be lifted to gain access to the sewers.\n",
      "mansion" : "The mansion to the northwest is built of red brick and "+
      "covered with a slate roof.\n",
      "paving stones" : "Large grayish-brown stones used to pave the city. "+
      "They are worn with age.\n",
    ])) ;
    lifted = 0 ;
}

void init() {
    add_action("lift_grate", "lift") ;
}

int lift_grate(string str) {
    int chance ;
    if(str!= "grate") {
	notify_fail("That cannot be lifted.\n") ;
	return 0 ;
    }
    if(lifted!=0) {
	write("The grate has already been removed.\n") ;
	return 1 ;
    }
    chance = random(80)+ this_player()->query_stats("strength") ;
    if(chance<50) {
	notify_fail("You try to lift the grate and fail!\n") ;
	say(this_player()->query_cap_name()+" fails to lift the grate.\n") ;
	return 0 ;
    }
    write("You heave the heavy grate aside, revealing a steps down "+
      "into the sewers.\n") ;
    set("exits/down", ROOMS+"sewer1") ;
    set("post_exit_func", ([ "down" : "replace" ])) ;
    lifted=1 ;
    return 1 ;
}

int replace() {
    lifted = 0 ;
    delete("exits/down") ;
    write("You slide the grate back as you climb down into the sewers.\n") ;
    say(this_player()->query_cap_name()+" slides the grate back into place.\n") ;
    return 1 ;
}
