
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是西大街。西面就是九江的西门了。北面是九江的盐局。由于
目前世道混乱，所以应承官府运盐的多是武林中豪杰人士。只听轰隆声
中，一个江湖豪客赶着车朝里边走去。西边是九江的西门，有几个官兵
正在那里检查着进出的行人。
LONG);

  set("exits", ([ 
  "north":__DIR__"yanju",
  "east":__DIR__"xidajie1",
  "west":__DIR__"ximen",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

