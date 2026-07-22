
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","裁缝店");
  set ("long", @LONG
这里是一家裁缝店。这里的衣服质量很好，在合肥有很高的信誉。
有很多人来这里做衣服，老板忙个不停。
LONG);

  set("exits", ([ 
  "north":__DIR__"xidajie2",
   ]));

  set("objects",([
	  __DIR__"npc/zhang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

