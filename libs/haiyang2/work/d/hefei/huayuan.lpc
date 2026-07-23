
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","花园");
  set ("long", @LONG
这里是一个花园。这里种了很多鲜花，有很多人在这里游玩。各种
鲜花争奇斗艳，争相开放。旁边还有几个假山，造型独特，怪石嶙峋，
形状各异。还有几个游客在旁边吟诗做对，大有“商女不知亡国恨”的
气势。
LONG);

  set("exits", ([ 
	  "west":__DIR__"nandajie1",
  ]));
 set("objects",([
	 //__DIR__"obj/xianrenzhang":2,
	 __DIR__"npc/xiaojie":1,
	 ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

