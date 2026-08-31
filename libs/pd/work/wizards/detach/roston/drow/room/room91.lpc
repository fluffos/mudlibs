#include <std.h>
#include <roston.h>
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

set_exits( ([ "out" : DROWROOM"room90" ]));
}                                                             
void reset() {
 

  ::reset();
     if(!present("guard"))
       {

new(DROWMOB"g_guard")->move(this_object());
new(DROWMOB"def")->move(this_object());
new(DROWMOB"def")->move(this_object());
new(DROWMOB"soldier")->move(this_object());
new(DROWMOB"archer")->move(this_object());
new(DROWMOB"calvary")->move(this_object());
new(DROWMOB"general")->move(this_object());   
  }
}
