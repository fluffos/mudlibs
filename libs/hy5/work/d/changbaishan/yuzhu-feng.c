
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","玉柱峰");
  set ("long", @LONG
玉柱峰在天池以西，东北与白云峰相临，又名青石峰，山峰高耸，
像一根擎天的玉柱，顶天立地，可谓白云峰之辅弼。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"baiyun-feng",
 "southwest":__DIR__"tiyun-feng",
         ]));

  
  set("outdoors","cbs");
  	set("objects", ([
   __DIR__"npc/gongzi":1,
"quest/skills2/wakuang/kuang/kuangmai" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

