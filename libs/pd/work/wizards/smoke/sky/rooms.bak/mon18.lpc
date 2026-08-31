#include <std.h>
#include <cp.h>
inherit VAULT;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
    "no teleport" : 1]) );
  set_short("Steel Hammer Monastery");
  set_long(
   "%^BOLD%^Stone walls surround the hallway with candle "
   "holders adorning them. Stained glass windows allow "
   "colorful light to shine through. A wooden door is "
   "on the southern wall, leading into an office. Hand woven tapestries cover "
   "the walls on both sides of the door.%^RESET%^");
  set_items(([
    "walls" : "The stone walls are cold and gray. They've "
    "been pollished smooth, reflecting the "
    "light.",
    "door" : "A wooden door on the southern wall leads "
    "into another part of the monastery.",
    "tapestries" : "Hand woven tapestries cover the wall. "
    "They are covered with religious symbols.",
    "symbols" : "The symbols are only important to "
    "Steel Hammer Villagers.",
    "holders" : "Golden candle holders line the walls.",
    "windows" : "Colorful windows decorate the monastery."
   ]));
  set_smell("default", "The smell of insence provides a sense of tranquility.");
  set_listen("default", "It is very quiet.");
  set_exits( ([ 
    "west" : ROOMS "mon17",
    "east" : ROOMS "mon19",
    "enter office" : ROOMS "mondoor1"]));
  cover_exit_with_door("enter office", "bishop_office_door");
}
