// Room: /d/wizhome/incahome/changcheng19.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "长城");
        set("long", WHT @LONG
你唱着，唱着，忽然迎面刮来一阵大风，吹的你满头，满脸，满嘴的
沙子。你的急忙闭上了嘴，兴致一下全没了。你看了一下周围，只见四周
已经很少看到植物，到处是黄沙，使人感到一片荒凉。
LONG
 NOR       );

        set("outdoors", "changcheng");

        set("exits", ([
                "southwest" :__DIR__"changcheng20.c",
                "northeast"   :__DIR__"changcheng18.c",
        ]));

        setup();
        replace_program(ROOM);
}
