
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石洞");
  set ("long", @LONG
这里是一个在半山腰天然形成的石洞，里面有着一张石床，一张石
桌，不过并没有椅子。地上有一些白骨和动物的尸体，看来房屋的主人
多半是遭遇不测了。
LONG);

  set("exits", ([ 

  "north":__DIR__"conglin",
    ]));
  set("objects",([
      __DIR__"npc/xiong":1,
      ]));
  set("valid_startroom", 1);
  setup();
 
}

	