
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","龙门峰");
  set ("long", @LONG
龙门峰为长白十六峰之一，在乘槎河两岸，与天豁峰相对，因形状
如门，故名龙门。所传，大禹治水曾到过这里，旁边有蝌蚪形柱，名为
神碑。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"pubu",
 "southeast":__DIR__"guanmian-feng",
 "northeast":__DIR__"tiyun-feng",
         ]));
  set("objects",([
   __DIR__"npc/qiangdao":1,
  ]));
  	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,

	]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

