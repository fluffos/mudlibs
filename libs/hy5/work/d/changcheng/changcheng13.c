// Room: /d/wizhome/incahome/changcheng13.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "长城");
        set("long", WHT @LONG
这里就是举世闻名的--长城。站在长城上你可以看到山脉连绵起伏，山
上已经很少看到树和灌木丛了。山上大片的地方光秃秃的，很多地方已经露
出了大片的黄土，你脚下的长城蜿蜒的向北，向南延伸出去。站在这里，你
已经可以感到迎面过来的大风中带着不少沙子，而长城厚厚的城墙也被侵蚀
的七零八落，不远处的一段城墙已经倒塌。你只好向南绕过去。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "west"       :__DIR__"FengHuoTai2-1",
                "north"      :__DIR__"changcheng12",
        ]));

        setup();
        replace_program(ROOM);
}

