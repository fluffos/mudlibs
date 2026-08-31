#include <std.h>
#include <marsh.h>
inherit VAULT;
create() {
  ::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Marsh");
    set_day_long(
      "The trees in this area is bunched up tightly, leaving no passage "
      "through.  The sounds of bugs buzzing off in the distance is "
      "overwhelming.  The nearby trees are overgrown with moss causing "
      "them to droop.  The sounds of a struggle echo from somewhere near by."
          );
    set_night_long(
      "Trees in this area are very thick, only path out is back to the north. "
      " A slight movement quickly shifts from tree to tree.  Red beady eyes "
      "move in closer at a slow steady pace.  A bat flies overhead and vanishes
"
      "into the darkness."
    );
    set_items(([
        "trees" : "Some of the trees look like it's been painted there.",
        "paint" : "You carefully inspect the paint, theres a faint outline.",
        "outline" : "Looks to be an outline of a door.",
        "door" : "The door is as tall as the trees.",
    ]));
    set_smell("default", "It smells of muddy waters.");
    set_listen("default", "Sounds coming from a southern corner");
    set_exits( ([
"north" : MARSH "marsh13",
"southwest" : TOWN "town23",
    ]) );
    add_invis_exit("southwest");
    set_door("door", TOWN"town23", "southwest", 0);
    set_heart_beat(1);
}

