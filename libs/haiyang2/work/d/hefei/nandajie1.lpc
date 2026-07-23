
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是合肥的南大街。北边是合肥的中心广场了。这里行人很多。
你向西望去，好象有一个花园。有很多游人都朝那里走去，那边也传来
嬉笑的声音。
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"center",
  "east":__DIR__"huayuan",
  "south":__DIR__"nandajie2",
   ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

