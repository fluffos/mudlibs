// sanjie langerdian1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "浪儿店");
  set ("long", @LONG
	
一家小店，提供了基本的服务。店里只有一个老人家打理，
不过还是停干净的，有回到家的感觉。
LONG);

  set("exits", ([
  "west" : __DIR__"sanjiedao",
]));
  set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/guanjia": 1 ]) );

  setup();
  replace_program(ROOM);

}
