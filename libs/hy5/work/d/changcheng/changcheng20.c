// Room: /d/wizhome/incahome/changcheng20.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "长城");
        set("long",WHT @LONG
由于长期受到风沙的侵蚀，不少城墙已经倒塌。墙角的黄沙中有许多
从城墙上掉下来的青砖。抬眼望去，只见城墙外是一望无边的黄沙，周围
安静极了，向一片死亡的世界，偶尔天上飞过一只苍鹰。远远的可以看见
西边有一座关卡。
LONG
   NOR     );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"      :__DIR__"changcheng21.c",
                "northeast" :__DIR__"changcheng19.c",
        ]));

        setup();
        replace_program(ROOM);
}
