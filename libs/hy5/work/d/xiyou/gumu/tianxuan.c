//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
       set("short", "天璇");
        set("long", @LONG

天罡北斗倒数第六颗星命名的小房间，这里什么都没有
前面一片迷离，什么也看不清楚，四周一片寂静......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"huo.c",
  "south" : __DIR__"yongdao3.c",
  "west" : __DIR__"tianshu.c",
  "east" : __DIR__"mu.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

