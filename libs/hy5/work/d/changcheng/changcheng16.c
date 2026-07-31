// Room: /d/wizhome/incahome/changcheng16.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT"长城");
        set("long", WHT@LONG
由于长期受到风沙的侵蚀，一小段城墙已经倒塌。你只好暂时从旁边的
小路绕过去。从这里你可以看到，虽然有的地方已经倒塌，但整条长城依然
雄伟的屹立在山顶，并向两边延伸出去。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "northup"   :__DIR__"changcheng17.c",
                "southeast" :__DIR__"changcheng15.c",
        ]));

        setup();
        replace_program(ROOM);
}
