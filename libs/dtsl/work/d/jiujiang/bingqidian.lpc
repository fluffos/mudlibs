
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器店");
  set ("long", @LONG
这里是个兵器店。由于是在战乱年代，所以这里的生意特别好。铁
匠在那里忙个不停，不知是为哪个势力在打造兵器。四下看去，只见角
落里堆积了很多兵器，刀、枪、杖，各种样式，应有尽有。只听乒乓声
中，又一件兵器打造好了。
LONG);

  set("exits", ([ 

  "south":__DIR__"dongdajie3",

         ]));
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

