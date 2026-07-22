
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","鹰嘴峰");
  set ("long", @LONG
经天池向西沿着冰雪中，猎人、樵夫和采药人的足迹，你登上了鹰
嘴峰，因为其山峰型入鹰嘴，故得名鹰嘴峰。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"tianchi",
 "southwest":__DIR__"tiebi-feng",
 "southeast":__DIR__"huagai-feng",
 "westup":__DIR__"luming-feng",
         ]));
  set("objects",([
   __DIR__"npc/qiaofu":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

