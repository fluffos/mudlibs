
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。西边是一个山崖，东边是一片松树林。上面还有
路，抬头望去，上面隐约有一座庙宇。
LONG);

  set("exits", ([ 
 "eastup":__DIR__"shanlu4",
 "west":__DIR__"shanya",
 "east":__DIR__"shulin2",
 "down":__DIR__"shulin1",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

