#include <std.h>
#include <event.h>
#include <citrin.h>

inherit ROOM;
int go_south() {
   if(!wizardp(this_player())) {
     write("A strange force repels you.\n");
     return 0;
    }
    return 1;
}

void create() {
    ::create();
    set_name("clearing");
    set_short("clearing in the path");
    set_long("The trees clear out.  A large field starts to the south.  "
      "There is no path leading into the field.  A grey mist hovers "
      "over most of the field.");
    set_properties((["light":1,"night light":1, "forest":1]));
    set_items(([
	"field":"Mist hovers over it making it almost "
	"impossible to see any further.",
      ]));
   set_pre_exit_functions( ({"south"}), ({"go_south"}) );
    if(E_D->is_started()) {
	set_exits(([
	    "northwest":ROOMS"59",
	    "south":"/d/events/rooms/stones",
	  ]));
    } else 
	set_exits(([
	    "northwest":ROOMS"59",
            //"south":ROOMS"stones",
	  ]));
}

