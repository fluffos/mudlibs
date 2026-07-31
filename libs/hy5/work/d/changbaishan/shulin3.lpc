
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","松树林");
  set ("long", @LONG
这里是一片松树林。树木挡住了呼啸的北风，这里稍微暖和一些。
据说这里是人参的盛产地，也不知道是不是真的。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"shulin2",
 "south":__DIR__"shulin4",
         ]));
  set("objects",([
      __DIR__"npc/she":2,
      ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

