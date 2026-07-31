//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"轩辕魔宫"NOR);
        set("long", @LONG
这里是轩辕魔宫的正殿，到处散发着一股妖气
正中端坐一人，正是开天创世的轩辕大帝。


LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xuanyuan" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"xuanyuan2.c",
//  "east" : __DIR__"xuanyuan3.c",
  "south" : __DIR__"xuanyuan.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

