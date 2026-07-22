#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"接 天 楼"NOR);
        set("long", @TEXT
这是接天楼的第七层，处于此处，真有伸手即可摘下星辰的感觉，你的灵觉
不住地扩大，直至象要和天地融为一体。
TEXT
        );

        set("exits", ([ /* sizeof() == 2 */
          "up" : __DIR__"lou8",
          "down": __DIR__"lou6",
        ]));
        set("no_fly1", "1");

        set("objects", ([
                        __DIR__"npc/wangbashuai" : 1,
                ])
        );

        setup();
}

