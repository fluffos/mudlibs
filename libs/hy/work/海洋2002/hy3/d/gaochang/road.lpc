// road.c

inherit ROOM;
#include <ansi.h>;

void create ()
{
  set ("short", "阴深小路");
  set ("long",
"注意：由此处向北！将进入高昌迷宫地域，不知走法和没有作好准备
的玩家请考虑清楚是否还要向北行。
              
                    "HIR"高   昌   迷   宫\n\n\n"NOR

);

  set("outdoors", "gaochang");
  set("no_npc", 1);
   set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin1",
  "south" : "/d/xingxiu/silk2",
]));

  setup();
  replace_program(ROOM);
}
