#include <std.h>
#include <key.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The Dou shores");
   set_long("The sandy shore of the Dou Key cannot support much life, "
	"though every now and again a fish or some other marine life "
	"will get washed ashore. The soft blue ocean spreads as far as "
	"they eye can see.");
   set_items(([
	"ocean" : "It is a beautiful and relaxing sight to see.",
	"shore" : "You are on the shore of the Dou Key."
   ]));
   set_exits(([
        "north" : "/d/freepk/keys/dou/beach",
         "east"  : "/d/freepk/keys/dou/beachse"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab"))
     new("/d/freepk/keys/dou/crab")->move(this_object());
}

