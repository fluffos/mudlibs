//kantai 看台

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIW"西看台"NOR);
        set("long", @LONG
这里是试剑山庄的看台，山庄内的各大高手，正在里面切磋武艺，热闹非
凡，这里人声鼎沸，热闹无比。
LONG
        );
        set("exits", ([        
        "out" : __DIR__"zongtai",
        ]));
        
        set("no_fight", "1");
        set("no_sleep_room", 1);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"obj/sxj2" : 1,
        ]));
     
        setup();
}

