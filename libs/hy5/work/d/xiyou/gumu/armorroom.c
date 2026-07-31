//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"护甲房"NOR);
        set("long", @LONG

这里存放者很多盔甲，如果有需要就拿吧。


LONG
        );

  set("objects", ([ /* sizeof() == 4 */
  "d/obj/armor/gujia.c" : 1,
  "d/obj/cloth/baipao.c" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"zhongting.c",
  "east" : __DIR__"zhongting.c",
//  "south" : "/d/dntg/sky/lingxiao",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

