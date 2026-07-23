
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西门");
  set ("long", @LONG
这里是九江的西门了。有很多商旅和武林人士进进出出。有几个官
兵在这里检查来往的行人。旁边站着一名军官，看起来神气十足，不停
地指手画脚。
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie2",
 "southwest":__DIR__"wguanlu1",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

