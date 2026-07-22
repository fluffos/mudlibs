
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","紫霞峰");
  set ("long", @LONG
紫霞峰位于天池东侧，西北与华盖峰相对，南与孤隼峰相望。紫霞
峰由紫色沙石堆积，远观之烟云缭绕，宛若西天落霞，紫气生辉，古香
古色，因而得名。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"huagai-feng",
 "southwest":__DIR__"tianhuo-feng",
       ]));
  set("objects",([
   __DIR__"npc/youke":2,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

