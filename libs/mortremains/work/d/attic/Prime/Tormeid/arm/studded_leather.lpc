#include <mudlib.h>
#include "../defs.h"

inherit ARMOR ;

void create() {
  seteuid(getuid());
  set("id", ({ "leather", "armor", "armour", "leather armour", "leather armor",
     "studded leather" }) ) ;
  set("short", "studded leather") ;
  set("long", @ENDLONG
A suit of tanned leather stitched together and metal studs to provide
extra protection.
ENDLONG
  );
  set("value",200);
  set_armor_type("leather") ;
  set("armor", 5) ;
  set("size", 6);
}



