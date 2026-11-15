// Room: practice
// Date: Feb.14 1998 by Java

#include <room.h>
inherit ROOM;

void create()
{
      set("short", "武馆操练房");
      set("long", @LONG
这里摆满了石锁簸箕、大刀长剑、沙袋绑腿等，还有几个精心制
造的木人，是武馆弟子日常练功的地方。
LONG );

      set("exits", ([ /* sizeof() == 1 */
	  "down"   : __DIR__"wuguan",
      ]));

      set("objects", ([
	  "/clone/npc/tong-ren" : 4,
      ]));

      setup();
      //replace_program(ROOM);
}
