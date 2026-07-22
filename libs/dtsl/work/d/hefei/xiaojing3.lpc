
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
这里是条小径。这里是安徽的南部了。平时有江淮军在这里巡逻，
你不禁小心起来。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaojing2",
  "south":__DIR__"shanlu1",
       ]));
  set("objects",([
	  __DIR__"npc/jun":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

