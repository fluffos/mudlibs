// emei 洞口

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这里是峭壁上的山洞，里面黑乎乎的，一个老人满头白发，正在里面打坐。
LONG
        );
        set("objects",([
		CLASS_D("emei") + "/guhongzi" : 1,
        ]));
        set("exits", ([
                "out" : __DIR__"houshandk",
                "eastdown": __DIR__"qingyinge",
        ]));

        setup();
}

