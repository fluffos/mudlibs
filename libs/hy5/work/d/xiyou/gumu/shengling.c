//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"圣灵殿"NOR);
        set("long", @LONG

这里就是女娲娘娘的圣殿。

LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/nuwa1" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"xuanyuan2.c",
//  "east" : __DIR__"xuanyuan3.c",
//  "south" : "/d/dntg/sky/lingxiao",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

