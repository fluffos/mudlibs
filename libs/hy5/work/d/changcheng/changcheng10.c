// Room: /d/wizhome/incahome/changcheng10.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT"长城");
        set("long", WHT@LONG
这里就是举世闻名的--长城。站在长城上你可以看到四周群山环绕，山上
可以看见不少矮矮的灌木丛，但不少的树也被砍光了，很多地方已经露出了一
片片的黄土，你举目望去你脚下的长城顺着山顶象一条巨龙般蜿蜒的向北，向
南延伸出去。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"      :__DIR__"changcheng11.c",
                "southup"   :__DIR__"changcheng9.c",
        ]));

        setup();
        replace_program(ROOM);
}
