#include <mudlib.h>
#include "sigil.h"
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
      set ("light", 1) ;
     set ("long",
"You are in a cell. \n"+
"These are some of the cleanest rooms in Sigil.\n") ;
  set("short", "A cell.") ;
     set ("exits", ([
   "south" : SIGIL + "prison2" 
  ]) ) ;
  set("objects", ([
    MON(prisoner) : 2,
   ]) ) ;
  reset() ;
}
