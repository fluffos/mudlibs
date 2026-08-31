// - Inferno -  Inside the town of Asgard

#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("walking along a dirt road");
   set_long("The dirt road you are walking on leads both "
            "east and west. To the south of you is a small "
            "building that looks to be a shop, though there "
            "are no signs indicating what is sold inside it.");
   set_exits(([
      "west" : "/d/standard/frealmz/town1",
      "east" : "/d/standard/frealmz/town3",
      "south" : "/d/standard/frealmz/general"
   ]));   /*-*-*-*-*-*-*-*-*need to make shop*-*-*-*-*-*-*-*-*/
   set_items(([
      "road" : "The road leads both east and west.",
      "buildings" : "They seem to be stores."
   ]));
}

void reset() {
 ::reset();
   if (!present("a citizen"))
     new("/d/standard/frealmz/mob/mcitizen")->move(this_object());
}
