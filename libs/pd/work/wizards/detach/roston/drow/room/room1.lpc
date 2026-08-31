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
set_long("This seems to be the opening to a giant camp. Your not sure "
   "who is camped here but, the camp looks as if its spread out for miles "
   "and miles. It looks as if the whole camp is seting up for a big attack "
   "on the town to the south. ");

set_exits( ([ "north" : DROWROOM"room2",
              "south" : DROWROOM"path1" ]));
           set_pre_exit_functions( ({ "north" }), ({ "go_north" }) );
}                                                              
void reset() {
  int i, x;
    object ob, thing;

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
