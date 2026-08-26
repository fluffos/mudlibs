#include "cm_h" 
void create() {
  seteuid(getuid());   
  make_scary();
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In a mysterious cemetary.");
set("long", @ENDLONG
A small house, painted white stands before you to the
north.  The windows are in dire need of washing.
There is a small porch with an ancient rocking chair
standing there like a monolith compared to the barren
decorations.
ENDLONG
);

set("exits", ([
  "east" : ROOMS(cm_np3),
  "west" : ROOMS(cm_np4),
  "north" : ROOMS(cm_in),
  "south" : ROOMS(cm_n3),
]) );
::create();
}