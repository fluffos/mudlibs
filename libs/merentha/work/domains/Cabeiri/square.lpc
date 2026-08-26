// Petrarch
// Merentha Lib 1.0

#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_short("The courtyard of Cabeiri Castle");
  set_long("The courtyard is filled with shops, halls and \
travellers.  The castle is to the east and extends high into the \
sky.  To the west are the gates of the courtyard.  There is a tall \
archer's tower on each side of the gate where lookouts keep \
watch."); 
  set_items(([
"shop":"There is a shop to the north which appears to supply items for daily use.  To the south are some stands selling food.",
"hall":"There are several halls in the courtyard.  The fighter and monk halls are to the west by the courtward gates.  The mage and healer halls are to the east.",
"castle":"The castle is to the east.  It's gates open into the courtyard.",
"tower":"The archer towers are manned night and day by archers who protect the castle incase of invasion.  Movement can be seen from within them."
]));
set_exits((["west":"/domains/Cabeiri/west_square",
"east":"/domains/Cabeiri/east_square",
"north":"/domains/Cabeiri/north_square",
"south":"/domains/Cabeiri/south_square",
]));
set_sounds((["default":"The sound of everyday commerce fills the streets."]));
}

void reset() {
::reset();
  if(!present("helper")) new(MON "helper")->move(this_object());
}

