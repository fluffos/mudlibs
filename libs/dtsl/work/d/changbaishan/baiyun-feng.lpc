
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","白云峰");
  set ("long", @LONG
沿着冰雪中，猎人、樵夫和采药人的足迹，你登上了长白山的主峰
“白云峰”，白云峰又叫“层岩”。从这望去天池象一块碧玉镶在群山
之中。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"tianchi",
 "southwest":__DIR__"yuzhu-feng",
 "northeast":__DIR__"luming-feng",
 "southdown":__DIR__"pubu"
         ]));
  set("objects",([
   __DIR__"npc/erlengzi":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

