#include <std.h>
#include <key.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The Dou beach");
   set_long("On this small isle, it is quite easy to find a beach, "
	"seeing as the entire island is a beach! Not much life can "
	"be seen on this island, but it is still a nice place to sit "
	"down and relax.");
   set_items(([
	"isle" : "Dou isle is a clam and relaxing place.",
	"beach" : "Surfer's paradise."
   ]));
   set_exits(([
        "south" : "/d/freepk/keys/dou/beachse",
         "west"  : "/d/freepk/keys/dou/beach"
   ]));
}

void reset() {
 ::reset();
   if (!present("fish"))
      new("/d/freepk/keys/dou/fish")->move(this_object());
}
