//  Ship Debris Room
//    Whit
#include <teststd.h>
#define DEFAULT_WAIT 60
inherit ROOM;
void create() {
    ::create();
    set_name("ship debris");
    set_long("This is some of the debris that is left of your ship.  "
      "The debris seems to be floating along the ocean.  Hopefully you "
      "will land somewhere.\n");
    set_short("on some debris on the ocean");
    set_properties(([ "light":1,"night light":1 ]));
    skip_obvious();
    call_out("land", DEFAULT_WAIT);
}
void land() {
    object *all;
    int i;
    i=sizeof(all=all_inventory(this_object()));
    while(i--) {
	message("", "After along drift, you find yourself floating "
	  "inside of a dock.  You climb off of the debris and up "
	  "on the docks.\n", all[i]);
	all[i]->move("/d/tirun/loadb");
	this_object()->remove();
    }
}
