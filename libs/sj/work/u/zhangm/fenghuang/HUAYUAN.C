#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","花园");
        set("long",@LONG
这里种着凤凰星特有的凤翎尾等奇花异草，宗主爱花胜于爱人，请
了全凤凰行最好的花匠来护理这些花草，使人一进来就感到心情
舒畅。
LONG);
        set("objects", ([
//           __DIR__"obj/hua1": 2,
//           __DIR__"obj/hua2": 2,
        ]));
        set("outdoors", "fenghuang");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"xiuxishi",
            "north"  : __DIR__"shuitan",
            "east"  : __DIR__"qianyuan",
        ]));
        setup();
        replace_program(ROOM);
}


