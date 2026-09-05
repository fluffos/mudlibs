//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "黄河");
        set("long", @LONG
    黄河沿蒙古高原南边向东流淌，遇太行山脉的阻拦，便转头南下，
形成晋陕的分界。西北北方向好象有个渡口。
LONG
        );
        set("no_task",1);
        set("exits", ([
                "south" : __DIR__"weifen",
                "northwest" : __DIR__"dukou",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
