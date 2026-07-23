
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","天池");
  set ("long", @LONG
这里就是最有名的长白山天池了，天池湖水深幽清澈，象一块瑰丽 
的碧玉镶嵌在群山环绕之中，使人如临仙境。不过，长白山气候瞬息万
变，使得天池若隐若现，故绘出了天池“水光潋滟晴方好，山色空蒙雨
亦奇”的绝妙景象。 
LONG);

  set("exits", ([ 
 "westup":__DIR__"baiyun-feng",
 "up":__DIR__"tiebi-feng",
 "southup":__DIR__"pingjin-feng",
 "eastup":__DIR__"yingzui-feng",
 "northup":__DIR__"luming-feng",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

