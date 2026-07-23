
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是九江的北大街。南边就是九江最繁华的地方了。东边有一家
妓院，就是九江的[春在楼]。门口有许多漂亮的姑娘在招呼着路上的行
人。也有几个江湖莽汉喝得醉熏熏地从里面摇晃着走出。
LONG);

  set("exits", ([ 

  "south":__DIR__"center",
  "north":__DIR__"beidajie1",
  "east":__DIR__"chunyuan",
         ]));
  set("objects",([
      __DIR__"npc/susu":1,
      ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

