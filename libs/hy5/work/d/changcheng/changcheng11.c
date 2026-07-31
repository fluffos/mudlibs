// Room: /d/wizhome/incahome/changcheng11.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short",WHT "长城");
        set("long", WHT@LONG
这里就是举世闻名的--长城。站在长城上你可以看到四周群山环绕，山上
的灌木丛已经不象东边的那么多了，树也被砍了不少，很多地方已经露出了一
片片的黄土，你举目望去你脚下的长城顺着山顶象一条巨龙般蜿蜒的向北，向
南延伸出去。向北望去，人烟稀少，让你感到一片荒凉。
LONG
 NOR       );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"      :__DIR__"changcheng12.c",
                "east"      :__DIR__"changcheng10.c",
        ]));

        setup();
        replace_program(ROOM);
}
