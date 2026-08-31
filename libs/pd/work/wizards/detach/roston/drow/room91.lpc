#include <std.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("This is the tent of the drow general, she is the "
"the leader of the army and is well respected. The members "
"are in here to draw up the the plans for battle.");

set_exits( ([ "out" : "/wizards/detach/roston/drow/room90" ]));
}                                                             
void reset() {
 

  ::reset();
     if(!present("guard"))
       {

new("/wizards/detach/roston/drow/mon/g_guard")->move(this_object());
new("/wizards/detach/roston/drow/mon/def")->move(this_object());
new("/wizards/detach/roston/drow/mon/def")->move(this_object());
new("/wizards/detach/roston/drow/mon/soldier")->move(this_object());
new("/wizards/detach/roston/drow/mon/archer")->move(this_object());
new("/wizards/detach/roston/drow/mon/calvary")->move(this_object());
new("/wizards/detach/roston/drow/mon/general")->move(this_object());   
  }
}
