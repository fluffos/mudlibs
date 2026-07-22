
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是江边的小路。旁边就是滚滚的长江。这里风景秀丽，山水如
画，空气清新。一阵风吹过，江水的潮湿气息扑鼻而来。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaolu2",
  "southwest":__DIR__"jiangbei",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

