#include <mudlib.h>
#include "../defs.h"

inherit PUB;

void create() {
     ::create();
	seteuid(getuid());
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are in the rowdy pub of the commoners - The Drunken Ass.

Commands are: menu, buy <drink>, powerheal <drink>
ENDLONG
  );
  set("short", "The Drunken Ass.") ;
  set("exit_msg", ([
  ]) ) ;
  set("item_desc", ([
   "man" : "He's the bartender.  He looks like he's experienced.\n",
   "bar" : "It's got all your alcohol needs.\n",
  ]) ) ;
     set ("exits", ([
   "east" : ROOMS(bshall6),
  ])  ) ;
}

