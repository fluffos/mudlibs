
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是合肥的东大街。西边是合肥的中心了。这里的行人很多。这
里可以听到西边热闹的声音。有几个醉汉从你的身旁摇摇晃晃地走过，
嘴里不停地骂着朝廷无道。四周的行人都远远地闪了开来。
LONG);

  set("exits", ([ 
	  "west":__DIR__"center",
      "east":__DIR__"dongdajie2",
  ]));
  
  set("objects",([
  	__DIR__"npc/dizi":1,
  ]));

  set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

