
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","文殊殿");
  set ("long", @LONG
这里是净念禅院的文殊殿。这里供奉了一座文殊菩萨的铜像，骑在
金毛狮背，高达两丈许，彩塑金饰，颇有气魄。有几个僧人正在颂经念
佛。
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"shijie1",
	  "eastup":__DIR__"shijie2",
  
         ]));
  
  set("objects",([
     __DIR__"npc/buchi":1,
     ]));

  set("valid_startroom", 1);
  setup();
 
}
