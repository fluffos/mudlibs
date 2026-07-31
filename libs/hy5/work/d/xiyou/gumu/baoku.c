//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"古墓宝库"NOR);
        set("long", @LONG

这是一间不大的石室，四壁俱是坚硬的岩石，这里
陈设很简单，一张供桌，一个蒲团。供桌上放着四
样物品。
LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/yuyi" : 1,
  __DIR__"obj/yuxiao" : 1,
  __DIR__"obj/zixue-blade" : 1,
  __DIR__"obj/mojian" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"mishi.c",

]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

