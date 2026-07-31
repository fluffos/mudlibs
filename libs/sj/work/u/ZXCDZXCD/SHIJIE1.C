#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "石阶");
    set("long", @LONG
这是一条长满青苔的石阶,四周有嶙峋突起的怪石,有的象狂龙
乱舞,有的似仙猴摘桃,怪异非常.石阶的两边还站着二名神气
无比的狼卫士.
LONG );

    set("exits", ([
     "northdown" : __DIR__"wangshougu",
        "southup" : __DIR__"shijie2",
        "east" : __DIR__"shandao1",
    ]));
 set("objects", ([   "/kungfu/class/shouzu/weishi": 2,        ]));
    setup();
    replace_program(ROOM); 
}
