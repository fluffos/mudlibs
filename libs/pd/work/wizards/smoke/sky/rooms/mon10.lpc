#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("Steel Hammer Monastery");
  set_long(
   "%^BOLD%^Stone walls surround the hallway with candle "
   "holders adorning them. Stained glass windows allow "
   "colorful light to shine through. A bench with wonderful "
   "carvings and a big cushion sits against the wall.%^RESET%^");
  set_items(([
    "walls" : "The stone walls are cold and gray. They've "
    "been pollished smooth, reflecting the "
    "light.",
    "door" : "A wooden door on the eastern wall leads "
    "into another part of the monastery.",
    "bench" : "The bench has some wonderful carvings "
    "and a big, comfy looking cushion.",
    "holders" : "Golden candle holders line the walls.",
    "windows" : "Colorful windows decorate the monastery."
   ]));
  set_smell("default", "The smell of insence provides a sense of tranquility.");
  set_listen("default", "It is very quiet.");
  set_exits( ([ 
    "north" : ROOMS "mon11",
    "south" : ROOMS "mon9"]));
}
