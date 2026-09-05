//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "沙漠");
        set("long", @LONG
一望无际的大漠，满眼黄沙，疾风摧残着一切生命。
LONG
        );

        set("exits", ([
			"east" : __DIR__"44",
"south" : __DIR__"32",
"southeast" : __DIR__"43",

        ]));
        set("no_task",1);
        setup();
        replace_program(ROOM);
}


