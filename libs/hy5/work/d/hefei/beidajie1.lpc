
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是合肥的北大街。南边是合肥的中心了。从这里可以听到中央
广场热闹的声音。只见几个武士打扮的人从你的身旁走过，还不时回头
冷冷地打量你几眼。不时有小商贩推着车从你的身旁擦过。
LONG);

  set("exits", ([ 
	  "north":__DIR__"beidajie2",
  "south":__DIR__"center",
     ]));
  
  set("objects",([
  	__DIR__"npc/wushi":1,
  ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

