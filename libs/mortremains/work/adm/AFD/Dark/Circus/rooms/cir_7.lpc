#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
  set_outside("zone", "2");
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The far north corner of the circus grounds.");
set("long", @ENDLONG
The clearing begins to narrow here.  The tents have begun to thin out
and become larger.  At the end of the clearing, a very large wagon
towers over you.  The warped trees seem almost to hold the wagon to them,
as if the wagon was part of the darkness they dwell in.
ENDLONG
);
  set("item_desc", ([
    "woods" : "Dark trees of all kinds lurk behind the wagon.\n",
    "wagon" : @EndText
The wagon is perhaps fifteen feet high and seventeen feet long.  The
wood it was fashioned out of is polished to a fine shine.  Black
velvet curtains conceal whatever horrors lurk  within.
EndText,
 ]) );
set("smell", ([ 
     "default" : "The trees have begun emiting a pungent bitter odor.\n",
     "wagon" : "It has the smell of wet wood, but has a burned quality to the soft
essence.\n",
]) );
  
set("exits", ([
  "west" : ROOMS(cir_4),
    "enter" : ROOMS(wag4.c),
]) );
::create();
}
