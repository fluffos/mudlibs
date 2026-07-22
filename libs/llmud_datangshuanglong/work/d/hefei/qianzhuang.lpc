
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","钱庄");
  set ("long", @LONG
这里是一家钱庄。这家钱庄在这里的信誉很好，来存钱的人很多。
钱庄老板正在那里算账，店里的伙计正在招呼来存钱的客人。
LONG);

  set("exits", ([ 
	  "south":__DIR__"dongdajie2",
   ]));

  set("objects",([
	  __DIR__"npc/chang":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}

