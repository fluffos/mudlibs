
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条上山的路。上面就是长白十六峰中的天豁峰，一路上通
过两燕观石、驼峰石、黑熊朝天，补天石，牛郎渡，倒石堆，方可登临
峰顶。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"pubu",
 "eastup":__DIR__"tianhuo-feng",
 "southup":__DIR__"heifengkou",
         ]));
  set("objects",([
   __DIR__"npc/lieren":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

