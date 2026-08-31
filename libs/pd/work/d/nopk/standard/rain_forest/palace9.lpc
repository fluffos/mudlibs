#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Outside the council room");
   set_long("The room outside the council "
            "room. There are a few chairs lined up against the"
            " walls. The council is apparently not dealing with"
            " anything at the moment");
   set_exits((["southwest" : ROOMS"palace10",
               "northwest" : ROOMS"palace8"]));
  set_pre_exit_functions( ({"southwest"}), ({"go_southwest"}) ); 

  set_items((["chairs" : "These are wooden chairs with pillows on "
               "them"]));
}

void reset() {
   ::reset();
   if(!present("guardian")) {
   new(MOB"guard5")->move(this_object());
   new(MOB"guard5")->move(this_object());
   }
}

int go_southwest() {
   if(present("guardian")) {
    present("guardian")->force_me("say Not unless you are scheduled.");
     return 0;
  }
    else return 1;
}
