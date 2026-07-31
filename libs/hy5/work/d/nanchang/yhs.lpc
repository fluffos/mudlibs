
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","文峰塔");
  set ("long", @LONG
文峰塔位于安义县城东侧潦河畔。始建于明代崇祯三年
（1630年），塔七级，高约七丈，以砖石砌成六面形，逐
级有台阶、板楼、门窗、可供游人跳望。 
LONG);

  set("exits", ([ 
  "southwest":__DIR__"hupao",
        ]));
  set("objects",([
       __DIR__"npc/daoke":2,
       ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

