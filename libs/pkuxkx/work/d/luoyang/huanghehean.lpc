//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "黄河岸边");
        set("long", @LONG
这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色的河水
在河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。
LONG
        );
        set("no_task",1);
        set("exits", ([
                "east" : __DIR__"huanghehean2",
                "northwest" : __DIR__"weifen",
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
