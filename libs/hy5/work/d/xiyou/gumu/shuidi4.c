//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"寒潭深处"NOR);
        set("long", @LONG

这里的水温不再那么冷，你隐隐约约看到前面有微微
的亮光，急急忙忙向那亮光处跑去......

LONG
        );

//  set("objects", ([ /* sizeof() == 2 */
//  "d/gumu/npc/daji" : 1,
//]));

        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xuanyuan.c",
  "east" : __DIR__"shuidi3.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

