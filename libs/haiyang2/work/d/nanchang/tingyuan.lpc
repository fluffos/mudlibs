
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","庭院");
  set ("long", @LONG
这里是李财主家的庭院，院中种植了很多花草。南边是李财主女二
的闺房。
LONG);

  set("exits", ([ 

  "east":__DIR__"dafu",
  "south":__DIR__"guifang",
  "north":__DIR__"huayuan",
  "west":__DIR__"dating",
      ]));
  set("objects",([
 __DIR__"npc/li":1,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!userp(me)&&(dir=="east"||dir=="south"))
		return 0;
	return ::valid_leave(me,dir);
}
