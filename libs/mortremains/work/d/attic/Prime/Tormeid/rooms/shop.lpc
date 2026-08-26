#include <mudlib.h>
#include "../defs.h"

inherit SHOP ;

void create() {
     ::create();
     set ("light", 1) ;
	set("forbidden", 1);
     set ("long",
@ENDLONG
This quiant little shop is nestled into one of the Castle's many 
rooms on the second floor.

Commands are: buy, list, sell, and appraise.
ENDLONG
  );
  set("short", "The Tormeid Local Trader.") ;
     set ("exits", ([
  "east": ROOMS(bshall2),
  ]) ) ;
}
