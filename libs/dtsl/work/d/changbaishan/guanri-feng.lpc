
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","观日峰");
  set ("long", @LONG
观日峰位于天池东南。西连孤隼峰。三奇峰峰顶有洞直通天池，峰
下有很多五色石，鲜艳光润，令人爱不释手，
LONG);

  set("exits", ([ 
 "west":__DIR__"gusun-feng",
 "south":__DIR__"wohu-feng",
 "northwest":__DIR__"pingjin-feng",
         ]));
  set("objects",([
   __DIR__"npc/youke":2,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

