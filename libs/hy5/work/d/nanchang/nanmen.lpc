
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"南门"NOR);
  set ("long", @LONG
这里是南昌的南门。南昌是旅游胜地，所以这里的行人很多。这里
有两个官兵，在检查着来往的行人。
LONG);

  set("exits", ([ 

  "north":__DIR__"nandajie2",
  "south":"/d/changsha/road8",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

