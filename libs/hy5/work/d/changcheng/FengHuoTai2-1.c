// Room: /d/changcheng/FengHuoTai2-1
// Date: inca 98/08/30

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",HIY "峰火台");
        set("long", WHT @LONG
这里是烽火台的内部，这里不是很亮，四周乱糟糟的放着一些杂物，但
靠墙的兵器架上的兵器却擦的亮光闪闪，可见虽然生活很艰苦，但将士们却
没有忘记自己的责任。
LONG
 NOR       );

        set("exits", ([
                "up"       :__DIR__"FengHuoTai2-2",
                "east"     :__DIR__"changcheng13",
                "northwest":__DIR__"changcheng14",
        ]));

        setup();

}

