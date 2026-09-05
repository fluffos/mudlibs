//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "渭汾流域");
        set("long", @LONG
    汾河和渭河汇入黄河，增大了其水势，也带来了更多的泥
沙。这里河东是晋，河西是陕。
LONG
        );
        set("no_task",1);
        set("exits", ([
                "southeast" : __DIR__"huanghehean",
                "north" : __DIR__"huanghe",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
