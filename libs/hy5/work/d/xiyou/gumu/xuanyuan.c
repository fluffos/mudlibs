//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"轩辕魔宫"NOR);
        set("long", @LONG
这里是在水下的一片平地上建造的宫殿，宫殿被一层
瘴气所包围着


LONG
        );



        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xuanyuan1.c",
  "south" : __DIR__"shuidi4.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

