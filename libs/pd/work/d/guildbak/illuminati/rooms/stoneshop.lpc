#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
::create();
  set_name("Magic shop");
  set_properties((["light" :2, "indoors": 1, "no scry" : 1, "no attack" : 1 ]));
  set_short("Illuminati Tower");
  set_long("%^ORANGE%^This strange room has all sorts of odd figurines placed all around on shelves. Each of them radiates with magical energy and has a specific purpose, it would be best not to touch them. At the back of the room is a bench with a man standing behind it, waiting to serve you. A sign hangs on the wall.%^RESET%^");
  set_exits(([
     "northeast" : ILROOM"floor2",
  ]));
}

void reset() {
   ::reset();
   if(!present("rand"))
   new(ILMOB"rand")->move(this_object());

}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}
