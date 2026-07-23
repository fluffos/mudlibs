
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。抬头望去，可以看到，上面有一座庙宇。从这里
隐约可以听到诵经的声音。
LONG);

  set("exits", ([ 
 "up":__DIR__"shanlu5",
 "westup":__DIR__"zhinv-feng",
         ]));
  set("outdoors","cbs");
  	set("objects", ([

"quest/skills2/wunon/dalie/dalie" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

