
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","松树林");
  set ("long", @LONG
这里是一片松树林。树木挡住了呼啸的北风，这里稍微暖和一些。
远处有几个采参的人。
LONG);

  set("exits", ([ 
 "west":__DIR__"shanlu3",
 "northeast":__DIR__"shulin3",
         ]));
  set("objects",([
      __DIR__"npc/she":2,
      ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

