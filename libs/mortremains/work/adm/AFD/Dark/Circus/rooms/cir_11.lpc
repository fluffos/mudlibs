#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
  set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
set("short", "an open field.");
  
set("long", @ENDLONG
This is an open field.  The ground has been cleaned and
cleared here.  The field is open in a circular pattern with
a twenty foot diameter.
ENDLONG
);
  set("item_desc", ([
    "field" : "This field looks quite clean.\n",
 ]) );

  set("objects", ([ MON(acrobat) : 1, ]) );

  set("exits", ([
    "north" : ROOMS(cir_8),
]) );
  ::create();  
}
