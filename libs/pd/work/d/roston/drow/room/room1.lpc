#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("E_camp");
set_long("The entrance to the camp. The camp is huge. It is spread out "
         "through the cave and into other cave openings. Dark elves can "
         "be seen moving about the camp.");

set_exits( ([ "north" : DROWROOM"room2",
              "south" : DROWROOM"path1" ]));
           set_pre_exit_functions( ({ "north" }), ({ "go_north" }) );
}                                                              

void reset() {

  ::reset();
     if(!present("guard"))
       {
       new(DROWMOB"guard")->move(this_object());
       new(DROWMOB"guard")->move(this_object());
   }

}
int go_north() {
    if(present("guard")) {
        present("guard")->force_me("emote Blocks your way.");
        return 0;
    }
    else return 1;
}
