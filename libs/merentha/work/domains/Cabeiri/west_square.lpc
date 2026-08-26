// Petrarch
// Merentha Lib 1.0

#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_short("The courtyard of Cabeiri Castle");
  set_long("The great gates of Cabeiri Courtyard stand to the west.  They \
are wide open and welcome visitors.  Two large buildings are here, the \
one to the north is the fighter hall and the hall to the south belongs to
the monks.  Towards the east is Cabeiri Castle.");
  set_items(([
"fighter hall":"The hall of fighters is to the north.  It is a rather large building with a big mural of combat on the walls.",
"north":"The hall of fighters is to the north.  It is a rather large building with a big mural of combat on the walls.",
"monk hall":"The monk hall is to the south.  Murals of prayer adorn the exterior walls.",
"south":"The monk hall is to the south.  Murals of prayer adorn the exterior walls.",
"courtyard":"This is Cabeiri Courtyard.  It is protected by tall walls.",
"castle":"The castle entrance at the eat side of Cabeiri courtyard.",
]));
set_exits((["gates":"/domains/Cabeiri/entrance",
"east":"/domains/Cabeiri/square",
"north":"/domains/Cabeiri/fighter_hall",
"south":"/domains/Cabeiri/monk_hall",
]));
}
