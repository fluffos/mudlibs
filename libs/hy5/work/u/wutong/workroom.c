#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",BLINK+HIR "梵天净土"NOR);
        set("long", HIY @LONG
超越了时间和空间，穿过了无尽的光明和黑暗，才能达到的世界......
在时间的起点和空间的终点之处，有一个无边的原野......
世间万物，只有被神选中的，才能去那个乐土......
那里没有饥饿，没有争斗，没有痛苦和悲哀......
那里是从世间一切痛苦和烦恼中解放出来的永久的净土......
那里叫做--梵天净土！！！
那里是......老子买的，一次性付款+全产权+国土证，你怕了吗？
LONG 
NOR );
        set("exits", ([ 
            "down" : "/d/city/guangchang",
            "biwu" : "/d/wizard/biwu",
]));

        set("valid_startroom",1);
        set("no_clean_up", 0);
        set("no_fight",1);
        set("chatroom",1);
        set("pingan",1);
        set("no_fight",1);
        set("chatroom",1);
        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}

