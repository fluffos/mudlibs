
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是合肥的东大街。这里人来人往，非常热闹。北边有一家钱庄。
钱庄的金字招牌在阳光的照耀下闪闪发光。钱庄的门口站着几个保镖，冷
冷地打量着来往的行人。
LONG);

  set("exits", ([ 
	  "west":__DIR__"dongdajie1",
      "east":__DIR__"dongdajie3",
      "north":__DIR__"qianzhuang",
  ]));
  
  set("objects",([
  	__DIR__"npc/qigai":1,
  ]));

  set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

