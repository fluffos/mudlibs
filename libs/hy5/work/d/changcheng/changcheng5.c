// Room: /d/wizhome/incahome/changcheng5.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "长城");
        set("long", WHT @LONG
这里就是举世闻名的--长城。站在长城上你可以看到四周群山环绕，山上
可以看见不少矮矮的灌木丛，但有的地方已经露出了一片片的黄土地，你举目
望去你脚下的长城顺着山顶象一条巨龙般蜿蜒的向北，向南延伸出去。从这里
向东你隐隐约约可以看到东边似乎有一座很大的关卡。
LONG
     NOR   );

        set("outdoors", "changcheng");

        set("exits", ([
                "west" :__DIR__"changcheng6.c",
                "eastdown" :__DIR__"changcheng4.c",
        ]));

        setup();
        replace_program(ROOM);
}
