//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"古墓前厅"NOR);
        set("long", @LONG

这是入墓的第一间石室，四壁俱是坚硬的岩石，古墓
内光线十分阴暗，寒气更为逼人，和室外有天壤之别
让你瑟瑟发抖,左边通往冥思室，往右则是打坐室。


LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/bei" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mingsi.c",
  "east" : __DIR__"dazuo.c",
  "north" : __DIR__"zhongting.c",
  "south" : __DIR__"yongdao4.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


