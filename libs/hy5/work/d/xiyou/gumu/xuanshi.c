//轩辕古墓
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"天阴玄石殿"NOR);
        set("long", @LONG

大殿里上都是五彩冰冷的石头，每一块都透射出阴气，一张
黑玄石雕成的贵妃椅放在靠南的墙下，一个妖艳的女子半卧
在石椅上，浑身散发着妖媚的气息......

LONG
        );

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wang" : 1,
]));

        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"sleeproom.c",
  "northeast" : __DIR__"beiji.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


