
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是南昌的东大街。西边是南昌的中心。从这里可以听到热闹喧
哗的声音。南边有一家药店，看来生意还不错，一阵淡淡的药香从那里
传来。这里的行人很多，多是往西边的鄱阳湖走去。
LONG);

  set("exits", ([ 

  "south":__DIR__"yaodian",
   "east":__DIR__"dongdajie2",
   "west":__DIR__"center",
         ]));
  set("objects",([
	  __DIR__"npc/liumang":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

