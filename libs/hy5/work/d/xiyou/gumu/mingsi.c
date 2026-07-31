//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"练功房"NOR);
        set("long", @LONG

在这里可以练习武功，也可以冥思打座


LONG
        );

//  set("objects", ([ /* sizeof() == 4 */
//  "d/obj/armor/gujia.c" : 1,
//  "d/obj/cloth/baipao.c" : 1,
//]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"zhongting.c",
  "east" : __DIR__"qianting.c",
//  "south" : "/d/dntg/sky/lingxiao",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

