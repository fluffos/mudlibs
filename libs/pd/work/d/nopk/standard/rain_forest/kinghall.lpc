#include <std.h>
#include <rain.h>
inherit ROOM;

create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("A plain hall");
   set_long("A short hallway. "
            "This hallway is plain white with no decorations at all.");
   set_exits((["north : ROOMS"greed",
               "west" : ROOMS"palace8"]));
}

init() {
   ::init();
   if(!wizardp(this_player()))
   new(MOB"gguard3")->move(this_object());
   force guard("say what do we have here?");
}
