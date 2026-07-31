//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"天权"NOR);
        set("long", @LONG

天罡北斗倒数第四颗星命名的小房间，这里什么都没有
前面一片迷离，什么也看不清楚，四周一片寂静......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yongdao2.c",
  "south" : __DIR__"yuheng.c",
  "east" : __DIR__"shui.c",
  "west" : __DIR__"huo.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

